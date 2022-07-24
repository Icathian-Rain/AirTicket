//
// Created by sszg on 22-4-20.
//

#include "RemainingSeat.h"
RemainingSeat::RemainingSeat(vector<string> record) {
    carrier = record[0];
    flightNo = record[1];
    Time tmp{};
    tmp.string2time(record[4]);
    depatureDate = tmp;
    tmp.string2time(record[5]);
    arrivalDate = tmp;
    seatF = record[6][0];
    //调整了seatC、seatY的读取顺序
    seatC = record[7][0];
    seatY = record[8][0];
    sCity = record[2];
    dCity = record[3];
}