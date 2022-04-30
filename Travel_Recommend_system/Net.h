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
#include <algorithm>
extern vector<string> mysplit(string str, string separator);

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
    void createNet(FILE* fp) {
        char buffer[200];
        string flightNo,sCity,dCity,carrier,tT,aT;
        int price;
        char cabin;
        while (fgets(buffer, 200, fp) != NULL) {
            vector<string> str = mysplit(buffer, ";");
            flightNo = str[0];
            sCity = str[1];
            tT = str[2];
            aT = str[3];
            dCity = str[4];
            price = atoi(str[6].c_str());
            carrier = str[7];
            int sCityIndex = FindIndex(sCity);
            int dCityIndex = FindIndex(dCity);
            if(sCityIndex==-1||dCityIndex==-1){
                cout<<"error"<<endl;
                return ;
            }
            vector<string> carriers = mysplit(carrier, ",");
            Flight flight;
            int time1[6],time2[6],cnt=0;
            for (int i = 0;i < 19;i++) {
                time1[cnt] = atoi(&tT[i]);
                time2[cnt++] = atoi(&aT[i]);
                for(;isdigit(tT[i])&&i<19;i++);
            }
            Time tTime, aTime;
            tTime.year = time1[0];
            tTime.month = time1[1];
            tTime.day = time1[2];
            tTime.hour = time1[3];
            tTime.minute = time1[4];
            aTime.year = time2[0];
            aTime.month = time2[1];
            aTime.day = time2[2];
            aTime.hour = time2[3];
            aTime.minute = time2[4];
            flight.createFlight(carriers, flightNo, tTime, aTime, sCity, dCity, price);
            matrix[sCityIndex][dCityIndex].push_back(flight);
        }
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
