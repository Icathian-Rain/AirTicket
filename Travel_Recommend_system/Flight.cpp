//
// Created by sszg on 22-4-20.
//

#include "Flight.h"

//航班信息
string Flight::Return_carrier() {
    return carrier;
}

string Flight::Return_flightNo() {
    return flightNo;
}

string Flight::Return_sCity() {
    return sCity;
}

string Flight::Return_dCity() {
    return dCity;
}

Time Flight::Return_takeOffTime() {
    return takeOffTime;
}

Time Flight::Return_arrivalTime() {
    return arrivalTime;
}
