//
// Created by sszg on 22-5-16.
//

#include "PriceRuleTable.h"
void PriceRuleTable::createTable(FILE *fp){
    char buffer[200];
    vector <string> temp;
    int i=0;
    while (fgets(buffer, 200, fp) != NULL) {
        string info(buffer);
        int cutAt;
        while( (cutAt = info.find_first_of(";")) != info.npos ){
            if(cutAt > 0)
                temp.push_back(info.substr(0, cutAt));
            info = info.substr(cutAt + 1);
        }
        PriceRule pr;
        pr.setRule(atoi(buffer),temp[1],temp[2],temp[3],temp[4],temp[5],temp[6]);
        Table.push_back(pr);
    }
}
