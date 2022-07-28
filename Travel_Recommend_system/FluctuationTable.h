//
// Created by sszg on 22-7-28.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#ifndef TRAVEL_RECOMMEND_SYSTEM_FLUCTUATIONTABLE_H
#define TRAVEL_RECOMMEND_SYSTEM_FLUCTUATIONTABLE_H


class FluctuationTable {

private:
    //'JGN', 'DNH', 'MDG', 'WEF', 'NZH', 'JIL', 'LLF', 'WNZ', 'HFE', 'HGH', 'CTU', 'HLH', 'SHS', 'BHY', 'BSD', 'NNG', 'TEN', 'SHP', 'KRY', 'AVA'
    map<string,int> fluctuation;         //代理人不同造成的票价波动
    int fluctuation_price[3];            //票价波动值
public:
    void init_fluctuation(vector<string> agency);    //初始化票价波动
    int index_fluctuation(string agc);       //找到代理人对应索引
    int find_fluctuation_price(int index);   //找到票价波动值
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLUCTUATIONTABLE_H
