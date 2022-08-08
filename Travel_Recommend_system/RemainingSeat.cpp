//
// Created by sszg on 22-4-20.
//

#include "RemainingSeat.h"
RemainingSeat::RemainingSeat(const RemainingSeat &rst) {
    carrier = rst.carrier;
    flightNo = rst.flightNo;
    depatureDate = rst.depatureDate;
    char F = rst.seatF.load(memory_order_relaxed);
    char C = rst.seatC.load(memory_order_relaxed);
    char Y = rst.seatY.load(memory_order_relaxed);
    seatF.store(F,memory_order_relaxed);
    seatC.store(C,memory_order_relaxed);
    seatY.store(Y,memory_order_relaxed);
}
RemainingSeat::RemainingSeat(vector<string> record) {
    carrier = record[0];
    flightNo = record[1];
    Time tmp{};
    tmp.string2time(record[4]);
    depatureDate = tmp;
    //tmp.string2time(record[5]);
    //arrivalDate = tmp;

    seatF.store(record[6][0],std::memory_order_relaxed);        //不要求顺序执行，只保证原子性
    seatC.store(record[7][0],std::memory_order_relaxed);
    seatY.store(record[8][0],std::memory_order_relaxed);
    //调整了seatC、seatY的读取顺序
//    seatF = record[6][0];
//    seatC = record[7][0];
//    seatY = record[8][0];
    //sCity = record[2];
    //dCity = record[3];
}