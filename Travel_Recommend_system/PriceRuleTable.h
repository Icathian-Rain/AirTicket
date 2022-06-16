//
// Created by sszg on 22-5-16.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
#define TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
#include <iostream>
#include <string>
#include <map>
#include "PriceRule.h"
using namespace std;

class PriceRuleTable {
private:
    vector <PriceRule> Table;//票价规则表
    map<string, int> carrierIndex;//航班承运人出现的先后顺序
    //下标是carrierIndex中航班承运人的位置，每一个元素是一个字典，是这个航班承运人的城市索引，在Table中的下标
    vector <map <string, int>> cityIndex;
public:
    void createTable(FILE *fp);
    void showCityIndex();//打印各个航班承运人的城市索引
    int find(const string& carrier,const string& sCity,const string& dCity);//输入承运人，起始终止城市，找到在Table中的下标
    //输入承运人，起始终止城市，输出代理人
    vector<string> findAgency(const string& carrier,const string& sCity,const string& dCity);
    void show(const string& carrier,const string& sCity,const string& dCity);
    //输入承运人，起始终止城市，输出Surcharge
    int findSurcharge(const string& carrier,const string& sCity,const string& dCity);
    void showSurcharge(const string& carrier,const string& sCity,const string& dCity);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
