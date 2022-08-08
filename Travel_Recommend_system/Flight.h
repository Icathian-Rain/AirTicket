//航班信息
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#include <string>
#include "Time.h"
using namespace std;
class Flight{//一個航班信息
protected:
    string carrier;        //承运人
    string flightNo;       //航班号
    Time takeOffTime{};      //起飞时间
    Time arrivalTime{};      //抵达时间
    string sCity;          //起飞城市
    string dCity;          //抵达城市

public:
    Flight();
    Flight(const string& carr, const string& fN, Time tTime, Time aTime, const string& sC, const string& dC) {
        if(carr.size()!=2 || fN.size()!= 4 || sC.size()!= 3 || dC.size() != 3){
            cout<<"wrong flight pattern!";
        }
        carrier = carr;
        flightNo = fN;
        takeOffTime = tTime;
        arrivalTime = aTime;
        sCity = sC;
        dCity = dC;
    };

    //获取航班信息,inline内联函数，提升效率，适用于代码量小(<10行)并且频繁使用的函数
    inline string carrierVal(){ return carrier;};
    inline string flightNoVal(){ return flightNo;};
    inline string sCityVal(){ return sCity;};
    inline string dCityVal(){ return dCity;};
    inline Time takeOffTimeVal(){ return takeOffTime;};
    inline Time arrivalTimeVal(){ return  arrivalTime;};
    inline void showFlight(){
        cout<<"航班号："<<flightNo<<" ";
    };
};

#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
