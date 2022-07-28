//
// Created by sszg on 22-5-28.
//

#include "RemainSeatTable.h"
//#include <thread>
void RemainSeatTable::CreatRemainSeatTable(const string& path) {
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
        seatTable.at(tmp).insert(pair<string,RemainingSeat>(data[0]+data[1],st));       //修改为data[0]+data[1]
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
    ifstream in(fullPath);
    string str;
    if(!in.is_open()){
        cout<<"cannot open the file"<<endl;
        return false;
    }
    map<string,map<string,RemainingSeat>>::iterator iter1;
    map<string ,RemainingSeat>::iterator iter2;
    while(getline(in,str)){
        vector<string> data = mysplit(str,";");
        string tmp = data[4];
        string key = data[0]+data[1];
        iter1 = seatTable.find(tmp);
        if(iter1!=seatTable.end()){
            iter2 = (iter1->second).find(key);
            if(iter2!=(iter1->second).end()){
                (iter2->second).setSeats(data[6][0],data[7][0],data[8][0]);     //更新余座
            }
            else cout<<key<<" not found!"<<endl;
        }
        else cout<<tmp<<" not found!"<<endl;
    }
    in.close();
    return true;
}



//void RemainSeatTable::travel(map<string,RemainingSeat> data){
//    map<string ,RemainingSeat>::iterator iter;
//    for(iter = data.begin();iter!=data.end();iter++){
//        (iter->second).updateSeats();
//    }
//}
