//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
#include <vector>
#include "Time.h"
#include "Flight.h"
#include "FlightRequest.h"
#include "FlightAns.h"
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "Net.h"
#include "SameDayFlight.h"
#include <queue>
//城市hash表，为每个城市分配一个索引
extern vector<string> mysplit(string str, string separator);

class FlightSet {//所有航班集合
private:
    Time today;     //今天的日期
    //vector <Flight> flightSet;  //未來所有天的航班按照日期排成數組
    vector<Net> flightSet;         //存储所有航班信息
public:
    void initSet(vector<string> CityName, string t, int future_days);
    void createSet(FILE *fp_flight,FILE *fp_price);
    void showSet();
    inline int getDir(FlightRequest req){return req.timeVal().day2int()-today.day2int();};//獲取待搜索的日期在日期數組中的位置
    void update();      //日期更新时对航班信息更新,pop_front,push_back
    vector <FlightAns> request(vector <FlightRequest> req, string target_agency); //輸入請求向量，獲取每一個請求的日期，分別調用當天航班的信息，最後返回結果向量
    vector <FlightAns> multiAgencyRequest(vector <FlightRequest> req);
    vector <FlightAns> multiPassengerRequest(vector <FlightRequest> req);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
