//
// Created by sszg on 22-5-28.
//

#include "RemainSeatTable.h"
//#include <thread>
void RemainSeatTable::CreatRemainSeatTable(const string& path) {
    seatTable.clear();
    ifstream in(path);
    string str;
    filename = path.substr(0, path.find("Setting.txt")) + ".txt";
    if(!in.is_open()){
        cout<<"cannot open the file"<<endl;
        return;
    }
    while(getline(in,str)){
        vector<string> data = mysplit(str,";");
        seatTable[data[0]] = stol(data[1]);
    }
    in.close();
}

//void RemainSeatTable::update() {
//    map<string,map<string ,RemainingSeat>>::iterator iter1;
//    for(iter1 = seatTable.begin();iter1!=seatTable.end();iter1++){
//        map<string ,RemainingSeat>::iterator iter2;
//        for(iter2 = (iter1->second).begin();iter2!=(iter1->second).end();iter2++){
//            (iter2->second).updateSeats();
//        }
//    }
//}

bool RemainSeatTable::update(const string& path) {      //读取数据文件实现更新
    string fullPath = "../" + path;
    CreatRemainSeatTable(path);
    return true;
}



//void RemainSeatTable::travel(map<string,RemainingSeat> data){
//    map<string ,RemainingSeat>::iterator iter;
//    for(iter = data.begin();iter!=data.end();iter++){
//        (iter->second).updateSeats();
//    }
//}
