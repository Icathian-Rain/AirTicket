//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTREQUEST_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTREQUEST_H
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
    char passengerNum;      //乘客數目
    char maxAnsNUm;         //最大請求結果數目
public:
    //获取信息
    Time timeVal();
    string Return_sCity();
    string Return_dCity();
    vector<string> Return_agency();
    char Return_passengerNUm();
    char Return_maxAnsNUm();
}; 
#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTREQUEST_H
