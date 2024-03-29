//
// Created by sszg on 22-4-20.
//

#include "Net.h"


extern PriceRuleTable *PRT;
extern PriceTable *PT;
extern RemainSeatTable *RST;
extern FluctuationTable *FT;
vector<string> mysplit(string str, const string& separator) {//split string str by separator，like split “a+b+c” by "+" into "a""b""c"
    vector<string> result;
    int cutAt;
    while( (cutAt = str.find_first_of(separator)) != std::string::npos ){
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

void Net::initNet(const vector<string>& cityName, Time t){
    vexnum=cityName.size();
    if(vexnum>CITYNUM)
        vexnum=CITYNUM;
    for(int i=0;i<vexnum;i++){
        vertex[cityName[i]]=i;
    }
    time=t;
    for (auto & i : matrix) {
        for (auto & j : i) {
            j = vector<Flight>();
        }
    }
}

void Net::addFlight(const string& sCity,const string& dCity,const string& flightNo,const string& carriers,Time tT,Time aT){//add one flight
    int sCityIndex = FindIndex(sCity);
    int dCityIndex = FindIndex(dCity);
    if(sCityIndex==-1||dCityIndex==-1||sCityIndex>CITYNUM||dCityIndex>CITYNUM){
        cout<<"FLight index out!"<<endl;
        return ;
    }
    Flight flight(carriers, flightNo, tT, aT, sCity, dCity);
    matrix[sCityIndex][dCityIndex].push_back(flight);
}

void Net::showNet() {
    for (int i = 0;i < vexnum;i++) {
        for (int j = 0;j < vexnum;j++) {
            if(!matrix[i][j].empty()){
                for (auto & k : matrix[i][j]) {
                    k.showFlight();
                }
            }
        }
    }
}

vector<AnsElement> Net::request(FlightRequest req){
    vector<AnsElement> res;             //result
    string sCity = req.Return_sCity();
    string dCity = req.Return_dCity();
    vector<string> target_agency = req.Return_agency();
    int N = req.Return_passengerNUm();      //旅客人数
    if( N <= 0 || N > 8) {
        cout<<"Passenger Number is error!"<<endl;
        return res;
    }
    //定位
    int s = FindIndex(sCity);
    int d = FindIndex(dCity);
    if( s < 0 || s >= CITYNUM) {
        cout<<"sCity not found!"<<endl;
        return res;
    }
    if( s < 0 || s >= CITYNUM) {
        cout<<"dCity not found!"<<endl;
        return res;
    }

    for(auto tmp_flightA : matrix[s][d]){
        //对象拷贝，不会对原数据造成修改
        string A_carrier = tmp_flightA.carrierVal();
        Time A_time = tmp_flightA.takeOffTimeVal();
        Time A_time2 = tmp_flightA.arrivalTimeVal();
        string A_number = tmp_flightA.flightNoVal();
        if(sCity != tmp_flightA.sCityVal()) continue;
        if(dCity != tmp_flightA.dCityVal()) continue;
        AnsElement ele(A_carrier,A_number,A_time,A_time2,sCity,dCity);

        //agency
        vector<string> agc = PRT->findAgency(A_carrier, sCity, dCity);      //从PTR中找到允许的代理人
        vector<string> common_agc;                                      //求代理人交集
        for(auto & j : agc){
            for(auto & k : target_agency){
                if(j == k) {
                    common_agc.push_back(j);
                    break;
                }
            }
        }
        if(common_agc.empty()) continue;
        //RemainingSeat
        string str_A_time = A_time.time2string_forday();                                  //起飞时间转为字符串
        string Number = A_carrier+A_number;         //carrier + flightNumber
        vector<char> A_Seat = RST->getSeat(str_A_time,Number);     //获取余座信息
        if( A_Seat[0] - '0' + A_Seat[1] - '0' + A_Seat[2] - '0' < N) continue;        //check Seats is enough or not

        //surcharge
        int surcharge = PRT->findSurcharge(A_carrier, sCity, dCity);
        if(surcharge < 0) continue;

        //Price
        int *A_Price = PT->findPrice(A_carrier,sCity,dCity);
        int Price[3];
        Price[0] = (A_Price[0]*(100+surcharge))/100;
        Price[0] -= Price[0]%10;
        Price[1] = (A_Price[1]*(100+surcharge))/100;
        Price[1] -= Price[1]%10;
        Price[2] = (A_Price[2]*(100+surcharge))/100;
        Price[2] -= Price[2]%10;
        if(!ele.SetSeats(A_Seat[0],A_Seat[1],A_Seat[2])) continue;    //设置余座，可供查看
        //为每个旅客分配尽可能价格低的仓位
        int ticketPrice = 0;
        char passenger_seatList[8] = {0,0,0,0,0,0,0,0};
        for(int i = 0; i < N; i++){
            if(i+1 <= A_Seat[2] - '0') {
                passenger_seatList[i] = 'Y';
                ticketPrice += Price[2];
            }
            else if(i+1 <= A_Seat[1] - '0'+ A_Seat[2] - '0') {
                passenger_seatList[i] = 'C';
                ticketPrice += Price[1];
            }
            else {
                passenger_seatList[i] = 'F';
                ticketPrice += Price[0];
            }
        }
        if(!ele.SetPrice(ticketPrice)) continue;
        ele.Set_passenger_seatList(passenger_seatList);

        //考虑不同代理人的票价波动
        vector<string> final_agc[3];        //最多分成3组
        for(auto & j:common_agc) {
            int p = FT->index_fluctuation(j);
            if(p < 3 && p >= 0) final_agc[p].push_back(j);
        }
        for(int j = 0; j < 3; j++) {
          if(!final_agc[j].empty()) {
              AnsElement final_ele = ele;       //copy一份ele，已经记录了余座、和乘客座位表
              int Extra_price = FT->find_fluctuation_price(j);
              if(Extra_price != 404) {
                  int final_price = ticketPrice + N * Extra_price;           //计算最终总票价
                  final_ele.SetPrice(final_price);      //设置最终总票价
                  final_ele.Set_agc(final_agc[j]);
                  res.push_back(final_ele);
              }
          }
        }
        //ele.Set_agc(common_agc);
        //满足,存入res
        //res.push_back(ele);
    }
    return res;
}

