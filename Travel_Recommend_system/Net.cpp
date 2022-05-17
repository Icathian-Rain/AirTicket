//
// Created by sszg on 22-4-20.
//

#include "Net.h"

extern vector<string> mysplit(string str, string separator) {//split string str by separator，like split “a+b+c” by "+" into "a""b""c"
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

bool Net::Set_flightSeats(RemainingSeat st) {
    int index_of_sCity = FindIndex(city[st.Return_sCity()]);
    int index_of_dCity = FindIndex(city[st.Return_dCity()]);
    for(int i = 0; i < matrix[index_of_sCity][index_of_dCity].size(); i++){
        if(matrix[index_of_sCity][index_of_dCity][i].flightNoVal() == st.Return_flightNo()){
            bool ok = matrix[index_of_sCity][index_of_dCity][i].setSeats(st.Return_seatF(),st.Return_seatC(),st.Return_seatY());
            if(!ok) cout<<"error!"<<endl;
            return true;
        }
    }
    cout<<"flignt not found!"<<endl;
    return false;
}

vector<Flight> Net::request(FlightRequest req, string target_agency){
    vector<Flight> res;             //result
    string sCity = req.Return_sCity();
    string dCity = req.Return_dCity();
    //string target_agency = req.Return_agency()[0];  //该功能指定一个代理人
    int s = FindIndex(sCity);
    int d = FindIndex(dCity);   //定位
    for(int i =0; i < matrix[s][d].size(); i++){
        //ReamainingSeat暂时
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
