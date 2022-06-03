//
// Created by sszg on 22-4-20.
//

#include "FlightAns.h"
//判断是否满足衔接条件
bool FlightAns::Connect_ok() {
    if(flight.size() <= 1) return true;
    else{
        bool flag = true;
        Time last = flight[0].arrivalTimeVal();
        for(int i = 1; i < flight.size(); i++){
            flag = Time::connect_ok(last,flight[i].takeOffTimeVal());
            if(flag) last = flight[i].arrivalTimeVal();
            else break;
        }
        return flag;
    }
}
