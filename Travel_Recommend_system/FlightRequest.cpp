//
// Created by sszg on 22-4-20.
//

#include "FlightRequest.h"

FlightRequest::FlightRequest(Time t, string s, string d, vector<string> agc, char passnum, char maxansnum) {
    time = t;
    sCity = s;
    dCity = d;
    agency = agc;
    passengerNum = passnum;
    maxAnsNUm = maxansnum;
}
