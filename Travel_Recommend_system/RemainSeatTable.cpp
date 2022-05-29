//
// Created by sszg on 22-5-28.
//

#include "RemainSeatTable.h"
void RemainSeatTable::CreatRemainSeatTable(string path) {
    ifstream in(path);
    string str;
    if(!in.is_open()){
        cout<<"cannot open the file"<<endl;
        return;
    }
    Time tmp;
    while(getline(in,str)){
        vector<string> data = mysplit(str,",");
        tmp.string2time(data[4]);
        map<string,RemainingSeat> table;
        seatTable.insert(pair<Time,map<string,RemainingSeat>>(tmp,table));
        RemainingSeat st(data);
        seatTable.at(tmp).insert(pair<string,RemainingSeat>(data[1],st));
    }
    in.close();
}