#include <iostream>
using namespace std;
//#include "Flight.h"
//#include "Time.h"
//#include "PriceRule.h"
#include "Net.h"
//#include "FlightAns.h"
#include "FlightRequest.h"
//#include "RemainingSeat.h"
#include "FlightSet.h"
#include "PriceRule.h"
#include "PriceRuleTable.h"
#include "PriceTable.h"
#include "RemainSeatTable.h"
#include <vector>
#include <string>
#include <thread>
#include <future>
FlightSet *SET;
PriceRuleTable *PRT;
PriceTable *PT;
RemainSeatTable *RST;
int main() {

    SET =new FlightSet;
    PRT =new PriceRuleTable;
    PT =new PriceTable;
    RST =new RemainSeatTable;
    vector<string> cityName={"AQG", "AOG", "AVA", "AEB", "BSD", "BAV", "BHY", "PEK", "BFU", "CGQ", "CGD", "CSX", "CZX", "CTU", "CIF", "CKG", "DLU", "DLC", "DNH", "ENH", "FUO", "FUG", "HMI", "HGH", "HZG", "HFE", "HEK", "HNY", "TXN", "HET", "HUZ", "JMU", "KNC", "JGN", "JIL", "TNA", "JDZ", "JNG", "JNZ", "JIU", "CHW", "JZH", "KHG", "KRY", "KRL", "KMG", "LHW", "LXA", "LYG", "LJG", "LYI", "LHN", "LZH",
                             "LYA", "LUZ", "LZO", "LUM", "NZH", "MIG", "MDG", "KHN", "NAO", "NKG", "NNG", "NTG", "NNY", "NGB", "PZI", "TAO", "IQN", "SHP", "NDG", "JUZ", "SYX", "SHA", "PVG", "SWA", "SHS", "SHE", "SZX",
    "SJW", "SZV", "TYN", "TSN", "TNH", "TGO", "TEN", "WEF", "WEH", "WNZ", "WUH", "WHU", "HLH", "URC", "WUX", "WUS", "WUZ", "XMN", "XIY", "SIA", "XIC", "XIL", "XNN", "XUZ", "ENY", "YNZ", "YNT", "YBP", "YIH", "YIN", "YIW", "LLF", "DYG", "ZHA", "ZAT", "CGO", "HJJ", "ZUH", "ZYI"};
    //SET init
    SET->initSet(cityName, "20220530000000", 370);
    FILE *fp1=fopen("../flight.txt","r");
    FILE *fp2=fopen("../price.txt","r");
    if(fp1==NULL||fp2==NULL){
        cout<<"flight.txt(price.txt) open error!";
        return -1;
    }
    cout<<"start gathering flight....."<<endl;
    SET->createSet(fp1);
    cout<<"gather finishing!"<<endl<<endl;

    //PT init
    FILE *fp3=fopen("../price.txt","r");
    if(fp3==NULL){
        cout<<"price.txt open error!";
        return -1;
    }
    cout<<"start gathering price....."<<endl;
    PT->createTable(fp3);
//    pt.showCityIndex();
    cout<<"gather finishing!"<<endl<<endl;

    //PRT init
    FILE *fp4=fopen("../priceRule.txt","r");
    if(fp4==NULL){
        cout<<"priceRule.txt open error!";
        return -1;
    }
    cout<<"start gathering price rules....."<<endl;
    PRT->createTable(fp4);
    cout<<"gather finishing!"<<endl<<endl;

    //RST init
    RST->CreatRemainSeatTable("../FlightSeats.txt");
    Time t[4];
    t[0].string2time("20220621000000");
    t[1].string2time("20220622000000");
    t[2].string2time("20220623000000");
    t[3].string2time("20220624000000");
    vector<string> agc = {"CIF001","BHY001","AOG001","CZX001","BFU001","DLU001","CKG001","CTU001","DNH001"};
    string sCity[4],dCity[4];
    cout<<"cin>>"<<endl;
    while(cin>>sCity[0] && cin>>dCity[0]){
        cin>>sCity[1]>>dCity[1]>>sCity[2]>>dCity[2]>>sCity[3]>>dCity[3];
        vector<FlightRequest> req;
        for(int i = 0; i < 4; i++) {
            FlightRequest a(t[i],sCity[i],dCity[i],agc,1,20);
            req.push_back(a);
        }
        vector<FlightAns> ans = SET->request(req);
        cout<<"ANs number:"<<ans.size()<<endl;
        for(int i = 0; i < ans.size(); i++) ans[i].ShowAns();
    }
    //async(launch::async,[RST](){RST->update();});
//    PT->findPrice("FM","KHG","DNH");
//    PT->findPrice("JZ","WDF","FEG");
//    PT->findPrice("CA","WDF","FEG");
//    PRT->findAgency("FM","KHG","DNH");
//    PRT->findSurcharge("FM","KHG","DNH");
//    PRT->findAgency("JZ","WDF","FEG");
//    PRT->findAgency("CA","WDF","FEG");
    return 0;
}
