//
// Created by sszg on 22-4-20.
//

#include "FlightAns.h"

//获取信息
vector<Flight> FlightAns::Return_flight() {
    return flight;
}

string FlightAns::Return_agency() {
    return agency;
}

int FlightAns::Return_ticketPrice() {
    return ticketPrice;
}

bool FlightAns::Return_status() {
    return status;
}


void FlightAns::Add(SameDayFlight sdf, string target_agency) {
    if(agency == target_agency || agency.length()==0) agency = target_agency;
    else return;            //二次检验代理人是否一致
    vector<Flight> new_flight = sdf.Return_all_flight();
    for( int i = 0; i < new_flight.size(); i++){    //存入航班，记录总票价
        flight.push_back(new_flight[i]);
        ticketPrice += new_flight[i].Return_price();
    }
}

void FlightAns::Virtual_FlightAns() {
    ticketPrice = 1e9;      //票价设置为大值
    status = false;         //状态设置为虚拟
}

