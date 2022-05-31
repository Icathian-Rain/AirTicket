//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#include "Flight.h"
#include <vector>
#include <string>
using namespace std;
class FlightAns {
private:
    vector<Flight> flight;//航班信息,可能是多个航班联程
    //Flight flight;
    int ticketPrice = 0;//总票價
    //搜索结果不需要代理人信息，用户已经指定了，可以考虑做一次验证操作，保证结果正确性
    bool status = true;         //真实or虚拟响应
public:
    //获取信息
    inline vector<Flight> Return_flight(){ return flight;};
    inline int Return_ticketPrice(){ return ticketPrice;};
    //string Return_agency();
    inline bool Return_status(){ return status;};       //返回状态


    static bool comparePrice(const FlightAns &a1, const FlightAns &a2){       //自定义比较函数、用于sort、set
        return a1.ticketPrice < a2.ticketPrice;
    }
    inline void Add(Flight sdf){
        flight.push_back(sdf);
        ticketPrice += sdf.Return_price();
    };                //添加航段到Ans当中,因为代码量小并且频繁使用，故改为内联函数inline
    void Virtual_FlightAns();                   //将该航班回应设置为虚拟回应，票价设置为最大值，用于低价行程推荐中初始化优先队列
    bool Connect_ok();                      //判断是否满足衔接条件
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
