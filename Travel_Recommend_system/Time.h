//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_TIME_H
#define TRAVEL_RECOMMEND_SYSTEM_TIME_H


class Time{             //时间
public:
    int year;
    char month;
    char day;
    char hour;
    char minute;
    Time(int y,char m,char d,char h,char min){year=y,month=m,day=d,hour=h,minute=min;};
};


#endif //TRAVEL_RECOMMEND_SYSTEM_TIME_H
