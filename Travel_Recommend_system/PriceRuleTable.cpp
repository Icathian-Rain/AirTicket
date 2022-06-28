//
// Created by sszg on 22-5-16.
//

#include "PriceRuleTable.h"

#include <utility>
void PriceRuleTable::createTable(FILE *fp){
    char buffer[200];
    vector <string> temp;
    map <string, int> city_index;
    int i=0,cnt=0;
    string carrier("START"),city("START");
    for (;fgets(buffer, 200, fp) != nullptr;i++) {
        string info(buffer);
        int cutAt;
        temp.clear();
        while( (cutAt = info.find_first_of(";")) != std::string::npos ){
            if(cutAt > 0)
                temp.push_back(info.substr(0, cutAt));
            info = info.substr(cutAt + 1);
        }
        //建立索引
        if(temp[1]!=carrier){
            if(i!=0)
                cityIndex.push_back(city_index);
            carrierIndex[temp[1]]=cnt++;
            carrier=temp[1];
            city_index.clear();
        }
        if(temp[2]!=city){
            city_index[temp[2]]=i;
            city=temp[2];
        }
        PriceRule pr;
        pr.setRule(atoi(buffer),temp[1],temp[2],temp[3],temp[4],temp[5],temp[6]);
        Table.push_back(pr);
    }
    cityIndex.push_back(city_index);
}

void PriceRuleTable::showCityIndex(){
    for(const auto& a:carrierIndex) {
        cout<<"..............."<<a.first<<"................."<<endl;
        for (const auto& c: cityIndex[a.second]) {
            cout << c.first << ":" << c.second << endl;
        }
    }
}

int PriceRuleTable::find(const string& carrier,const string& sCity,const string& dCity){
    if(carrierIndex.find(carrier)==carrierIndex.end()){
        return -1;
    }
    int carrier_index=carrierIndex[carrier];
    if(cityIndex[carrier_index].find(sCity)==cityIndex[carrier_index].end()||cityIndex[carrier_index].find(dCity)==cityIndex[carrier_index].end()){
        return -1;
    }
    int city_index=cityIndex[carrier_index][sCity];
    for(int i=city_index;i<Table.size()&&Table[i].Return_sCity()==sCity;i++){
        if(Table[i].Return_dCity()==dCity) {
            return i;
        }
    }
    for(int i=cityIndex[carrier_index][dCity];i<Table.size()&&Table[i].Return_sCity()==dCity;i++){
        if(Table[i].Return_dCity()==sCity) {
            return i;
        }
    }
}
vector<string> PriceRuleTable::findAgency(const string& carrier,const string& sCity,const string& dCity){
    int index=find(carrier,sCity,dCity);
    if(index==-1){
        return {};
    }
    vector<string> agencies=Table[index].Return_agency();
    return agencies;
}

void PriceRuleTable::show(const string& carrier,const string& sCity,const string& dCity){
    vector<string> agencies=findAgency(carrier,sCity,dCity);
    if(agencies.empty()){
        cout<<"Not find carrier!!"<<endl;
    }
    for(auto & agencies : agencies){
        cout<<agencies<<' ';
    }
    cout<<endl;
}

int PriceRuleTable::findSurcharge(const string& carrier,const string& sCity,const string& dCity){
    int index=find(carrier,sCity,dCity);
    if(index==-1){
        return -2;
    }
    return Table[index].Return_surcharge();
}

void PriceRuleTable::showSurcharge(const string& carrier,const string& sCity,const string& dCity){
    int price=findSurcharge(carrier,sCity,dCity);
    if(price==-2){
        cout<<"not find price!"<<endl;
    }
    cout<<"price:"<<price<<endl;
}
