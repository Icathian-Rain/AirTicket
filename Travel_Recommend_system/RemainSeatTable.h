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
    map<string,long> seatTable;
    string filename;
public:
    inline RemainingSeat getSeat(string &t,string &n,string &dCity){//Time is the DepatureTime and the string is the carruer+flighNo
        RemainingSeat ret("20200831");//if there is no suitable flight, return this object
        if(seatTable.find(t)==seatTable.end()){
            return ret;
        }
        long lines = seatTable[t];
        FILE *fp = fopen(filename.c_str(),"r+");
        fseek(fp,54L*lines,SEEK_SET);
        char buffer[200];
        while(fgets(buffer,200,fp)!= nullptr){
            vector<string> data = mysplit(buffer,";");
            if(data[4].find(t)!=0){
                break;
            }
            if(data[3]==dCity){
                RemainingSeat ans(data);
                return ans;
            }
        }
        return ret;
    }
    inline bool isEmpty(){
        return seatTable.empty();
    }
    void CreatRemainSeatTable(const string& path);
    //void update();
    bool update(const string& path);
//    void travel(map<string,RemainingSeat>);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_REMAINSEATTABLE_H