//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_PRICERULE_H
#define TRAVEL_RECOMMEND_SYSTEM_PRICERULE_H
#include <string>
#include <vector>
using namespace std;
class PriceRule {
private:
    int sequenceNo;         //序号，不可重復
    string carrier;    //承运人，不能爲空
    string sCity;
    string dCity;
    string nextCarrier;    //后续衔接的航空公司，可为空
    vector <string> agency;   //允许出票的代理人队列
    char surcharge;     //额外费用百分比
public:
    //获取信息
    int Return_sequenceNo();
    string Return_carrier();
    string Return_sCity();
    string Return_dCity();
    string Return_nextCarrier();
    vector <string> Return_agency();
    char Return_surcharge();
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICERULE_H
