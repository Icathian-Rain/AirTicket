//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGNTREQUEST_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGNTREQUEST_H
#include "Time.h"
#include <string>
#include <vector>
using namespace  std;
class FlightRequest {           //搜索请求
private:
    Time time;                  //日期
    string sCity;          //起止城市
    string dCity;
    vector<string> agency;        //代理人
    char passengerNum;
    char maxAnsNUm;
}; 
#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGNTREQUEST_H
