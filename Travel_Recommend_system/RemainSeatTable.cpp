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
    while(getline(in,str)){
        vector<string> data = mysplit(str,";");
        string tmp = data[4];
        map<string,RemainingSeat> table;
        seatTable.insert(pair<string,map<string,RemainingSeat>>(tmp,table));
        RemainingSeat st(data);
        seatTable.at(tmp).insert(pair<string,RemainingSeat>(data[1],st));
    }
    in.close();
}

void RemainSeatTable::update() {
    sleep(10);
    map<string,map<string ,RemainingSeat>>::iterator iter1;
    for(iter1 = seatTable.begin();iter1!=seatTable.end();iter1++){
        map<string ,RemainingSeat>::iterator iter2;
        for(iter2 = (iter1->second).begin();iter2!=(iter1->second).end();iter2++){
            (iter2->second).updateSeats();
        }
    }
    return;
}
