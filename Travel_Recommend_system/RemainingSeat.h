//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#define TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#include <string>


class RemainingSeat {       //航班余座信息
private:
    std::string carrier;
    std::string flightNo;
    std::string sCity;
    std::string dCity;
    char seatF;         //头等舱座位数量，0:无座，9:9坐，A：10座以上
    char seatC;         //商务舱
    char seatY;         //经济舱
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
