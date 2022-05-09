//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_TIME_H
#define TRAVEL_RECOMMEND_SYSTEM_TIME_H
#include <iostream>
#include "string.h"
using namespace std;
class Time{             //时间
public:
    int year;
    char month;             
    char day;
    char hour;
    char minute;
    Time T(int y, int m, int d, int h, int min) { year = y, month = m, day = d, hour = h, minute = min; };
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
    int timeInterval(Time t) {//output |t-(this->time)|
        int C=0;
        int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(t.year-year==0){
            if((year%4==0&&year%100!=0)||(year%400==0))
                m[2]=29;
            for(int i=month;i<t.month;i++){
                if(i==month)
                    C=m[i]-day;
                else
                    C+=m[i];
            }
            C+=t.day;
            if(t.month==month)C=t.day-day;
            return C>0?C:-C;
        }
        else{
            for(int i=year;i<t.year;i++){
                if(i%4==0&&i%100!=0||i%400==0) C+=366;
                else C+=365;
            }
            if(year%4==0&&year%100!=0||year%400==0) m[2]=29;
            for(int i=1;i<month;i++) C-=m[i];
            C-=day;
            if(t.year%4==0&&t.year%100!=0||t.year%400==0) m[2]=29;
            else m[2]=28;
            for(int i=1;i<t.month;i++)C+=m[i];
            C+=t.day;
            return C>0?C:-C;
        }
        return 0;
    }
    void string2time(string str) {//input like 20220503000000
        string temp;
        year = atoi(temp.assign(str,0,4).c_str());
        month = atoi(temp.assign(str,4,2).c_str());
        day = atoi(temp.assign(str,6,2).c_str());
        hour = atoi(temp.assign(str,8,2).c_str());
        minute = atoi(temp.assign(str,10,2).c_str());
    }
    void tomorrow() {//add one day
        day++;
        if(day>31){
            day = 1;
            month++;
            if(month>12){
                month = 1;
                year++;
            }
        }
    }
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
        if(t1.year < t2.year) return true;
        if(t1.year > t2.year) return false;
        //同一年
        int daydiff = t2.day2int() - t1.day2int();        //求两个时间相差的天数
        if(daydiff < 0) return false;
        if(daydiff >=2) return true;
        t2.hour += 24*daydiff;
        if(t2.hour - t1.hour < 2) return false;
        else if(t2.hour - t1.hour == 2) {
            if (t2.minute > t1.minute) return true;
            else return false;
        }
        return true;
    };
    static bool compare_Time(Time t1, Time t2){             //判断t1>t2,  用于按照时间降序排序
        bool ok = false;
        if(t1.year > t2.year) ok= true;
        else if(t1.year == t2.year){
            if(t1.month > t2.month) ok= true;
            else if(t1.month == t2.month){
                if(t1.day > t2.day) ok= true;
                else if (t1.day == t2.day){
                    if(t1.hour > t2.hour) ok= true;
                    else if(t1.hour == t2.hour){
                        if(t1.minute > t2.minute) ok= true;
                    }
                }
            }
        }
        return ok;
    };
};


#endif //TRAVEL_RECOMMEND_SYSTEM_TIME_H
