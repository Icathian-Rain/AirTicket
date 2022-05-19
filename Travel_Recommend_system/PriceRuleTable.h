//
// Created by sszg on 22-5-16.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
#define TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
#include <iostream>
#include "PriceRule.h"
using namespace std;

class PriceRuleTable {
public:
    vector <PriceRule> Table;
    void createTable(FILE *fp);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICERULETABLE_H
