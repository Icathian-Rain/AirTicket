//
// Created by sszg on 22-4-20.
//

#include "FlightSet.h"

extern unordered_map<string, int> City_index
({{"HRB",0},{"MDG",1},{"NDG",2},{"JMU",3},     //黑龙江
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

void FlightSet::initSet(vector<string> CityName, string t, int future_days) {
    int timearray[3],cnt=0;
    for (int i = 0;i < 10;i++) {
        timearray[cnt++] = atoi(&t[i]);
        for(;isdigit(t[i])&&i<10;i++);
    }
    today.year = timearray[0];
    today.month = timearray[1];
    today.day = timearray[2];
    today.hour = today.minute = 0;
    Time temp = today;
    for (int i = 0;i < future_days;i++) {
        Net net;
        temp.tomorrow();
        net.initNet(CityName, temp);
        flightSet.push_back(net);
    }
}

void FlightSet::update() {


}

vector<FlightAns> FlightSet::request(vector<FlightRequest> req) {

    int req_size = req.size();      //航班联程数量
    vector<Flight> tmp[req_size];       //暂存每一段航班的搜索结果
    vector<vector<SameDayFlight> >allowed_combinations; //允许的航班组合,由这个结构得到最终的Ans
    //该结构主要针对处理同一天的多段请求，将他们组合并且合并起来
    vector<FlightAns> ans;          //final answer
    bool flag = false;              //标记是否有同一天的连程航班
    Time last_date = today;         //记录上一段航班的日期
    for(int i = 0; i < req.size(); i++) {
        if (i) {
            if (Time::Date_equal(req[i].timeVal(), last_date)) flag = true;
            else flag = false;
        }
        int d = getDir(req[i]);     //date_index日期索引
        tmp[i] = flightSet[d].request(req[i]);  //返回按照价格升序的航班结果
        last_date = req[i].timeVal();

        //都存入类型SameDayFlight的二维数组中，对于同一天的进行合并
        if (flag) {   //如果与上一段在同一天，则进行组合
            int index = allowed_combinations.size() - 1;     //定位上一组
            //按照抵达时间升序排序
            sort(allowed_combinations[index].begin(),allowed_combinations[index].end(),SameDayFlight::compare_arriveTime);
            //对当前航段按照起飞时间降序排序
            sort(tmp[i].begin(),tmp[i].end(),Flight::compare_takeOffTime);
            int sign = tmp[i].size();       //标记
            vector<SameDayFlight> newSection;
            for (int j = 0; j < allowed_combinations[index].size(); j++) {
                for (int k = 0; k < sign; k++) {
                    if (Time::connect_ok(allowed_combinations[index][j].arriveTime, tmp[i][k].takeOffTimeVal())) {
                        //如果满足衔接要求
                        SameDayFlight element = allowed_combinations[index][j];     //copy
                        element.push_back(tmp[i][k]);
                        newSection.push_back(element);
                    }
                    else{//剪枝
                        sign = k;
                        break;
                    }
                    if(sign == 0) break;
                }
            }
            //删掉原来的，加入组合之后的
            allowed_combinations.pop_back();
            allowed_combinations.push_back(newSection);

        } else {       //如果不在同一天
            vector<SameDayFlight> section;
            for (int j = 0; j < tmp[i].size(); j++) {
                SameDayFlight p;
                p.push_back(tmp[i][j]);
                section.push_back(p);
            }
            allowed_combinations.push_back(section);
        }
    }
    //对每一段SameDayFlight的结果按照票价排序
    for(int i = 0; i < allowed_combinations.size(); i++) sort(allowed_combinations[i].begin(),allowed_combinations[i].end(),SameDayFlight::comparePrice);
    //得到20个low_price结果

}