//
// Created by sszg on 22-5-16.
//

#include "PriceRuleTable.h"
void PriceRuleTable::createTable(FILE *fp){
    char buffer[200];
    vector <string> temp;
    map <string, int> city_index;
    int i=0,cnt=0;
    string carrier("START"),city("START");
    for (;fgets(buffer, 200, fp) != NULL;i++) {
        string info(buffer);
        int cutAt;
        temp.clear();
        while( (cutAt = info.find_first_of(";")) != info.npos ){
            if(cutAt > 0)
                temp.push_back(info.substr(0, cutAt));
            info = info.substr(cutAt + 1);
        }
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
    for(auto a:carrierIndex) {
        cout<<"..............."<<a.first<<"................."<<endl;
        for (auto c: cityIndex[a.second]) {
            cout << c.first << ":" << c.second << endl;
        }
    }
}

int PriceRuleTable::find(string carrier,string sCity,string dCity){
    if(carrierIndex.find(carrier)==carrierIndex.end()){
        cout<<"Not find carrier!!"<<endl;
        return -1;
    }
    int carrier_index=carrierIndex[carrier];
    if(cityIndex[carrier_index].find(sCity)==cityIndex[carrier_index].end()||cityIndex[carrier_index].find(dCity)==cityIndex[carrier_index].end()){
        cout<<"Not find city!!"<<endl;
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
vector<string> PriceRuleTable::findAgency(string carrier,string sCity,string dCity){
    int index=find(carrier,sCity,dCity);
    vector<string> agencies=Table[index].Return_agency();
    for(int i=0;i<agencies.size();i++){
        cout<<agencies[i]<<' ';
    }
    cout<<endl<<endl;
    return agencies;
}

int PriceRuleTable::findSurcharge(string carrier,string sCity,string dCity){
    int index=find(carrier,sCity,dCity);
    cout<<Table[index].Return_surcharge()<<endl<<endl;
    return Table[index].Return_surcharge();
}
