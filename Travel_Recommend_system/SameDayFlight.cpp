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

//返回航班信息
vector<Flight> SameDayFlight::Return_all_flight() {
    return sd_flight;
}
//返回当前总票价
int SameDayFlight::Return_totalPrice() {
    return totalPrice;
}