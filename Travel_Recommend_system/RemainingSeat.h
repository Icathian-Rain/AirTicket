//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#define TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
#include <string>
#include <vector>
#include "Time.h"
#include <time.h>

#include <atomic>   //定义原子操作
using namespace std;

class RemainingSeat {       //航班余座信息
private:
    string carrier;
    string flightNo;
    //string sCity;
    //string dCity;
    Time depatureDate{};
    //Time arrivalDate{};
    atomic_char seatF;
    atomic_char seatC;
    atomic_char seatY;
//    char seatF;         //头等舱座位数量，0:无座，9:9坐，A：10座以上
//    char seatC;         //商务舱
//    char seatY;         //经济舱

public:
//    RemainingSeat();
    RemainingSeat(const RemainingSeat & rst);           //自定义拷贝构造函数
    RemainingSeat(vector<string> record);
    //余座信息
//    inline char Return_seatF() const{ return seatF;};
//    inline char Return_seatC() const{ return seatC;};
//    inline char Return_seatY() const{ return seatY;};
    inline vector<char> Return_seat(){
        char F = seatF.load(memory_order_relaxed);          //原子操作
        char C = seatC.load(memory_order_relaxed);
        char Y = seatY.load(memory_order_relaxed);
        vector<char> allseat = {F,C,Y};
        return allseat;
    };
    inline void setSeats(char F, char C, char Y) {
//        seatF = F;
//        seatC = C;
//        seatY = Y;
        seatF.store(F,memory_order_relaxed);
        seatC.store(C,memory_order_relaxed);
        seatY.store(Y,memory_order_relaxed);
        return;
    };
    inline void updateSeats(){//update the number of the remaining seats
        int num1 = rand()%20;
        int num2 = rand()%20;
        int num3 = rand()%20;
        seatC.store(changeseats(num1),memory_order_relaxed);
        seatF.store(changeseats(num2),memory_order_relaxed);
        seatY.store(changeseats(num3),memory_order_relaxed);
    };
    static inline char changeseats(int num){
        if(num>=10){
            return 'A';
        }
        return (char)(num+'0');
    };
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAININGSEAT_H
