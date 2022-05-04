//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_NET_H
#define TRAVEL_RECOMMEND_SYSTEM_NET_H
#include "Time.h"
#include "Flight.h"
#include "FlightAns.h"
#include "FlightRequest.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>

extern vector<string> mysplit(string str, string separator);
static map<string,string> city={{"BJS","北京"},{"SHA","上海"},{"CAN","广州"},{"SZX","深圳"},{"HKG","香港"},{"MFM","澳门"},{"SHE","沈阳"},{"TAO","青岛"},{"TNA","济南"},{"WUH","武汉"},{"XMN","厦门"},{"SIA","西安"},{"CSX","长沙"},{"NKG","南京"},{"HGH","杭州"},{"CKG","重庆"},{"CTU","成都"},{"KMG","昆明"},{"KWE","贵阳"},{"SYX","三亚"},{"HAK","海口"},{"URC","乌鲁木齐"},{"XNN","西宁"},{"LHW","兰州"},{"INC","银川"},{"LXA","拉萨"}};

#define CITYNUM 27
class Net {
private:
    int vexnum;     //城市數目
    Time time;      //日期
    vector<Flight> matrix[CITYNUM][CITYNUM];
    string vertex[CITYNUM];         //城市數組
    int FindIndex(string city) {//找到城市在數組中的下標位置
        for (int i = 0;i < vexnum;i++) {
            if (vertex[i] == city) {
                return i;
            }
        }
        return -1;
    }
public:
    void initNet(vector<string> cityName, Time t){
        vexnum = cityName.size();
        for (int i = 0;i < vexnum;i++) {
            vertex[i] = cityName[i];
        }
        time=t;
        for (int i = 0;i < CITYNUM;i++) {
            for (int j = 0;j < CITYNUM;j++) {
                matrix[i][j] = vector<Flight>();
            }
        }
    }
    void addFlight(string sCity,string dCity,string flightNo,string carriers,Time tT,Time aT,int price){//add one flight
        int sCityIndex = FindIndex(city[sCity]);
        int dCityIndex = FindIndex(city[dCity]);
        if(sCityIndex==-1||dCityIndex==-1){
            cout<<"error"<<endl;
            return ;
        }
        Flight flight;
        flight.createFlight(carriers, flightNo, tT, aT, sCity, dCity, price);
        matrix[sCityIndex][dCityIndex].push_back(flight);
    }
    void showNet() {
        for (int i = 0;i < vexnum;i++) {
            for (int j = 0;j < vexnum;j++) {
                if(matrix[i][j].size()!=0){
                    for (int k = 0;k < matrix[i][j].size();k++) {
                        matrix[i][j][k].showFlight();
                    }
                }
            }
        }
    }
    vector<Flight> request(FlightRequest req);   //單乘客單代理人情況
    FlightAns multiAgencyRequest(FlightRequest req);    //多代理人
    FlightAns multiPassengerRequest(FlightRequest req); //多乘客
    void update();
};


#endif //TRAVEL_RECOMMEND_SYSTEM_NET_H
