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
    char month;             
    char day;
    char hour;
    char minute;
    //Time(int y,char m,char d,char h,char min){year=y,month=m,day=d,hour=h,minute=min;};
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
    void showTime(){
        cout<<year<<"-"<<int(month)<<"-"<<int(day)<<" "<<int(hour)<<":"<<int(minute)<<endl;
    };
    static bool Date_equal(Time t1, Time t2){              //判断日期是否相同
        if(t1.year != t2.year) return false;
        if(t1.month!= t2.month) return false;
        if(t1.day != t2.day) return false;
        return true;
    };
    static bool connect_ok(Time t1, Time t2){             //判断t1->t2是否满足大于120分钟的衔接要求
        //t1,t2首先已经是同一天的了
        if(t2.hour - t1.hour < 2) return false;
        else if(t2.hour - t1.hour == 2) {
            if (t2.minute > t1.minute) return false;
            else return true;
        }
    }
};


#endif //TRAVEL_RECOMMEND_SYSTEM_TIME_H
