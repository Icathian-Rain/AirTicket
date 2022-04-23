//
// Created by sszg on 22-4-20.
//

#include "FlightSet.h"


vector<FlightAns> FlightSet::request(vector<FlightRequest> req) {

    int req_size = req.size();      //航班联程数量
    vector<Flight> tmp[req_size];
    //剪枝：抵达城市、出票代理人、航班余座
    for(int i = 0; i < req.size(); i++){
        Time time = req[i].timeVal();                  //日期
        string sCity = req[i].Return_sCity();          //起止城市
        string dCity = req[i].Return_dCity();
        string agency = req[i].Return_agency()[0];        //代理人
        int d = getDir(req[i]);     //date_index日期索引
        int s = City_index[sCity];      //sCity_index起飞city
        for(int j=0; j < flightSet[d][s].size(); j++)
        {
            //dCity
            if(dCity != flightSet[d][s][j].dCityVal()) continue;
            //余座暂时略
            //agency
            vector<string> agc = flightSet[d][s][j].rule.Return_agency();
            bool ok = false;
            for(int k=0; k < agc.size(); k++)
            {
                if(agency == agc[k]){
                    ok = true;
                    break;
                }
            }
            if(!ok) continue;
            //insert
            tmp[i].push_back(flightSet[d][s][j]);
        }
        sort(tmp[i].begin(), tmp[i].end(), Flight::comparePrice);       //快排，按照票价升序
    }

    //打算用贪心，已经将每一段的航班按照票价排序了
    //困难在于每一个结果都要满足时间要求，即航班之间衔接要大于120分钟
}