//
// Created by sszg on 22-5-19.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_PRICETABLE_H
#define TRAVEL_RECOMMEND_SYSTEM_PRICETABLE_H
#include "Price.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class PriceTable {
private:
    vector <Price> Table;
    map <string, int> carrierIndex;//航班承运人出现的先后顺序
    //下标是carrierIndex中航班承运人的位置，每一个元素是一个字典，是这个航班承运人的城市索引，在Table中的下标
    vector <map <string, int>> cityIndex;
public:
    void createTable(FILE *fp);
    void showCityIndex();//打印各个航班承运人的城市索引
    //输入航班承运人，起始终止城市，输出F\C\Y的票价
    int *findPrice(const string& carrier,const string& sCity,const string& dCity);
    void showPrice(const string& carrier,const string& sCity,const string& dCity);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICETABLE_H
