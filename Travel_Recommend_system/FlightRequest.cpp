//
// Created by sszg on 22-4-20.
//

#include "FlightRequest.h"

#include <utility>

FlightRequest::FlightRequest(Time t, string s, string d, vector<string> agc, char passnum, char maxansnum) {
    time = t;
    sCity = std::move(s);
    dCity = std::move(d);
    agency = std::move(agc);
    passengerNum = passnum;
    maxAnsNUm = maxansnum;
}
