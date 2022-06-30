//
// Created by sszg on 22-4-20.
//

#include "Time.h"

void Time::string2time(const string& str) {//input like 20220503000000
    string temp;
    year = atoi(temp.assign(str,0,4).c_str());
    month = atoi(temp.assign(str,4,2).c_str());
    day = atoi(temp.assign(str,6,2).c_str());
    hour = atoi(temp.assign(str,8,2).c_str());
    minute = atoi(temp.assign(str,10,2).c_str());
}

void Time::tomorrow() {//add one day
    day++;
    int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear())
        month_day[1] = 29;
    if(day>month_day[month]){
        day = 1;
        month++;
        if(month>12){
            month = 1;
            year++;
        }
    }
}

void Time::showTime() const {
    cout<<year<<"-"<<int(month)<<"-"<<int(day)<<" "<<int(hour)<<":"<<int(minute)<<endl;
}

string Time::time2string_forday() const{
    string temp;
    temp += to_string(year);
    if(month < 10) temp += "0";
    temp += to_string(month);
    if(day < 10) temp += "0";
    temp += to_string(day);
    if(hour < 10) temp += "0";
    temp += to_string(hour);
    if(minute < 10) temp += "0";
    temp += to_string(minute);
    temp += "00";
    return temp;
}

int Time::day2int() const {
    //輸入日期，返回在這一年中的第幾天
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
}

int Time::timeInterval(Time t) const {
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