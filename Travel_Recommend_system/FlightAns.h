//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#include "Flight.h"
#include "SameDayFlight.h"
#include <vector>
#include <string>
using namespace std;
class FlightAns {
private:
    vector<Flight> flight;//航班信息,可能是多个航班联程
    //Flight flight;
    int ticketPrice;//总票價
    string agency;//代理人
    bool status = true;         //真实or虚拟响应
public:
    //获取信息
    vector<Flight> Return_flight();
    int Return_ticketPrice();
    string Return_agency();
    bool Return_status();       //返回状态


    static bool comparePrice(const FlightAns &a1, const FlightAns &a2){       //自定义比较函数、用于sort、set
        return a1.ticketPrice < a2.ticketPrice;
    }
    void Add(SameDayFlight sdf);                //添加航段到Ans当中
    void Virtual_FlightAns();                   //将该航班回应设置为虚拟回应，票价设置为最大值，用于低价行程推荐中初始化优先队列
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
