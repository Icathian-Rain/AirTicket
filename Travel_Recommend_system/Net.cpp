//
// Created by sszg on 22-4-20.
//

#include "Net.h"

extern vector<string> mysplit(string str, string separator) {
    vector<string> result;
    int cutAt;
    while( (cutAt = str.find_first_of(separator)) != str.npos ){
        if(cutAt > 0)
        {
            result.push_back(str.substr(0, cutAt));
        }
        str = str.substr(cutAt + 1);
    }
    if(str.length() > 0){
        result.push_back(str);
    }
    return result;
}

vector<Flight> Net::request(FlightRequest req){
    vector<Flight> res;             //result
    string sCity = req.Return_sCity();
    string dCity = req.Return_dCity();
    string target_agency = req.Return_agency()[0];  //该功能指定一个代理人
    int s = FindIndex(sCity);
    int d = FindIndex(dCity);   //定位
    for(int i =0; i < matrix[s][d].size(); i++){
        //ReamainingSeat暂时略
        //agency
        vector<string> agc = matrix[s][d][i].rule.Return_agency();
        bool ok = false;
        for(int j = 0; j < agc.size(); j++){
            if(agc[j] == target_agency) {
                ok = true;
                break;
            }
        }
        if(!ok) continue;
        //满足,存入res
        res.push_back(matrix[s][d][i]);
    }
    //sort(res.begin(),res.end(),Flight::comparePrice);       //按照票价升序排序
    //不进行排序，节省一些时间
    return res;
}

FlightAns Net::multiAgencyRequest(FlightRequest req){

}

FlightAns Net::multiPassengerRequest(FlightRequest req){

}

void Net::update(){

}
