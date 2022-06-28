//
// Created by sszg on 22-6-9.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_ANSELEMENT_H
#define TRAVEL_RECOMMEND_SYSTEM_ANSELEMENT_H
#include "Flight.h"
#include <utility>
#include <vector>
using namespace std;
class AnsElement:public Flight{            //Flight->FlightAns的中间层
private:
    char seatF;         //头等舱座位数量，0:无座，9:9坐，A：10座以上
    char seatC;         //商务舱
    char seatY;         //经济舱
    int price = 0;              //票价，在搜索时确定，同时用于排序
    char passenger_seatList[8] = {0,0,0,0,0,0,0,0};          //记录乘客座位表，即为每个乘客所在的仓位，值分别为F,C,Y，以0填充
    vector<string> agc;

public:
    AnsElement();
    AnsElement(const string& carr, const string& fN, Time tTime, Time aTime, const string& sC, const string& dC) : Flight(carr, fN, tTime, aTime, sC, dC){};
    inline int Return_price() const{ return price;};         //返回票价
    inline vector<string> Return_agc(){ return agc;};
    inline string Return_flightNo(){ return flightNo;};
    inline string Return_takeOffTime() { return takeOffTime.time2string_forday();};
    inline string Return_arrivalTime() { return arrivalTime.time2string_forday();};
    inline string Return_sCity() { return sCity;};
    inline string Return_dCity() { return dCity;};
    inline char Return_seatF() const{ return seatF;};
    inline char Return_seatC() const{ return seatC;};
    inline char Return_seatY() const{ return seatY;};
    inline char* Return_passenger_seatList(){ return passenger_seatList;};

    static bool comparePrice(const AnsElement &f1, const AnsElement &f2){       //自定义比较函数、用于sort、set
        return f1.price < f2.price;
    }

    inline void showElement(){
        cout<<"航班号："<<flightNo<<" ";
////        cout<<"agc:"<<agc<<endl;
//        cout << "起飞时间：";
//        takeOffTime.showTime();
//        cout<<"抵达时间：";
//        arrivalTime.showTime();
//        cout<<"起飞城市："<<sCity<<endl;
//        cout<<"抵达城市："<<dCity<<endl;
//        cout<<"余座信息："<<seatF<<';'<<seatC<<';'<<seatY<<';'<<endl;
//        cout<<"旅客座位表："<<endl;
//        for(int i = 0; i < 8 && passenger_seatList[i]!= 0; i++) cout<<passenger_seatList[i]<<" ";
//        cout<<endl<<"票价："<<price<<endl<<endl;
    };
    inline bool SetSeats(char F, char C, char Y){
        seatF = F;
        seatC = C;
        seatY = Y;
        return true;
    };      //设置当前航班余座
    inline bool SetPrice(int ticketPrice){
        if(ticketPrice > 0) {
            price = ticketPrice;
            return true;
        }
        else return false;
    }//票价
    inline void Set_passenger_seatList(const char a[8]){
        for(int i = 0; i < 8; i++) passenger_seatList[i] = a[i];
   };//设置乘客座位表
    inline void Set_agc(vector<string> agency){
        agc = std::move(agency);
    };  //设置代理人
};


#endif //TRAVEL_RECOMMEND_SYSTEM_ANSELEMENT_H
