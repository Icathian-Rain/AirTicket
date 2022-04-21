//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#define TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#include <string>
using namespace std;

class RemainingSeat {       //航班余座信息
private:
    string carrier;
    string flightNo;
    string sCity;
    string dCity;
    char seatF;         //头等舱座位数量，0:无座，9:9坐，A：10座以上
    char seatC;         //商务舱
    char seatY;         //经济cang

public:
    //余座信息
    string Return_carrier();
    string Return_flightNo();
    string Return_sCity();
    string Return_dCity();
    char Return_seatF();
    char Return_seatC();
    char Return_seatY();
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
