#include <iostream>
using namespace std;
//#include "Flight.h"
//#include "Time.h"
//#include "PriceRule.h"
#include "Net.h"
//#include "FlightAns.h"
//#include "FlightRequest.h"
//#include "RemainingSeat.h"
#include "FlightSet.h"
#include "PriceRule.h"
#include "PriceRuleTable.h"
#include "PriceTable.h"
//#include "Recommend_sys.h"
#include <vector>
#include <string>

int main() {
    vector<string> cityName={"北京","上海","广州","深圳","香港","澳门","沈阳","青岛","济南","武汉","厦门","西安","长沙","南京","杭州","重庆","成都","昆明","贵阳","三亚","海口","乌鲁木齐","西宁","兰州","银川","拉萨"};
    FlightSet set;
    set.initSet(cityName, "20220503000000", 10);
    FILE *fp1=fopen("../flight2.txt","r");
    FILE *fp2=fopen("../price.txt","r");
    if(fp1==NULL||fp2==NULL){
        cout<<"flight error!";
        return -1;
    }
    set.createSet(fp1,fp2);
//    set.showSet();
    PriceTable pt;
    FILE *fp3=fopen("../price.txt","r");
    if(fp3==NULL){
        cout<<"price error!";
        return -1;
    }
    cout<<"start gathering price....."<<endl;
    pt.createTable(fp3);
//    pt.showCityIndex();
    cout<<"gather finishing!"<<endl<<endl;
    pt.findPrice("FM","KHG","DNH");
    pt.findPrice("JZ","WDF","FEG");
    pt.findPrice("CA","WDF","FEG");
    PriceRuleTable prt;
    FILE *fp4=fopen("../priceRule.txt","r");
    if(fp4==NULL){
        cout<<"priceRule error!";
        return -1;
    }
    cout<<"start gathering price rules....."<<endl;
    prt.createTable(fp4);
    cout<<"gather finishing!"<<endl;
//    prt.showCityIndex();
    prt.findAgency("FM","KHG","DNH");
    prt.findSurcharge("FM","KHG","DNH");
    prt.findAgency("JZ","WDF","FEG");
    prt.findAgency("CA","WDF","FEG");
    return 0;
}
