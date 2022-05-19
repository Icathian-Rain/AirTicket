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
    map <string, int> carrierIndex;
    vector <map <string, int>> cityIndex;
public:
    void createTable(FILE *fp);
    void showCityIndex();
    int *findPrice(string carrier,string sCity,string dCity);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICETABLE_H
