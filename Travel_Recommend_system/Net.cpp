//
// Created by sszg on 22-4-20.
//

#include "Net.h"


//extern PriceRuleTable *PRT;
//extern PriceTable *PT;
//extern RemainSeatTable *RST;

vector<string> mysplit(string str, string separator) {//split string str by separator，like split “a+b+c” by "+" into "a""b""c"
    vector<string> result;
    int cutAt;
    while( (cutAt = str.find_first_of(separator)) != str.npos ){
        if(cutAt > 0)
        {
            result.push_back(str.substr(0, cutAt));
        }
        str = str.substr(cutAt + 1);
    }
    if(str.length() > 0){
        result.push_back(str);
    }
    return result;
}

/*void Net::initSet_and_Table() {
    SET = new FlightSet;
    PT = new PriceTable;
    PRT = new PriceRuleTable;
    RST = new RemainSeatTable;
    vector<string> cityName={"北京","上海","广州","深圳","香港","澳门","沈阳","青岛","济南","武汉","厦门","西安","长沙","南京","杭州","重庆","成都","昆明","贵阳","三亚","海口","乌鲁木齐","西宁","兰州","银川","拉萨"};
    //SET init
    SET->initSet(cityName, "20220503000000", 10);
    FILE *fp1=fopen("../flight.txt","r");
    FILE *fp2=fopen("../price.txt","r");
    if(fp1==NULL||fp2==NULL){
        cout<<"flight error!";
       // return -1;
    }
    SET->createSet(fp1,fp2);

    //PT init
    FILE *fp3=fopen("../price.txt","r");
    if(fp3==NULL){
        cout<<"price error!";
       // return -1;
    }
    cout<<"start gathering price....."<<endl;
    PT->createTable(fp3);
//    pt.showCityIndex();
    cout<<"gather finishing!"<<endl<<endl;

    //PRT init
    FILE *fp4=fopen("../priceRule.txt","r");
    if(fp4==NULL){
        cout<<"priceRule error!";
      //  return -1;
    }
    cout<<"start gathering price rules....."<<endl;
    PRT->createTable(fp4);
    cout<<"gather finishing!"<<endl<<endl;

    //RST init
    RST->CreatRemainSeatTable("../seats.txt");
    PT->findPrice("FM","KHG","DNH");
    PT->findPrice("JZ","WDF","FEG");
    PT->findPrice("CA","WDF","FEG");
    PRT->findAgency("FM","KHG","DNH");
    PRT->findSurcharge("FM","KHG","DNH");
    PRT->findAgency("JZ","WDF","FEG");
    PRT->findAgency("CA","WDF","FEG");
}
*/
bool Net::Set_flightSeats(RemainingSeat st) {
    int index_of_sCity = FindIndex(city[st.Return_sCity()]);
    int index_of_dCity = FindIndex(city[st.Return_dCity()]);
    for(int i = 0; i < matrix[index_of_sCity][index_of_dCity].size(); i++){
        if(matrix[index_of_sCity][index_of_dCity][i].flightNoVal() == st.Return_flightNo()){
            bool ok = matrix[index_of_sCity][index_of_dCity][i].SetSeats(st.Return_seatF(),st.Return_seatC(),st.Return_seatY());
            if(!ok) cout<<"error!"<<endl;
            return true;
        }
    }
    cout<<"flignt not found!"<<endl;
    return false;
}

vector<Flight> Net::request(FlightRequest req, string target_agency){
    vector<Flight> res;             //result
    string sCity = req.Return_sCity();
    string dCity = req.Return_dCity();
    int N = req.Return_passengerNUm();      //旅客人数
    //string target_agency = req.Return_agency()[0];  //该功能指定一个代理人
    int s = FindIndex(sCity);
    int d = FindIndex(dCity);   //定位
    for(int i =0; i < matrix[s][d].size(); i++){
        Flight tmp_flightA = matrix[s][d][i];
//        string A_carrier = tmp_flightA.carrierVal();
//        //agency
//        vector<string> agc = PRT->findAgency(A_carrier, sCity, dCity);      //从PTR中找到允许的代理人
//        bool ok = false;
//        for(int j = 0; j < agc.size(); j++){
//            if(agc[j] == target_agency) {
//                ok = true;
//                break;
//            }
//        }
//        if(!ok) continue;
//        //RemainingSeat
//        Time A_time = tmp_flightA.takeOffTimeVal();
//        string A_number = tmp_flightA.flightNoVal();
//        char*A_Seat = RST->getSeat(A_time,A_number).Return_seat();     //获取余座信息
//        if( A_Seat[0] + A_Seat[1] + A_Seat[2] < N) continue;        //check Seats is enough or not
//
//        //Price
//        int *A_Price = PT->findPrice(A_carrier,sCity,dCity);
//        tmp_flightA.SetSeats(A_Seat[0],A_Seat[1],A_Seat[2]);    //设置余座，可供查看
//        //为每个旅客分配尽可能价格低的仓位
//        int ticketPrice = 0;
//        char passenger_seatList[8] = {0,0,0,0,0,0,0,0};
//        for(int i = 0; i < N; i++){
//            if(i+1 <= A_Seat[2]) {
//                passenger_seatList[i] = 'Y';
//                ticketPrice += A_Price[2];
//            }
//            else if(i+1 <= A_Seat[1]+ A_Seat[2]) {
//                passenger_seatList[i] = 'C';
//                ticketPrice += A_Price[1];
//            }
//            else {
//                passenger_seatList[i] = 'F';
//                ticketPrice += A_Price[0];
//            }
//        }
//        tmp_flightA.SetPrice(ticketPrice);
//        tmp_flightA.Set_passenger_seatList(passenger_seatList);
//        tmp_flightA.Set_agc(target_agency);
        //满足,存入res
        res.push_back(tmp_flightA);
    }
    //sort(res.begin(),res.end(),Flight::comparePrice);       //按照票价升序排序
    return res;
}


void Net::update(){

}
