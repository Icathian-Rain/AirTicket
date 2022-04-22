//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_TIME_H
#define TRAVEL_RECOMMEND_SYSTEM_TIME_H
#include <iostream>
using namespace std;
class Time{             //时间
public:
    int year;
    char month;             //why?
    char day;
    char hour;
    char minute;
    Time(int y,char m,char d,char h,char min){year=y,month=m,day=d,hour=h,minute=min;};
    int day2int(){//輸入日期，返回在這一年中的第幾天
        int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(year%4==0){          //闰年
            if(year%100==0 && year%400!=0);
            else days[1] = 29;
        }
        if(month>12||day>days[month-1]){
            cout<<"date error!"<<endl;
            return 0;
        }
        int sum = 0;
        for(int i=0;i<month-1;i++)
            sum+=days[i];
        sum+=day;
        return sum;
    };
};


#endif //TRAVEL_RECOMMEND_SYSTEM_TIME_H
