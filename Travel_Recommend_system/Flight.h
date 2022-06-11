//航班信息
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#include <string>
#include "Time.h"
using namespace std;
class Flight{//一個航班信息
protected:
    string carrier;        //承运人
    string flightNo;       //航班号
    Time takeOffTime;      //起飞时间
    Time arrivalTime;      //抵达时间
    string sCity;          //起飞城市
    string dCity;          //抵达城市
//    //根据req搜索后确定，赋值于NET.cpp request，通过拷贝实现，不会对FlightSet SET造成影响
//    char seatF;         //头等舱座位数量，0:无座，9:9坐，A：10座以上
//    char seatC;         //商务舱
//    char seatY;         //经济舱
//    int price = 0;              //票价，在搜索时确定，同时用于排序
//    char passenger_seatList[8] = {0,0,0,0,0,0,0,0};          //记录乘客座位表，即为每个乘客所在的仓位，值分别为F,C,Y，以0填充
//    string agc;                 //代理人

public:
    Flight();
    Flight(string carr, string fN, Time tTime, Time aTime, string sC, string dC) {
        if(carr.size()!=2 || fN.size()!= 4 || sC.size()!= 3 || dC.size() != 3){
            cout<<"wrong flight pattern!";
        }
        carrier = carr;
        flightNo = fN;
        takeOffTime = tTime;
        arrivalTime = aTime;
        sCity = sC;
        dCity = dC;
    };

    //获取航班信息,inline内联函数，提升效率，适用于代码量小(<10行)并且频繁使用的函数
    inline string carrierVal(){ return carrier;};
    inline string flightNoVal(){ return flightNo;};
    inline string sCityVal(){ return sCity;};
    inline string dCityVal(){ return dCity;};
    inline Time takeOffTimeVal(){ return takeOffTime;};
    inline Time arrivalTimeVal(){ return  arrivalTime;};
//    inline int Return_price(){ return price;};         //返回票价
//    static bool comparePrice(const Flight &f1, const Flight &f2){       //自定义比较函数、用于sort、set
//        return f1.price < f2.price;
//    }
//    inline void createFlight(string carr,string flightN,Time tTime,Time aTime,string sCi,string dCi){
//        if(carr.size()!=2 || flightN.size()!= 4 || sCi.size()!= 3 || dCi.size() != 3){
//            cout<<"wrong flight pattern!";
//            return;
//        }
//        carrier=carr;
//        flightNo=flightN;
//        takeOffTime=tTime;
//        arrivalTime=aTime;
//        sCity=sCi;
//        dCity=dCi;
////        price=pri;
//    };
    inline void showFlight(){
        cout<<"航班号："<<flightNo<<endl;
//        cout<<"agc:"<<agc<<endl;
        cout << "起飞时间：";
        takeOffTime.showTime();
        cout<<"抵达时间：";
        arrivalTime.showTime();
        cout<<"起飞城市："<<sCity<<endl;
        cout<<"抵达城市："<<dCity<<endl;
//        cout<<"余座信息："<<seatF<<';'<<seatC<<';'<<seatY<<';'<<endl;
//        cout<<"票价："<<price<<endl<<endl;
    };
    static bool compare_takeOffTime(const Flight &f1, const Flight &f2){       //按照起飞时间降序
        Time t1 = f1.takeOffTime;
        Time t2 = f2.takeOffTime;
        return Time::compare_Time(t1,t2);          //降序排序
    }

    //搜索设置
//    inline bool SetSeats(char F, char C, char Y){
//        seatF = F;
//        seatC = C;
//        seatY = Y;
//        return true;
//    };      //设置当前航班余座
//    inline bool SetPrice(int ticketPrice){
//        if(ticketPrice > 0) {
//            price = ticketPrice;
//            return true;
//        }
//        else return false;
//    }//票价
//    inline void Set_passenger_seatList(char a[8]){
//        for(int i = 0; i < 8; i++) passenger_seatList[i] = a[i];
//        return;
//    };//设置乘客座位表
//    inline void Set_agc(string agency){
//            agc = agency;
//    };  //设置代理人
};

#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
