//
// Created by sszg on 22-4-20.
//

#include "PriceRule.h"
//获取信息
vector<string> PriceRule::Return_agency() {
    return agency;
}

string PriceRule::Return_sCity() {
    return sCity;
}

string PriceRule::Return_dCity() {
    return dCity;
}

string PriceRule::Return_carrier() {
    return carrier;
}

string PriceRule::Return_nextCarrier() {
    return nextCarrier;
}

int PriceRule::Return_sequenceNo() {
    return sequenceNo;
}

char PriceRule::Return_surcharge() {
    return surcharge;
}