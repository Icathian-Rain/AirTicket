//
// Created by sszg on 22-4-20.
//

#include "FlightSet.h"

extern unordered_map<string, int> City_index
({{"HRB",0},{"MDG",1},{"NDG",2},{"JMU",3},     //黑龙江
{"CGQ",4},{"YNJ",5},{"JIL",6},{"NBS",7},                            //吉林
{"SHE",8},{"DDG",9},{"JNZ",10},{"DLC",11},{"CHG",12},               //辽宁
{"TNA",13},{"YNT",14},{"WEF",15},{"TAO",16},{"WEH",17},{"LYI",18},   //山东
{"PEK",19},{"SJW",20},{"TSN",21},{"SHP",22},            //北京、河北
{"CGO",23},{"LYA",24},{"NNY",25},                           //河南
{"WUH",26},{"XFN",27},{"ENH",28},{"YIH",29},{"SHS",30},                     //湖北
{"CSX",31},{"CGD",32},{"LLF",33},{"DYG",34},{"HNY",35},{"JZH",36},              //湖南
{"NKG",37},{"LYG",38},{"SZV",39},{"CZX",40},{"NTG",41},{"YNZ",42},{"XUZ",43},{"WUX",44},{"HSN",45},     //江苏
{"HGH",46},{"NGB",47},{"YIW",48},{"SHA",49},{"HYN",50},{"WNZ",51},{"JUZ",52},           //浙江、上海
{"FOC",53},{"JJN",54},{"LCX",55},{"XMN",56},{"WUS",57},                             //福建
{"TYN",58},                     //山西太原
{"SIA",59},{"UYN",60},{"HZG",61},{"ENY",62},                //陕西
{"CTU",63},{"YBP",64},{"CKG",65},{"GHN",66},{"LZO",67},{"WXN",68},{"MIG",69},{"GYS",70},{"PZI",71},{"XIC",72},  //四川
{"HFE",73},{"AQG",74},{"BFU",75},{"TXN",76},{"FUG",77},     //安徽
{"KHN",78},{"JDZ",79},{"JGS",80},{"JIU",81},{"KOW",82},{"LUZ",83},      //江西
{"KMG",84},{"JHG",85},{"SYM",86},{"DLU",87},{"DIG",88},{"TCZ",89},{"LJG",90},{"LUM",91},     //云南
{"NNG",92},{"BHY",93},{"WUZ",94},{"KWL",95},{"LZH",96},     //广西
{"KWE",97},{"ZYI",98},{"TEN",99},                   //贵州
{"CAN",100},{"ZUH",101},{"YGG",102},{"SZX",103},{"SWA",104},{"FUO",105},{"ZHA",106},{"MXZ",107},    //广东
{"HAK",108},{"SYX",109},        //海南
{"HET",110},{"BAV",111},{"TGO",112},{"CIF",113},{"HLD",114},{"HLH",115},    //内蒙古
{"LHW",116},{"DNH",117},{"JGN",118},        //甘肃
{"URC",119},{"AAT",120},{"KHG",121},{"YIN",122},        //新疆
{"INC",123},        //宁夏
{"XNN",124},{"GOQ",125},        //青海
{"LXA",126}});      //西藏拉萨

void FlightSet::initSet(vector<string> CityName, string t, int future_days) {//初始化Set，输入城市节点信息，当天日期t和未来航班天数future_days
    today.string2time(t);
    today.showTime();
    Time temp = today;
    for (int i = 0;i < future_days;i++) {//
        Net net;
        temp.tomorrow();
        net.initNet(CityName, temp);
        flightSet.push_back(net);
    }
}

void FlightSet::createSet(FILE *fp_flight,FILE *fp_price){
    char buffer[200];
    string flightNo,sCity,dCity,carrier,tT,aT;
    while (fgets(buffer, 200, fp_flight) != NULL) {
        vector<string> str = mysplit(buffer, ";");
        carrier = str[0];
        flightNo = str[1];
        tT = str[2];
        aT = str[3];
        sCity = str[4];
        dCity = str[5];
        Time tTime,aTime;
        tTime.string2time(tT);
        aTime.string2time(aT);
        int index=today.timeInterval(tTime);
        fgets(buffer,200,fp_price);
        int num=atoi(&buffer[18]);
        flightSet[index].addFlight(sCity,dCity,flightNo,carrier,tTime,aTime,num);
    }
}

void FlightSet::showSet(){
    for(int i=0;i<flightSet.size();i++){
        flightSet[i].showNet();
    }
}

void FlightSet::update() {


}

/*
vector<FlightAns> FlightSet::request(vector<FlightRequest> req, string target_agency) {           //低价行程推荐
    int req_size = req.size();      //航班请求数量
    vector<Flight> tmp[req_size];       //暂存每一段航班的搜索结果
    vector<vector<SameDayFlight> >allowed_combinations; //允许的航班组合,由这个结构处理时间衔接问题
    //该结构主要针对处理同一天的多段请求，将他们组合并且合并起来

    vector<FlightAns> ans;          //用于输出final answer；同时也存储最后一步的中间结果
    bool flag = false;              //标记是否有同一天的连程航班
    bool ok = true;                 //查询成功/失败，如果某一段查询不到航班，则查询失败
    Time last_date = today;         //记录上一段航班的日期，初始化为当天日期
    for(int i = 0; i < req.size(); i++) {
        if (i) {    //i==0时不需要做此判断
            if (Time::Date_equal(req[i].timeVal(), last_date)) flag = true;
            else flag = false;
        }
        int d = getDir(req[i]);     //date_index日期索引
        tmp[i] = flightSet[d].request(req[i], target_agency);  //调用当天的Net搜索满足条件的所有航班
        if(tmp[i].empty()){
            cout<<"第"<<i+1<<"航段查询不到，请重新选择!"<<endl;
            ok = false;     //记录查询结果为失败
            break;
        }
        last_date = req[i].timeVal();   //更新last_date

        //都存入类型SameDayFlight的二维数组中，对于同一天的进行合并
        if (flag) {   //如果与上一段在同一天，则进行组合
            int index = allowed_combinations.size() - 1;     //定位上一组
            //按照抵达时间升序排序
            sort(allowed_combinations[index].begin(),allowed_combinations[index].end(),SameDayFlight::compare_arriveTime);
            //对当前航段按照起飞时间降序排序
            sort(tmp[i].begin(),tmp[i].end(),Flight::compare_takeOffTime);
            int sign = tmp[i].size();       //标记
            vector<SameDayFlight> newSection;
            for (int j = 0; j < allowed_combinations[index].size(); j++) {
                for (int k = 0; k < sign; k++) {
                    if (Time::connect_ok(allowed_combinations[index][j].arriveTime, tmp[i][k].takeOffTimeVal())) {
                        //如果满足衔接要求
                        SameDayFlight element = allowed_combinations[index][j];     //copy
                        element.push_back(tmp[i][k]);
                        newSection.push_back(element);
                    }
                    else{//剪枝
                        sign = k;
                        break;
                    }
                    if(sign == 0) break;
                }
            }
            //删掉原来的，加入组合之后的
            allowed_combinations.pop_back();
            allowed_combinations.push_back(newSection);

        } else {       //如果不在同一天
            vector<SameDayFlight> section;
            for (int j = 0; j < tmp[i].size(); j++) {
                SameDayFlight tmp_saf;
                tmp_saf.push_back(tmp[i][j]);
                section.push_back(tmp_saf);
            }
            allowed_combinations.push_back(section);
        }
    }
    if(ok) {        //查询成功
        int num = allowed_combinations.size();
        //对每一段SameDayFlight的结果按照票价排序
        for (int i = 0; i < num; i++)
            sort(allowed_combinations[i].begin(), allowed_combinations[i].end(), SameDayFlight::comparePrice);
        //得到20个low_price结果

        //num == 1时直接得到20个result, num > 1
        for(int i = 0; i < allowed_combinations[0].size() && i <20; i++){    //初始化,使i<20，做一点剪枝
            FlightAns tmp_ans;
            tmp_ans.Add(allowed_combinations[0][i],target_agency);
            ans.push_back(tmp_ans);
        }
        if(num > 1){
            for(int i = 1; i < num; i++){
                priority_queue<FlightAns,vector<FlightAns>,cmp> p;      //优先队列,大根堆，用于动态选取20个低价行程
                for(int j = 0; j < 20 ; j++){
                    FlightAns tmp_ans;
                    tmp_ans.Virtual_FlightAns();            //设置票价为大值，状态为虚拟
                    p.push(tmp_ans);
                }
                for(int j = 0; j < allowed_combinations[i].size() && j <20; j++){
                    FlightAns top = p.top();
                    if(allowed_combinations[i][j].Return_totalPrice() + ans[0].Return_ticketPrice() < top.Return_ticketPrice()){
                        FlightAns tmp_ans = ans[0];
                        tmp_ans.Add(allowed_combinations[i][j],target_agency);
                        p.pop();
                        p.push(tmp_ans);
                    }
                    else break;             //如果首个都不满足，那么之后所有情况都不要考虑了
                    for(int k = 1; k < ans.size(); k++){
                        FlightAns Piletop = p.top();
                        if(allowed_combinations[i][j].Return_totalPrice() + ans[k].Return_ticketPrice() < Piletop.Return_ticketPrice()){   //比堆顶小，pop_top，新元素入堆
                            FlightAns tmp_ans = ans[k];    //copy 一份
                            tmp_ans.Add(allowed_combinations[i][j],target_agency);
                            p.pop();
                            p.push(tmp_ans);
                        }
                        else break;  //该轮之后肯定也不会比堆顶小，故剪枝
                    }
                }

                //更新ans
                ans.clear();                //clear清空
                vector<FlightAns> reverse_order;        //先存一个反序的
                while(!p.empty()){
                    FlightAns top = p.top();
                    if(top.Return_status())         //如果不是虚拟响应，输出到ans
                        reverse_order.push_back(top);
                    p.pop();
                }
                for(int j = reverse_order.size() - 1; j > 0; j--){  //再反序更新到ans
                    ans.push_back(reverse_order[j]);
                }
            }
        }
        return ans;
    }
    else{       //查询失败
        return ans;     //返回一个空向量，或者可以用一个FlightAns记录下查询失败的航段
    }
}*/

//堆模拟辅助结构
struct asdf{
    int val;        //当前航班总票价
    int x,y;        //当前位置
    int pos[10] = {0};    //初始每一组均取第一个元素，即为最小
    bool p;         //判断是否满足扩展条件
    asdf(){}
    asdf(int vall,int xe,int yo,bool pp){val=vall;x=xe;y=yo;p=pp;}  //快捷构造
    bool operator <(const asdf &b)const{return val>b.val;}          //小于号重载
};
//低价行程推荐算法优化：堆模拟搜索算法-->O(MNlogN)
vector<FlightAns> FlightSet::request(vector<FlightRequest> req, string target_agency) {           //低价行程推荐
    int req_size = req.size();      //航段请求数量
    vector<Flight> tmp[req_size];       //暂存每一段航班的搜索结果
    vector<FlightAns> ans;          //存放推荐结果
    bool ok = true;                 //查询成功/失败，如果某一段查询不到航班，则查询失败

    pair<int,int> head[10];
    priority_queue<asdf>q;          //小根堆
    int cnt = 0;                    //目前得到的满足条件的结果数
    int tot = 0;
    for(int i = 0; i < req_size; i++){
        int d = getDir(req[i]);     //date_index日期索引
        tmp[i] = flightSet[d].request(req[i], target_agency);  //调用当天的Net搜索满足条件的所有航班
        if(tmp[i].empty()){
            cout<<"第"<<i+1<<"航段查询不到，请重新选择!"<<endl;
            ok = false;     //记录查询结果为失败
            break;
        }
        sort(tmp[i].begin(),tmp[i].end(),Flight::comparePrice);     //按照价格从低到高排序-->O(MNlogN)
        if(tmp[i].size() <= 1) head[i]= pair<int,int>(0,i);
        else head[i]= pair<int,int>( tmp[i][1].Return_price() - tmp[i][0].Return_price(),i);
        tot = tot + tmp[i][0].Return_price();         //记录最小值
    }
    if(ok){             //查询成功
        sort(head, head+req_size);      //按照(次小-最小的值)给每一组排序
        q.push(asdf(tot,0,0,false));
        while(cnt <20 && !q.empty()){
            asdf np=q.top();
            q.pop();
            //根据输出构造一个FligntAns
            FlightAns tmp_ans;
            for(int i = 0; i < req_size; i++){
                tmp_ans.Add(tmp[i][np.pos[i]]);
            }
            //判断是否满足衔接条件
            if(tmp_ans.Connect_ok()){   //满足则输出到ans，并且记录cnt++
                ans.push_back(tmp_ans);
                cnt++;
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
            if(np.x+1<req_size){
                asdf tmp_asdf = np;
                tmp_asdf.val = np.val - tmp[head[np.x+1].second][0].Return_price() + tmp[head[np.x+1].second][1].Return_price();
                tmp_asdf.x = np.x + 1;
                tmp_asdf.y = 1;
                tmp_asdf.p = true;
                tmp_asdf.pos[head[np.x+1].second] = 1;
                q.push(tmp_asdf);
            }
            if(np.x+1<req_size && np.p){
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
        return a1.Return_ticketPrice() < a2.Return_ticketPrice();
    }
};
vector<FlightAns> FlightSet::multiAgencyRequest(vector<FlightRequest> req) {
    vector<string>  target_agency = req[0].Return_agency();         //获取允许的代理人数目
    vector<FlightAns> ans;
    priority_queue<FlightAns,vector<FlightAns>,cmp> p;      //优先队列,大根堆，用于动态选取20个低价行程
    for(int j = 0; j < 20 ; j++){
        FlightAns tmp_ans;
        tmp_ans.Virtual_FlightAns();            //设置票价为大值，状态为虚拟
        p.push(tmp_ans);
    }
    //求出每个代理人的20个低价结果，再用堆排序进一步筛选20个低价结果
    for(int i = 0; i < target_agency.size(); i++){
        vector<FlightAns> tmp = request(req,target_agency[i]);
        for(int j = 0 ; j < tmp.size(); j++){
            FlightAns top = p.top();
            if(top.Return_ticketPrice() > tmp[j].Return_ticketPrice()){
                p.pop();
                p.push(tmp[j]);
            }
        }
    }

    vector<FlightAns> reverse_order;        //先存一个反序的
    while(!p.empty()){
        FlightAns top = p.top();
        if(top.Return_status())         //如果不是虚拟响应，输出到ans
            reverse_order.push_back(top);
        p.pop();
    }
    for(int j = reverse_order.size() - 1; j > 0; j--){  //再反序更新到ans
        ans.push_back(reverse_order[j]);
    }
    return ans;
}