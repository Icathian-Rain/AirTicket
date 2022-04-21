//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_PRICERULE_H
#define TRAVEL_RECOMMEND_SYSTEM_PRICERULE_H
#include <string>
#include <vector>

class PriceRule {
private:
    int sequenceNo;         //序号
    std::string carrier;    //承运人
    std::string sCity;
    std::string dCity;
    std::string nextCarrier;    //后续衔接的航空公司，可为空
    std::vector <std::string> agency;   //允许出票的代理人队列
    char surcharge;     //额外费用百分比
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICERULE_H
