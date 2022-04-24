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

FlightAns Net::request(FlightRequest req){

}

FlightAns Net::multiAgencyRequest(FlightRequest req){

}

FlightAns Net::multiPassengerRequest(FlightRequest req){

}

void Net::update(){

}
