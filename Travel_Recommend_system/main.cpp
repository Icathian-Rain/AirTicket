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
#include "RemainSeatTable.h"
//#include "Recommend_sys.h"
#include <vector>
#include <string>
extern FlightSet *SET;
extern PriceRuleTable *PRT;
extern PriceTable *PT;
extern RemainSeatTable *RST;
int main() {

    FlightSet *SET =new FlightSet;
    PriceRuleTable *PRT =new PriceRuleTable;
    PriceTable *PT =new PriceTable;
    RemainSeatTable *RST =new RemainSeatTable;
    vector<string> cityName={"北京","上海","广州","深圳","香港","澳门","沈阳","青岛","济南","武汉","厦门","西安","长沙","南京","杭州","重庆","成都","昆明","贵阳","三亚","海口","乌鲁木齐","西宁","兰州","银川","拉萨"};
    //SET init
    SET->initSet(cityName, "20220503000000", 10);
    FILE *fp1=fopen("../flight.txt","r");
    FILE *fp2=fopen("../price.txt","r");
    if(fp1==NULL||fp2==NULL){
        cout<<"flight error!";
        return -1;
    }
    SET->createSet(fp1,fp2);

    //PT init
    FILE *fp3=fopen("../price.txt","r");
    if(fp3==NULL){
        cout<<"price error!";
        return -1;
    }
    cout<<"start gathering price....."<<endl;
    PT->createTable(fp3);
//    pt.showCityIndex();
    cout<<"gather finishing!"<<endl<<endl;

    //PRT init
    FILE *fp4=fopen("../priceRule.txt","r");
    if(fp4==NULL){
        cout<<"priceRule error!";
        return -1;
    }
    cout<<"start gathering price rules....."<<endl;
    PRT->createTable(fp4);
    cout<<"gather finishing!"<<endl<<endl;

    //RST init
    RST->CreatRemainSeatTable("../seats.txt");

    PT->findPrice("FM","KHG","DNH");
    PT->findPrice("JZ","WDF","FEG");
    PT->findPrice("CA","WDF","FEG");
    PRT->findAgency("FM","KHG","DNH");
    PRT->findSurcharge("FM","KHG","DNH");
    PRT->findAgency("JZ","WDF","FEG");
    PRT->findAgency("CA","WDF","FEG");
    return 0;
}
