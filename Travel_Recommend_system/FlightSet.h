//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
#include <vector>
#include "Time.h"
#include "Flight.h"
#include "FlightAns.h"
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <fstream>
#include "RemainingSeat.h"
#include "Net.h"
//城市hash表，为每个城市分配一个索引
extern vector<string> mysplit(string str, const string& separator);
class FlightSet {//所有航班集合
private:
    Time today;     //今天的日期
    int future_day; //未來天數
    vector<Net> flightSet;         //存储所有航班信息
public:
    void initSet(const vector<string>& CityName, string t, int future_days);
    void createSet(FILE *fp);
    inline int getDir(FlightRequest req){return today.timeInterval(req.timeVal());};//獲取待搜索的日期在日期數組中的位置
    vector <FlightAns> request(vector <FlightRequest> req); //輸入請求向量，獲取每一個請求的日期，分別調用當天航班的信息，最後返回結果向量
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
