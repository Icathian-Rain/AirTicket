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


#define CITYNUM 119
class Net {
private:
    int vexnum = 0;     //城市數目
    Time time;      //日期
    vector<Flight> matrix[CITYNUM][CITYNUM];
    vector <string> vertex;         //城市數組
    int FindIndex(const string& city) {//找到城市在數組中的下標位置
        for (int i = 0;i < vexnum;i++) {
            if (vertex[i] == city) {
                return i;
            }
        }
        return -1;
    }
public:
    void initNet(const vector<string>& cityName, Time t){
        vexnum=cityName.size();
        if(vexnum>CITYNUM)
            vexnum=CITYNUM;
        vertex=cityName;
        time=t;
        for (auto & i : matrix) {
            for (auto & j : i) {
                j = vector<Flight>();
            }
        }
    }
    void addFlight(const string& sCity,const string& dCity,const string& flightNo,const string& carriers,Time tT,Time aT){//add one flight
        int sCityIndex = FindIndex(sCity);
        int dCityIndex = FindIndex(dCity);
        if(sCityIndex==-1||dCityIndex==-1||sCityIndex>CITYNUM||dCityIndex>CITYNUM){
            cout<<"FLight index out!"<<endl;
            return ;
        }
        Flight flight(carriers, flightNo, tT, aT, sCity, dCity);
//        flight.createFlight(carriers, flightNo, tT, aT, sCity, dCity);
        matrix[sCityIndex][dCityIndex].push_back(flight);
    }

    void showNet() {
        for (int i = 0;i < vexnum;i++) {
            for (int j = 0;j < vexnum;j++) {
                if(!matrix[i][j].empty()){
                    for (auto & k : matrix[i][j]) {
                        k.showFlight();
                    }
                }
            }
        }
    }
    vector<AnsElement> request(FlightRequest req);   //單请求情況
};


#endif //TRAVEL_RECOMMEND_SYSTEM_NET_H
