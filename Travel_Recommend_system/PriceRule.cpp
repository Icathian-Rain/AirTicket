//
// Created by sszg on 22-4-20.
//

#include "PriceRule.h"
void PriceRule::setRule(int seq,string car,string sC,string dC,string next,string agen,const string& surch){
    sequenceNo=seq,carrier=std::move(car),sCity=std::move(sC),dCity=std::move(dC),nextCarrier=std::move(next);
    if(agen!=" "){
        int cutAt;
        while( (cutAt = agen.find_first_of(',')) != std::string::npos ){
            if(cutAt > 0)
                agency.push_back(agen.substr(0, cutAt));
            agen = agen.substr(cutAt + 1);
        }
        if(agen.length() > 0)
            agency.push_back(agen);
    }
    surcharge=stoi(surch,nullptr,10);
}