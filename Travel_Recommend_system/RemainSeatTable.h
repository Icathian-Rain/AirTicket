//
// Created by sszg on 22-5-28.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H
#define TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H
#include "RemainingSeat.h"
#include <map>
#include <unistd.h>
#include<fstream>
using namespace std;
extern vector<string> mysplit(string str, const string& separator);
class RemainSeatTable {
private:
    map<string,map<string,RemainingSeat>> seatTable;
public:
    inline RemainingSeat getSeat(string &t,string &n){//Time is the DepatureTime and the string is the carruer+flighNo
        map<string,map<string,RemainingSeat>>::iterator iter1;
        iter1 = seatTable.find(t);
        if(iter1!=seatTable.end()){
            map<string ,RemainingSeat>::iterator iter2;
            iter2 = (iter1->second).find(n);
            if(iter2!=(iter1->second).end()){
                return iter2->second;
            }
            else{
                return (iter1->second).end()->second;
            }
        }
        else{
            return (iter1->second).end()->second;//cannot find the seat
        }
    }
    inline bool isEmpty(){
        return seatTable.empty();
    }
    void CreatRemainSeatTable(const string& path);
    //void update();
    void update(const string& path);
//    void travel(map<string,RemainingSeat>);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H