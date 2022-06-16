//
// Created by sszg on 22-5-19.
//

#include "PriceTable.h"

void PriceTable::createTable(FILE *fp){
    char buffer[200];
    vector <string> temp;
    string carrier("START"),city("START");
    map <string, int> city_index;
    int i,cnt=0;
    for (i=0;fgets(buffer, 200, fp) != nullptr;i++){
        string info(buffer);
        int cutAt;
        temp.clear();
        while( (cutAt = info.find_first_of(';')) != std::string::npos ){
            if(cutAt > 0)
                temp.push_back(info.substr(0, cutAt));
            info = info.substr(cutAt + 1);
        }
        if(temp[0]!=carrier){
            if(i!=0)
                cityIndex.push_back(city_index);
            carrierIndex[temp[0]]=cnt++;
            carrier=temp[0];
            city_index.clear();
        }
        if(temp[1]!=city){
            city_index[temp[1]]=i;
            city=temp[1];
        }
        Price pr;
        pr.setPrice(temp[0],temp[1],temp[2],stoi(temp[4]),stoi(temp[6]),stoi(temp[8]));
        Table.push_back(pr);
    }
    cityIndex.push_back(city_index);
}

void PriceTable::showCityIndex(){
    for(const auto& a:carrierIndex) {
        cout<<"..............."<<a.first<<"................."<<endl;
        for (const auto& c: cityIndex[a.second]) {
            cout << c.first << ":" << c.second << endl;
        }
    }
}

int * PriceTable::findPrice(const string& carrier,const string& sCity,const string& dCity){
    if(carrierIndex.find(carrier)==carrierIndex.end()){
        return nullptr;
    }
    int carrier_index=carrierIndex[carrier];
    if(cityIndex[carrier_index].find(sCity)==cityIndex[carrier_index].end()||cityIndex[carrier_index].find(dCity)==cityIndex[carrier_index].end()){
        return nullptr;
    }
    int city_index=cityIndex[carrier_index][sCity];
    for(int i=city_index;i<Table.size()&&Table[i].Return_sCity()==sCity;i++){
        if(Table[i].Return_dCity()==dCity) {
            int *price=Table[i].Return_price();
            return price;
        }
    }
    for(int i=cityIndex[carrier_index][dCity];i<Table.size()&&Table[i].Return_sCity()==dCity;i++){
        if(Table[i].Return_dCity()==sCity) {
            int *price=Table[i].Return_price();
            return price;
        }
    }
}

void PriceTable::showPrice(const string& carrier,const string& sCity,const string& dCity){
    int *price = findPrice(carrier,sCity,dCity);
    if(price== nullptr){
        cout<<"Not find city!!"<<endl;
        return ;
    }
    cout << carrier<<' '<<dCity<<"->"<<sCity<<" find!" << endl;
    cout << "F:"<<price[0]<<"\tC:"<<price[1]<<"\tY:"<<price[2]<<endl;
}