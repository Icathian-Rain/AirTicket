//航班信息
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#include <string>
#include "Time.h"
using namespace std;
class Flight{//一個航班信息
private:
    string carrier;        //承运人
    string flightNo;       //航班号
    Time takeOffTime;      //起飞时间
    Time arrivalTime;      //抵达时间
    string sCity;          //起飞城市
    string dCity;          //抵达城市

public:
    //获取航班信息
    string carrierVal();
    string flightNoVal();
    string sCityVal();
    string dCityVal();
    Time takeOffTimeVal();
    Time arrivalTimeVal();



};

#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
