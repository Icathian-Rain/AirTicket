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
    vector <PriceRule> Table;
    map<string, int> carrierIndex;
    vector <map <string, int>> cityIndex;
public:
    void createTable(FILE *fp);
    void showCityIndex();
    int find(string carrier,string sCity,string dCity);
    vector<string> findAgency(string carrier,string sCity,string dCity);
    int findSurcharge(string carrier,string sCity,string dCity);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
