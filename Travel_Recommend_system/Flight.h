//航班信息
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#include <string>
#include "Time.h"
#include "PriceRule.h"
using namespace std;
class Flight{//一個航班信息
private:
    string carrier;        //承运人
    string flightNo;       //航班号
    Time takeOffTime;      //起飞时间
    Time arrivalTime;      //抵达时间
    string sCity;          //起飞城市
    string dCity;          //抵达城市
    int Price;              //票价，目前还没有使用运价这一数据，暂用Price替代

public:
    //获取航班信息
    string carrierVal();
    string flightNoVal();
    string sCityVal();
    string dCityVal();
    Time takeOffTimeVal();
    Time arrivalTimeVal();
    PriceRule rule;         //运价规则
    static bool comparePrice(const Flight &f1, const Flight &f2){       //自定义比较函数、用于sort、set
        return f1.Price < f2.Price;
    }



};

#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
