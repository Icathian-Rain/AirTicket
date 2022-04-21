//
// Created by sszg on 22-4-20.
//

#include "FlightRequest.h"

//获取信息
Time FlightRequest::timeVal(){
    return time;
}

string FlightRequest::Return_sCity() {
    return sCity;
}

string FlightRequest::Return_dCity() {
    return dCity;
}

vector<string> FlightRequest::Return_agency() {
    return agency;
}

char FlightRequest::Return_maxAnsNUm(){
    return maxAnsNUm;
}

char FlightRequest::Return_passengerNUm() {
    return passengerNum;
}
