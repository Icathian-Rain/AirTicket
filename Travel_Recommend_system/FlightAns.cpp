//
// Created by sszg on 22-4-20.
//

#include "FlightAns.h"
//判断是否满足衔接条件
bool FlightAns::Connect_ok() {
    if(flight.size() <= 1) return true;
    else{
        bool flag = true;
        Time last = flight[0].arrivalTimeVal();
        for(int i = 1; i < flight.size(); i++){
            flag = Time::connect_ok(last,flight[i].takeOffTimeVal());
            if(flag) last = flight[i].arrivalTimeVal();
            else break;
        }
        return flag;
    }
}

bool FlightAns::GetCommon_agc() {
    if(flight.empty()) {
        cout<<"Ans element empty!"<<endl;
        return false;
    }
    vector<string> last = flight[0].Return_agc();
    for(int i = 1; i < flight.size(); i++) {
        vector<string> now = flight[i].Return_agc();
        vector<string> tmp;
        for(int j = 0; j < last.size(); j++) {
            for(int k = 0; k < now.size(); k++) {
                if(last[j] == now[k]) tmp.push_back(last[j]);
                continue;
            }
        }
        if(tmp.empty()) return false;
        last = tmp;
    }
    if(last.empty()) return false;
    agc = last;
    return true;
}