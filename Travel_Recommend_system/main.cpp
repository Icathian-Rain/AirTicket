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
#include "FluctuationTable.h"
#include <vector>
#include <string>
#include <unistd.h>
FlightSet *SET;
PriceRuleTable *PRT;
PriceTable *PT;
RemainSeatTable *RST;
FluctuationTable *FT;
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif defined(_MSC_VER)
#pragma warning(disable : 4996)
#endif



int initialize();

void srv_setup(const char *, int);

int main() {
    srand((int)time(0));
    //gathering data info
    if(initialize()==-1){
        return -1;
    }
    srv_setup("0.0.0.0", 8080);
    return 0;
}

int initialize(){
    SET =new FlightSet;
    PRT =new PriceRuleTable;
    PT =new PriceTable;
    RST =new RemainSeatTable;
    FT = new FluctuationTable;
    vector<string> cityName={"AQG", "AOG", "AVA", "AEB", "BSD", "BAV", "BHY", "PEK", "BFU", "CGQ", "CGD", "CSX", "CZX", "CTU", "CIF", "CKG", "DLU", "DLC", "DNH", "ENH", "FUO", "FUG", "HMI", "HGH", "HZG", "HFE", "HEK", "HNY", "TXN", "HET", "HUZ", "JMU", "KNC", "JGN", "JIL", "TNA", "JDZ", "JNG", "JNZ", "JIU", "CHW", "JZH", "KHG", "KRY", "KRL", "KMG", "LHW", "LXA", "LYG", "LJG", "LYI", "LHN", "LZH",
                             "LYA", "LUZ", "LZO", "LUM", "NZH", "MIG", "MDG", "KHN", "NAO", "NKG", "NNG", "NTG", "NNY", "NGB", "PZI", "TAO", "IQN", "SHP", "NDG", "JUZ", "SYX", "SHA", "PVG", "SWA", "SHS", "SHE", "SZX",
                             "SJW", "SZV", "TYN", "TSN", "TNH", "TGO", "TEN", "WEF", "WEH", "WNZ", "WUH", "WHU", "HLH", "URC", "WUX", "WUS", "WUZ", "XMN", "XIY", "SIA", "XIC", "XIL", "XNN", "XUZ", "ENY", "YNZ", "YNT", "YBP", "YIH", "YIN", "YIW", "LLF", "DYG", "ZHA", "ZAT", "CGO", "HJJ", "ZUH", "ZYI"};
    //'SHS','XIC','WUX','SHE','NNG','DNH','SZX','AOG','XUZ','CGQ'
    vector<string> All_Agency = {"SHS","XIC","WUX","SHE","NNG","DNH","SZX","AOG","XUZ","CGQ"};
    //fluctuation init
    FT->init_fluctuation(All_Agency);

    //SET init
    SET->initSet(cityName, "20220901000000", 370);
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
    //close 并释放文件指针和有关缓冲区
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    cout << "Down" << endl;
    return 1;
}

/**
 * @brief http服务器启动
 * 
 * @param ip_addr 监听的ip地址
 * @param port 端口
 */

void srv_setup(const char * ip_addr, int port)
{
        // 初始化svr
        httplib::HttpServer srv(ip_addr, port);
        // read:读取json
        Json::Reader read;
        srv.Post("/api/query", [&](httplib::HttpRequest &req, httplib::HttpResponse &res)
        {
            // 获取request的数据
            string req_data = req.get_body();
            Json::Value value;
            read.parse(req_data, value);
            // 获取乘客人数
            char passNum = value.get("N", 0).asInt();
            // 获取最大结果数
            int maxAnsnum = value.get("Max", 0).asInt();
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
                FlightRequest a(t, rawsCity[i].asString(), rawdCity[i].asString(), agc, passNum);
                flightReq.push_back(a);
            }
            // 获取结果
            vector<FlightAns> ans = SET->request(flightReq, maxAnsnum);
            Json::Value res_value;
            Json::Value res_data;
            Json::Value res_meta;

            if(!ans.empty())
            {
                res_meta["msg"] = "query succeed";
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
                        res_flight_ans["flightNo"] = res_flight[j].carrierVal() + res_flight[j].Return_flightNo();
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
                res_meta["msg"] = "Not Found";
                res_meta["status"] = 404;
            }
            res_value["meta"] = res_meta;
            res_value["data"] = res_data;
            Json::StreamWriterBuilder builder;
            const string res_body = Json::writeString(builder, res_value);
            res.set_body(res_body, "text/plain");
        });
        srv.Get("/api/update", [&](httplib::HttpRequest &req, httplib::HttpResponse &res)
        {
            string updateFile=req.get_param("fileName");
            Json::Value value;
            if(RST->update(updateFile) == true) {
                value["msg"] = "update succeed";
                value["status"] = 200;
            }
            else {
                value["msg"] = "update failed";
                value["status"] = 404;
            }
            Json::StreamWriterBuilder builder;
            const string res_body = Json::writeString(builder, value);
            res.set_body(res_body, "text/plain");
        });
        srv.run();
}
