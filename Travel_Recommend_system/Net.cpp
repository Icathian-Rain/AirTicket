//
// Created by sszg on 22-4-20.
//

#include "Net.h"


extern PriceRuleTable *PRT;
extern PriceTable *PT;
extern RemainSeatTable *RST;

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

    for(int i =0; i < matrix[s][d].size(); i++){
        Flight tmp_flightA = matrix[s][d][i];       //对象拷贝，不会对原数据造成修改
        string A_carrier = tmp_flightA.carrierVal();
        Time A_time = tmp_flightA.takeOffTimeVal();
        Time A_time2 = tmp_flightA.arrivalTimeVal();
        string A_number = tmp_flightA.flightNoVal();
        if(sCity != tmp_flightA.sCityVal()) continue;
        if(dCity != tmp_flightA.dCityVal()) continue;
        AnsElement ele(A_carrier,A_number,A_time,A_time2,sCity,dCity);

        //agency
        vector<string> agc = PRT->findAgency(A_carrier, sCity, dCity);      //从PTR中找到允许的代理人
        vector<string> common_agc;
        for(int j = 0; j < agc.size(); j++){
            for(int k = 0; k < target_agency.size(); k++){
                if(agc[j] == target_agency[k]) {
                    common_agc.push_back(agc[j]);
                    break;
                }
            }
        }
        if(common_agc.empty()) continue;
        //RemainingSeat
        string date = A_time.time2string_forday();
        //暂时用这个方法，之后改成袁的做法
        vector<char> A_Seat = RST->getSeat(date,A_number).Return_seat();     //获取余座信息
        if( A_Seat[0] + A_Seat[1] + A_Seat[2] < N) continue;        //check Seats is enough or not

        //Price
        int *A_Price = PT->findPrice(A_carrier,sCity,dCity);
        ele.SetSeats(A_Seat[0],A_Seat[1],A_Seat[2]);    //设置余座，可供查看
        //为每个旅客分配尽可能价格低的仓位
        int ticketPrice = 0;
        char passenger_seatList[8] = {0,0,0,0,0,0,0,0};
        for(int i = 0; i < N; i++){
            if(i+1 <= A_Seat[2]) {
                passenger_seatList[i] = 'Y';
                ticketPrice += A_Price[2];
            }
            else if(i+1 <= A_Seat[1]+ A_Seat[2]) {
                passenger_seatList[i] = 'C';
                ticketPrice += A_Price[1];
            }
            else {
                passenger_seatList[i] = 'F';
                ticketPrice += A_Price[0];
            }
        }
        ele.SetPrice(ticketPrice);
        ele.Set_passenger_seatList(passenger_seatList);
        ele.Set_agc(common_agc);
        //满足,存入res
        res.push_back(ele);
    }
    //sort(res.begin(),res.end(),Flight::comparePrice);       //按照票价升序排序
    return res;
}


void Net::update(){

}
