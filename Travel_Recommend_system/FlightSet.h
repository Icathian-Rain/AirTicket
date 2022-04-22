//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
#define TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
#include <vector>
#include "Time.h"
#include "Flight.h"
#include "FlightRequest.h"
#include "FlightAns.h"
#include <unordered_map>
#include <set>
#include <algorithm>

//城市hash表，为每个城市分配一个索引
unordered_map<string, int> City_index({{"HRB",0},{"MDG",1},{"NDG",2},{"JMU",3},     //黑龙江
                                       {"CGQ",4},{"YNJ",5},{"JIL",6},{"NBS",7},                            //吉林
                                       {"SHE",8},{"DDG",9},{"JNZ",10},{"DLC",11},{"CHG",12},               //辽宁
                                       {"TNA",13},{"YNT",14},{"WEF",15},{"TAO",16},{"WEH",17},{"LYI",18},   //山东
                                       {"PEK",19},{"SJW",20},{"TSN",21},{"SHP",22},            //北京、河北
                                       {"CGO",23},{"LYA",24},{"NNY",25},                           //河南
                                       {"WUH",26},{"XFN",27},{"ENH",28},{"YIH",29},{"SHS",30},                     //湖北
                                       {"CSX",31},{"CGD",32},{"LLF",33},{"DYG",34},{"HNY",35},{"JZH",36},              //湖南
                                       {"NKG",37},{"LYG",38},{"SZV",39},{"CZX",40},{"NTG",41},{"YNZ",42},{"XUZ",43},{"WUX",44},{"HSN",45},     //江苏
                                       {"HGH",46},{"NGB",47},{"YIW",48},{"SHA",49},{"HYN",50},{"WNZ",51},{"JUZ",52},           //浙江、上海
                                       {"FOC",53},{"JJN",54},{"LCX",55},{"XMN",56},{"WUS",57},                             //福建
                                       {"TYN",58},                     //山西太原
                                       {"SIA",59},{"UYN",60},{"HZG",61},{"ENY",62},                //陕西
                                       {"CTU",63},{"YBP",64},{"CKG",65},{"GHN",66},{"LZO",67},{"WXN",68},{"MIG",69},{"GYS",70},{"PZI",71},{"XIC",72},  //四川
                                       {"HFE",73},{"AQG",74},{"BFU",75},{"TXN",76},{"FUG",77},     //安徽
                                       {"KHN",78},{"JDZ",79},{"JGS",80},{"JIU",81},{"KOW",82},{"LUZ",83},      //江西
                                       {"KMG",84},{"JHG",85},{"SYM",86},{"DLU",87},{"DIG",88},{"TCZ",89},{"LJG",90},{"LUM",91},     //云南
                                       {"NNG",92},{"BHY",93},{"WUZ",94},{"KWL",95},{"LZH",96},     //广西
                                       {"KWE",97},{"ZYI",98},{"TEN",99},                   //贵州
                                       {"CAN",100},{"ZUH",101},{"YGG",102},{"SZX",103},{"SWA",104},{"FUO",105},{"ZHA",106},{"MXZ",107},    //广东
                                       {"HAK",108},{"SYX",109},        //海南
                                       {"HET",110},{"BAV",111},{"TGO",112},{"CIF",113},{"HLD",114},{"HLH",115},    //内蒙古
                                       {"LHW",116},{"DNH",117},{"JGN",118},        //甘肃
                                       {"URC",119},{"AAT",120},{"KHG",121},{"YIN",122},        //新疆
                                       {"INC",123},        //宁夏
                                       {"XNN",124},{"GOQ",125},        //青海
                                       {"LXA",126}});      //西藏拉萨

class FlightSet {//所有航班集合
private:
    Time today;     //今天的日期
    //vector <Flight> flightSet;  //未來所有天的航班按照日期排成數組
    vector<Flight>flightSet[367][127];   //367x127，对应该年中每一天的航班，以及每一天中以某一城市为起飞城市的航班;
public:
    //int getDir(FlightRequest req){return req.timeVal().day2int()-today.day2int();};//獲取待搜索的日期在日期數組中的位置
    int getDir(FlightRequest req){return req.timeVal().day2int();};//获取日期索引
    vector <FlightAns> request(vector <FlightRequest> req); //輸入請求向量，獲取每一個請求的日期，分別調用當天航班的信息，最後返回結果向量
    vector <FlightAns> multiAgencyRequest(vector <FlightRequest> req);
    vector <FlightAns> multiPassengerRequest(vector <FlightRequest> req);
};


#endif //TRAVEL_RECOMMEND_SYSTEM_FLIGHTSET_H
