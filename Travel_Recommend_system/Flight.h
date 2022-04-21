//航班信息
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#include <string>
#include "Time.h"
using namespace std;
class Flight{
private:
    string carrier;        //承运人
    string flightNo;       //航班号
    Time takeOffTime;           //起飞时间
    Time arrivalTime;           //抵达时间
    string sCity;          //起飞城市
    string dCity;          //抵达城市

public:
    //获取航班信息
    string Return_carrier();
    string Return_flightNo();
    string Return_sCity();
    string Return_dCity();
    Time Return_takeOffTime();
    Time Return_arrivalTime();



};

#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
