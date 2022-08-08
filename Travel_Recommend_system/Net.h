//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_NET_H
#define TRAVEL_RECOMMEND_SYSTEM_NET_H
#include "Time.h"
#include "Flight.h"
#include "AnsElement.h"
#include "FlightRequest.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "RemainingSeat.h"
#include "PriceRuleTable.h"
#include "PriceTable.h"
#include "RemainSeatTable.h"
#include "FluctuationTable.h"

#define CITYNUM 119
class Net {
private:
    int vexnum = 0;     //城市數目
    Time time;      //日期
    vector<Flight> matrix[CITYNUM][CITYNUM];
    map<string,int> vertex;         //城市字典
    int FindIndex(const string& city) {//找到城市在數組中的下標位置
        if(vertex.find(city)==vertex.end())
            return -1;
        return vertex[city];
    }
public:
    void initNet(const vector<string>& cityName, Time t);
    void addFlight(const string& sCity,const string& dCity,const string& flightNo,const string& carriers,Time tT,Time aT);
    void showNet();
    vector<AnsElement> request(FlightRequest req);   //單请求情況
};

#endif //TRAVEL_RECOMMEND_SYSTEM_NET_H
