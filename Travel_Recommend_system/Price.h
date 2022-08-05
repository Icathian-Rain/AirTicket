//
// Created by sszg on 22-5-19.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_PRICE_H
#define TRAVEL_RECOMMEND_SYSTEM_PRICE_H
#include <string>
#include <utility>
using namespace std;

class Price {
private:
    string carrier;
    string sCity;
    string dCity;
    int price[3];//F,C,Y charge
public:
    void setPrice(string car,string sC,string dC,int F,int C,int Y){
        carrier=std::move(car),sCity=std::move(sC),dCity=std::move(dC);
        price[0]=F,price[1]=C,price[2]=Y;
    }
    inline string Return_carrier(){ return carrier;};
    inline string Return_sCity(){ return sCity;};
    inline string Return_dCity(){ return dCity;};
    inline int* Return_price(){ return price;};
};


#endif //TRAVEL_RECOMMEND_SYSTEM_PRICE_H
