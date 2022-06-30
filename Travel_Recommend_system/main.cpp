#include <iostream>
#include <json/json.h>
#include "httplib.h"
using namespace std;
//#include "Flight.h"
//#include "Time.h"
//#include "PriceRule.h"
#include "Net.h"
//#include "FlightAns.h"
#include "FlightRequest.h"
//#include "RemainingSeat.h"
#include "FlightSet.h"
#include "PriceRuleTable.h"
#include "PriceTable.h"
#include "RemainSeatTable.h"
#include <vector>
#include <string>
FlightSet *SET;
PriceRuleTable *PRT;
PriceTable *PT;
RemainSeatTable *RST;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif defined(_MSC_VER)
#pragma warning(disable : 4996)
#endif



int initialize();

void srv_setup(const string&, int);

int main() {
    //gathering data info
    if(initialize()==-1){
        return -1;
    }
    srand((int)time(0));
    srv_setup("0.0.0.0", 8080);
    return 0;
}

int initialize(){
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
    if(fp1==nullptr||fp2==nullptr){
        cout<<"flight.txt(price.txt) open error!";
        return -1;
    }
    cout<<"start gathering flight....."<<endl;
    SET->createSet(fp1);
    cout<<"gather finishing!"<<endl<<endl;

    //PT init
    FILE *fp3=fopen("../price.txt","r");
    if(fp3==nullptr){
        cout<<"price.txt open error!";
        return -1;
    }
    cout<<"start gathering price....."<<endl;
    PT->createTable(fp3);
//    pt.showCityIndex();
    cout<<"gather finishing!"<<endl<<endl;

    //PRT init
    FILE *fp4=fopen("../priceRule.txt","r");
    if(fp4==nullptr){
        cout<<"priceRule.txt open error!";
        return -1;
    }
    cout<<"start gathering price rules....."<<endl;
    PRT->createTable(fp4);
    cout<<"gather finishing!"<<endl<<endl;

    //RST init
    cout<<"start gathering remaining seats....."<<endl;
    RST->CreatRemainSeatTable("../FlightSeats.txt");
    cout<<"gather finishing!"<<endl<<endl;

    cout << "Down" << endl;
    return 1;
}

/**
 * @brief http服务器启动
 * 
 * @param ip_addr 监听的ip地址
 * @param port 端口
 */

void srv_setup(const string& ip_addr, int port)
{
        // 初始化svr
        httplib::Server svr;
        // read:读取json
        Json::Reader read;
        svr.Post("/api/query", [&](const httplib::Request &req, httplib::Response &res)
        {
            // 获取request的数据
            string req_data = req.body;
            Json::Value value;
            read.parse(req_data, value);
            // 获取乘客人数
            char passNum = value.get("N", 0).asInt();
            // 获取agc列表
            Json::Value rawAgc = value.get("agency", 0);
            vector<string> agc;
            for(const auto & i : rawAgc)
            {
                agc.push_back(i.asString());
            }
            // 分段接收每一段的数据
            int flightNum = value.get("M", 0).asInt();
            Json::Value rawDate = value.get("date", 0);
            Json::Value rawsCity = value.get("sCity", 0);
            Json::Value rawdCity = value.get("dCity", 0);
            vector<FlightRequest> flightReq;
            for(int i = 0; i<flightNum; i++)
            {
                Time t{};
                t.string2time(rawDate[i].asString());
                FlightRequest a(t, rawsCity[i].asString(), rawdCity[i].asString(), agc, passNum, 20);
                flightReq.push_back(a);
            }
            // 获取结果
            vector<FlightAns> ans = SET->request(flightReq);
            cout << ans.size() << endl;
            Json::Value res_value;
            Json::Value res_data;
            Json::Value res_meta;

            if(!ans.empty())
            {
                res_meta["msg"] = "获取成功";
                res_meta["status"] = 200;
                res_data["ansNum"] = (int)ans.size();
                for(int i = 0; i<ans.size(); i++)
                {
                    Json::Value res_ans;
                    res_ans["ticketPrice"] = ans[i].Return_ticketPrice();
                    vector<string> res_agc = ans[i].Return_agc();
                    vector<AnsElement> res_flight = ans[i].Return_flight();
                    for(int j = 0; j<res_agc.size(); j++)
                    {
                        res_ans["agc"][j] = res_agc[j];
                    }
                    for(int j = 0; j<res_flight.size(); j++)
                    {
                        Json::Value res_flight_ans;
                        res_flight_ans["flightNo"] = res_flight[j].Return_flightNo();
                        vector<string> rawAgc = res_flight[j].Return_agc();
                        for(int k = 0; k<rawAgc.size(); k++)
                            res_flight_ans["agc"][k] = rawAgc[k];
                        res_flight_ans["takeOffTime"] = res_flight[j].Return_takeOffTime();
                        res_flight_ans["arriveTime"] = res_flight[j].Return_arrivalTime();
                        res_flight_ans["sCity"] = res_flight[j].Return_sCity();
                        res_flight_ans["dCity"] = res_flight[j].Return_dCity();
                        res_flight_ans["seatF"] = res_flight[j].Return_seatF();
                        res_flight_ans["seatC"] = res_flight[j].Return_seatC();
                        res_flight_ans["seatY"] = res_flight[j].Return_seatY();
                        char *rawSeat = res_flight[j].Return_passenger_seatList();
                        string passengerSeatList;
                        for(int k = 0; k<8 && rawSeat[k] != 0; k++)
                        {
                            passengerSeatList += rawSeat[k];
                        }
                        res_flight_ans["passengetSeatList"] = passengerSeatList;
                        res_flight_ans["price"] = res_flight[j].Return_price();
                        res_ans["flight"][j] = res_flight_ans;
                    }
                    res_data["ans"][i] = res_ans;
                }
            }
            else
            {
                res_meta["msg"] = "未获取到符合条件的航班";
                res_meta["status"] = 400;
            }
            res_value["meta"] = res_meta;
            res_value["data"] = res_data;
            Json::StreamWriterBuilder builder;
            const string res_body = Json::writeString(builder, res_value);
            res.set_content(res_body, "text/plain");
        });
        svr.Get("/api/reset", [&](const httplib::Request &req, httplib::Response &res)
        {
            RST->update();
            Json::Value value;
            value["msg"] = "重置成功";
            value["status"] = 200;
            Json::StreamWriterBuilder builder;
            const string res_body = Json::writeString(builder, value);
        });

        svr.listen(ip_addr.c_str(), port);
}
