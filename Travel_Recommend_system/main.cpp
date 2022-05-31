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
//#include "Recommend_sys.h"
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
    Time t1;
    t1.string2time("20220512134000");
    vector<string> agc = {"CGQ001"};
    //HO;5769;20220512134000;20220512165500;SZX;BJS;
    FlightRequest a(t1,"NKG","SZX",agc,1,20);
    vector<FlightRequest> req;
    req.push_back(a);
    vector<FlightAns> ans = SET->multiAgencyRequest(req);
    for(int i = 0; i < ans.size(); i++) cout<<ans[i].Return_ticketPrice()<<endl;
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
