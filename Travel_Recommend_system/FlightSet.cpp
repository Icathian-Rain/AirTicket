//
// Created by sszg on 22-4-20.
//

#include "FlightSet.h"
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
            vector<SameDayFlight> newSection;
            for (int j = 0; j < allowed_combinations[index].size(); j++) {
                for (int k = 0; k < tmp[i].size(); k++) {
                    if (Time::connect_ok(allowed_combinations[index][j].arriveTime, tmp[i][k].takeOffTimeVal())) {
                        //如果满足衔接要求
                        SameDayFlight element = allowed_combinations[index][j];     //copy
                        element.push_back(tmp[i][k]);
                        newSection.push_back(element);
                    }
                }
            }
            sort(newSection.begin(), newSection.end(), SameDayFlight::comparePrice);  //按价格升序排序
            //sort by price
            //删掉原来的，加入组合之后的
            allowed_combinations.pop_back();
            allowed_combinations.push_back(newSection);

        } else {       //如果不在同一天，直接按照价格升序
            vector<SameDayFlight> section;
            for (int j = 0; j < tmp[i].size(); j++) {
                SameDayFlight p;
                p.push_back(tmp[i][j]);
                section.push_back(p);
            }
            allowed_combinations.push_back(section);
        }
    }
    //归并排序？得到20个结果


        /*string sCity = req[i].Return_sCity();          //起止城市
        string dCity = req[i].Return_dCity();
        string agency = req[i].Return_agency()[0];        //代理人
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
        }*/
        //sort(tmp[i].begin(), tmp[i].end(), Flight::comparePrice);       //快排，按照票价升序

}