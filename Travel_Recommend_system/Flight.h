//航班信息
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
#include <string>
#include "Time.h"
#include "PriceRule.h"
using namespace std;
class Flight{//一個航班信息
private:
    string carrier;        //承运人
    string flightNo;       //航班号
    Time takeOffTime;      //起飞时间
    Time arrivalTime;      //抵达时间
    string sCity;          //起飞城市
    string dCity;          //抵达城市
    int price;              //票价，目前还没有使用运价这一数据，暂用Price替代

public:
    //获取航班信息,inline内联函数，提升效率，适用于代码量小(<10行)并且频繁使用的函数
    inline string carrierVal(){ return carrier;};
    inline string flightNoVal(){ return flightNo;};
    inline string sCityVal(){ return sCity;};
    inline string dCityVal(){ return dCity;};
    inline Time takeOffTimeVal(){ return takeOffTime;};
    inline Time arrivalTimeVal(){ return  arrivalTime;};
    inline int Return_price(){ return price;};         //返回票价
    PriceRule rule;         //运价规则
    static bool comparePrice(const Flight &f1, const Flight &f2){       //自定义比较函数、用于sort、set
        return f1.price < f2.price;
    }
    void createFlight(string carr,string flightN,Time tTime,Time aTime,string sCi,string dCi,int pri){carrier=carr,flightNo=flightN,takeOffTime=tTime,arrivalTime=aTime,sCity=sCi,dCity=dCi,price=pri;};
    void showFlight(){
        cout<<"航班号："<<flightNo<<endl;
        cout << "起飞时间：";
        takeOffTime.showTime();
        cout<<"抵达时间：";
        arrivalTime.showTime();
        cout<<"起飞城市："<<sCity<<endl;
        cout<<"抵达城市："<<dCity<<endl;
        cout<<"票价："<<price<<endl<<endl;
    };
    static bool compare_takeOffTime(const Flight &f1, const Flight &f2){       //按照起飞时间降序
        Time t1 = f1.takeOffTime;
        Time t2 = f2.takeOffTime;
        return Time::compare_Time(t1,t2);          //降序排序
    }
};

#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHT_H
