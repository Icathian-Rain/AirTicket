//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#define TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#include <string>
#include <vector>
#include "Time.h"
#include <time.h>
using namespace std;

class RemainingSeat {       //航班余座信息
private:
    string carrier;
    string flightNo;
    string sCity;
    string dCity;
    Time depatureDate{};
    Time arrivalDate{};
    char seatF;         //头等舱座位数量，0:无座，9:9坐，A：10座以上
    char seatC;         //商务舱
    char seatY;         //经济舱

public:
    RemainingSeat();
    RemainingSeat(vector<string> record);
    //余座信息
    inline char Return_seatF() const{ return seatF;};
    inline char Return_seatC() const{ return seatC;};
    inline char Return_seatY() const{ return seatY;};
    inline vector<char> Return_seat(){
        vector<char> allseat = {seatF,seatC,seatY};
        return allseat;
    };
    inline void updateSeats(){//update the number of the remaining seats
        int num1 = rand()%20;
        int num2 = rand()%20;
        int num3 = rand()%20;
        seatC = changeseats(num1);
        seatF = changeseats(num2);
        seatY = changeseats(num3);
    }
    static inline char changeseats(int num){
        if(num>=10){
            return 'A';
        }
        return (char)(num+'0');
    }
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
