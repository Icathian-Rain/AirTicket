//
// Created by sszg on 22-4-24.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_SAMEDAYFLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_SAMEDAYFLIGHT_H
#include "Flight.h"
using namespace  std;

class SameDayFlight {       //记录同一天的航班请求
private:
    int num = 0;            //航段数目
    int limit_num = 3;      //限定同一天最多3段航班,注意在前端中实现
    vector<Flight> sd_flight;
    int totalPrice = 0;
public:
    Time arriveTime;    //记录抵达时间
    bool push_back(Flight f);       //航班合并，同时更新num、limit_num、sd_flight、totalPrice、arriveTime
    static bool comparePrice(const SameDayFlight &f1, const SameDayFlight &f2){       //自定义比较函数、用于sort、set
        return f1.totalPrice < f2.totalPrice;
    }
};


#endif //TRAVEL_RECOMMEND_SYSTEM_SAMEDAYFLIGHT_H
