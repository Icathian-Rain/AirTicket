//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#include "Flight.h"
#include <string>
using namespace std;
class FlightAns {
private:
    Flight flight;//航班信息
    int ticketPrice;//票價
    string agency;//代理人
public:
    //获取信息
    Flight Return_flight();
    int Return_ticketPrice();
    string Return_agency();
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
