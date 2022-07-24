//
// Created by sszg on 22-4-20.
//

#include "FlightSet.h"

#include <utility>

//西藏拉萨

void FlightSet::initSet(const vector<string>& CityName, string t, int future_days) {//初始化Set，输入城市节点信息，当天日期t和未来航班天数future_days
    today.string2time(std::move(t));
    Time temp = today;
    future_day=future_days;
    for (int i = 0;i < future_days;i++) {//
        Net net;
        temp.tomorrow();
        net.initNet(CityName, temp);
        flightSet.push_back(net);
    }
}

void FlightSet::createSet(FILE *fp){
    char buffer[200];
    string flightNo,sCity,dCity,carrier,tT,aT;
    while (fgets(buffer, 200, fp) != nullptr) {
        vector<string> str = mysplit(buffer, ";");
        if(str.size()!=7){
            cout<<"flight.txt pattern error!"<<endl;
            continue;
        }
        carrier = str[0];
        flightNo = str[1];
        tT = str[2];
        aT = str[3];
        sCity = str[4];
        dCity = str[5];
        Time tTime,aTime{};
        tTime.string2time(tT);
        aTime.string2time(aT);
        if(Time::compare_Time(today,tTime)){
            cout<<"flight date error!"<<endl;
            continue;
        }

        int index=today.timeInterval(tTime);
        if(index>future_day){
            cout<<"future day out!"<<endl;
            continue;
        }
        flightSet[index].addFlight(sCity,dCity,flightNo,carrier,tTime,aTime);
    }
}

//堆模拟辅助结构
struct asdf{
    int val{};        //当前航班总票价
    int x{},y{};        //当前位置
    int pos[10] = {0,0,0,0,0,0,0,0,0,0};    //初始每一组均取第一个元素，即为最小
    bool p{};         //判断是否满足扩展条件
    asdf()= default;
    asdf(int vall,int xe,int yo,bool pp){val=vall;x=xe;y=yo;p=pp;}  //快捷构造
    bool operator <(const asdf &b)const{return val>b.val;}          //小于号重载
};
//行程推荐算法优化：堆模拟搜索算法-->O(MNlogN)
//多旅客、多代理人
vector<FlightAns> FlightSet::request(vector<FlightRequest> req) {           //低价行程推荐
    vector<FlightAns> ans;          //存放推荐结果
    int req_size = req.size();      //航段请求数量
    if(req_size <= 0 || req_size > 8) {
        cout<<"Request size is error!"<<endl;
        return ans;
    }
    vector<string> target_agc = req[0].Return_agency();
    if(target_agc.empty()) {
        cout<<"Target agency is empty!"<<endl;
        return ans;
    }
    vector<AnsElement> tmp[req_size];       //暂存每一段航班的搜索结果
    bool ok = true;                 //查询成功/失败，如果某一段查询不到航班，则查询失败

    pair<int,int> head[10];
    priority_queue<asdf>q;          //小根堆
    int cnt = 0;                    //目前得到的满足条件的结果数
    int tot = 0;
    for(int i = 0; i < req_size; i++){
        int d = getDir(req[i]);     //date_index日期索引
        if( d < 0 || d >= flightSet.size()){
            cout<<"The date is error!"<<endl;
            ok = false;
            break;
        }
        tmp[i] = flightSet[d].request(req[i]);  //调用当天的Net搜索满足条件的所有航班
        if(tmp[i].empty()){
            cout<<"第"<<i+1<<"航段查询不到航班!"<<endl;
            ok = false;     //记录查询结果为失败
            break;
        }
        sort(tmp[i].begin(),tmp[i].end(),AnsElement::comparePrice);     //按照价格从低到高排序-->O(MNlogN)
        if(tmp[i].size() <= 1) head[i]= pair<int,int>(0,i);
        else head[i]= pair<int,int>( tmp[i][1].Return_price() - tmp[i][0].Return_price(),i);
        tot = tot + tmp[i][0].Return_price();         //记录最小值
    }
    if(ok){             //查询成功
        sort(head, head+req_size);      //按照(次小-最小的值)给每一组排序
        q.push(asdf(tot,0,0,false));
        while(cnt <20 && !q.empty()){
            asdf np = q.top();
            q.pop();
            //根据输出构造一个FligntAns
            FlightAns tmp_ans;
            for(int i = 0; i < req_size; i++){
                tmp_ans.Add(tmp[i][np.pos[i]]);
            }
            //判断是否满足衔接条件
            if(tmp_ans.Connect_ok()){
                //判断是否存在公共代理商
                if(tmp_ans.GetCommon_agc()){
                    ans.push_back(tmp_ans);
                    cnt++;
                }
            }
            if(np.y+1<tmp[head[np.x].second].size()) {
                asdf tmp_asdf = np;
                tmp_asdf.val = np.val - tmp[head[np.x].second][np.y].Return_price() + tmp[head[np.x].second][np.y+1].Return_price();
                tmp_asdf.x = np.x;
                tmp_asdf.y = np.y +1;
                tmp_asdf.p = false;
                tmp_asdf.pos[head[np.x].second] = np.y+1;
                q.push(tmp_asdf);
            }
            if(np.x+1<req_size && tmp[head[np.x+1].second].size() > 1){
                asdf tmp_asdf = np;
                tmp_asdf.val = np.val - tmp[head[np.x+1].second][0].Return_price() + tmp[head[np.x+1].second][1].Return_price();
                tmp_asdf.x = np.x + 1;
                tmp_asdf.y = 1;
                tmp_asdf.p = true;
                tmp_asdf.pos[head[np.x+1].second] = 1;
                q.push(tmp_asdf);
            }
            if(np.x+1<req_size && np.p && tmp[head[np.x+1].second].size() > 1){
                asdf tmp_asdf = np;
                tmp_asdf.val = np.val - tmp[head[np.x].second][np.y].Return_price() + tmp[head[np.x].second][0].Return_price() - tmp[head[np.x+1].second][0].Return_price() + tmp[head[np.x+1].second][1].Return_price();
                tmp_asdf.x = np.x + 1;
                tmp_asdf.y = 1;
                tmp_asdf.p = true;
                tmp_asdf.pos[head[np.x].second] = 0;
                tmp_asdf.pos[head[np.x+1].second] = 1;
                q.push(tmp_asdf);
            }
        }
        return ans;
    }
    else return ans;        //返回空响应
}


struct cmp{             //FlightAns 总票价越高，优先级越高
    bool operator()(FlightAns &a1, FlightAns &a2){
        return a1.Return_ticketPrice() > a2.Return_ticketPrice();
    }
};
