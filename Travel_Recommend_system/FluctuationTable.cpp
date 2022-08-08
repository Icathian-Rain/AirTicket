//
// Created by sszg on 22-7-28.
//

#include "FluctuationTable.h"

void FluctuationTable::init_fluctuation(vector<string> agency) {
    cout<<"init fluctuation："<<endl;
    //设置波动票价
    fluctuation_price[0] = 30;
    fluctuation_price[1] = 0;
    fluctuation_price[2] = -10;

    for(auto &agc : agency) {
        int n = rand()%3;
        fluctuation.insert({agc+"001", n});     //使用随机数分组0,1,2
        cout<<agc<<":"<<fluctuation_price[n]<<endl;
    }
    return;
}

int FluctuationTable::index_fluctuation(string agc) {
    map<string,int>::iterator iter = fluctuation.find(agc);
    if(iter != fluctuation.end()){
        return iter->second;
    }
    return 3;
}

int FluctuationTable::find_fluctuation_price(int index) {
    if(index < 3 && index >= 0) {
        return fluctuation_price[index];
    }
    return 404;
}