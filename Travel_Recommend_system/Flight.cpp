//
// Created by sszg on 22-4-20.
//

#include "Flight.h"

//航班信息
string Flight::carrierVal() {
    return carrier;
}

string Flight::flightNoVal() {
    return flightNo;
}

string Flight::sCityVal() {
    return sCity;
}

string Flight::dCityVal() {
    return dCity;
}

Time Flight::takeOffTimeVal() {
    return takeOffTime;
}

Time Flight::arrivalTimeVal() {
    return arrivalTime;
}
