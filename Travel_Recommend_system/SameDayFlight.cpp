//
// Created by sszg on 22-4-24.
//

#include "SameDayFlight.h"

bool SameDayFlight::push_back(Flight f) {       //航班合并
    if(num >= limit_num) return false;  //超出限制
    num++;
    sd_flight.push_back(f);
    arriveTime = f.arrivalTimeVal();
    totalPrice += f.Return_price();
    return true;
}