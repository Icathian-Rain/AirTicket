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
    char seatY;         //经济舱

public:
    //余座信息
    inline string Return_carrier(){ return carrier;};
    inline string Return_flightNo(){ return flightNo;};
    inline string Return_sCity(){ return sCity;};
    inline string Return_dCity(){ return dCity;};
    inline char Return_seatF(){ return seatF;};
    inline char Return_seatC(){ return seatC;};
    inline char Return_seatY(){ return seatY;};
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
