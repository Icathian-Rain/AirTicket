//
// Created by sszg on 22-5-28.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H
#define TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H
#include "RemainingSeat.h"
#include <map>
#include<fstream>
#include "FlightSet.h"
using namespace std;

class RemainSeatTable {
private:
    map<Time,map<string,RemainingSeat>> seatTable;
public:
    inline RemainingSeat getSeat(Time &t,string &n){//Time is the DepatureTime and the string is the flighNo
        map<Time,map<string,RemainingSeat>>::iterator iter1;
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
        return seatTable.size()==0;
    }
    RemainSeatTable(string path);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H