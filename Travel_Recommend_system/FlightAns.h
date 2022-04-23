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
    int ticketPrice;//总票價
    string agency;//代理人
public:
    //获取信息
    vector<Flight> Return_flight();
    int Return_ticketPrice();
    string Return_agency();
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
