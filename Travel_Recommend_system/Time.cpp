//
// Created by sszg on 22-4-20.
//

#include "Time.h"

void Time::showTime() {
    cout<<year<<"-"<<int(month)<<"-"<<int(day)<<" "<<int(hour)<<":"<<int(minute)<<endl;
}

int Time::day2int() {
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

int Time::timeInterval(Time t) {
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