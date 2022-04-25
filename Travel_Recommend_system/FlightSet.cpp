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