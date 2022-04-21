//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_NET_H
#define TRAVEL_RECOMMEND_SYSTEM_NET_H
#include "Time.h"
#include "Flight.h"
#include "FlightAns.h"
#include "FlightRequest.h"
#include <vector>

#define MAX 1000    //最大城市數目

class Net {
private:
    int vexnum;     //城市數目
    Time time;      //日期
    vector< vector<Flight>> matrix[MAX][MAX];
    string vertex[MAX];         //城市數組
    int FindIndex(string city){//找到城市在數組中的下標位置
        for(int i=0;i<vexnum;i++){
            if(vertex[i]==city) {
                return i;
            }
        }
        return -1;
    }
public:
    void createNet();
    FlightAns request(FlightRequest req);   //單乘客單代理人情況
    FlightAns multiAgencyRequest(FlightRequest req);    //多代理人
    FlightAns multiPassengerRequest(FlightRequest req); //多乘客
    void update();
};


#endif //TRAVEL_RECOMMEND_SYSTEM_NET_H
