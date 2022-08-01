//
// Created by sszg on 22-4-20.
//

#ifndef TRAVEL_RECOMMEND_SYSTEM_TIME_H
#define TRAVEL_RECOMMEND_SYSTEM_TIME_H
#include <iostream>
#include <cstring>
using namespace std;
class Time{             //时间
public:
    int year;
    char month;
    char day;
    char hour;
    char minute;
    inline Time T(int y, int m, int d, int h, int min) { year = y, month = m, day = d, hour = h, minute = min; };
    int day2int() const;          //不考虑年份的情况
    int timeInterval(Time t) const;
    inline bool isLeapYear(){return (year % 4 == 0 && year % 100 !=0 )||year % 400 == 0;}
    void string2time(const string& str);//input like 20220503000000
    //日期转到字符串,转来转去很麻烦，之后对余座数据表进行修改
    void showTime() const;
    string time2string_forday() const;
    void tomorrow(); //add one day
    static bool Date_equal(Time t1, Time t2){              //判断日期是否相同
        if(t1.year != t2.year) return false;
        if(t1.month!= t2.month) return false;
        if(t1.day != t2.day) return false;
        return true;
    };
    static bool connect_ok(Time t1, Time t2){             //判断t1->t2是否满足大于120分钟的衔接要求
//        if(t1.year < t2.year) return true;
        if(t1.year > t2.year || (t1.year == t2.year && t1.day2int() > t2.day2int())) return false;
        //同一年
        int daydiff = t1.timeInterval(t2);        //求两个时间相差的天数
        if(daydiff >=2) return true;
        t2.hour += 24*daydiff;                          //调用了拷贝构造函数，不会对原时间造成影响
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
    bool operator>(const Time &t)const{         //data compare
        if(this->year>t.year){
            return this->year>t.year;
        }
        if(this->month>t.month){
            return this->month>t.month;
        }
        if(this->day>t.day){
            return this->day>t.day;
        }
        if(this->hour>t.hour){
            return this->hour>t.hour;
        }
        if(this->minute>t.minute){
            return this->minute>t.minute;
        }
        return false;
    };

    bool operator<(const Time &t) const{
        return t>*this;
    }

    bool operator==(const Time &t) const{
        return this->year==t.year&&this->day==t.day&&this->month==t.month&&this->minute==t.minute&&this->hour==t.hour;
    }


};


#endif //TRAVEL_RECOMMEND_SYSTEM_TIME_H
