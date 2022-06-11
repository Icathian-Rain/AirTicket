//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
#include <vector>
#include <string>
#include "Flight.h"
#include "AnsElement.h"
using namespace std;
class FlightAns {
private:
    vector<AnsElement> flight;//航班信息,可能是多个航班联程
    //Flight flight;
    int ticketPrice = 0;//总票價
    vector<string> agc;
public:
    //获取信息
    inline vector<AnsElement> Return_flight(){ return flight;};
    inline int Return_ticketPrice(){ return ticketPrice;};
    //string Return_agency();


    static bool comparePrice(const FlightAns &a1, const FlightAns &a2){       //自定义比较函数、用于sort、set
        return a1.ticketPrice < a2.ticketPrice;
    }
    inline void Add(AnsElement sdf){
        flight.push_back(sdf);
        ticketPrice += sdf.Return_price();
    };                //添加航段到Ans当中,因为代码量小并且频繁使用，故改为内联函数inline
    bool Connect_ok();                      //判断是否满足衔接条件

    inline void ShowAns(){
        cout<<"ANs :"<<endl;
        cout<<"Agency :"<<endl;
        for(int i = 0; i < agc.size(); i++) cout<<agc[i]<<" ";
        cout<<endl;
        cout<<"Total price："<<ticketPrice<<endl;
        cout<<"segment flights:"<<endl;
        for(int i = 0; i < flight.size(); i++) flight[i].showElement();
    }
    bool GetCommon_agc();       //从flight中获取公共代理商，如果为空返回false
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTANS_H
