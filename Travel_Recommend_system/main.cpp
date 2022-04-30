#include <iostream>
using namespace std;
//#include "Flight.h"
//#include "Time.h"
//#include "PriceRule.h"
#include "Net.h"
//#include "FlightAns.h"
//#include "FlightRequest.h"
//#include "RemainingSeat.h"
#include "FlightSet.h"
//#include "Recommend_sys.h"
#include <vector>
#include <string>

int main() {
    vector<string> cityName={"北京","上海","广州","深圳","香港","澳门","沈阳","青岛","济南","武汉","厦门","西安","长沙","南京","杭州","重庆","成都","昆明","贵阳","三亚","海口","乌鲁木齐","西宁","兰州","银川","拉萨"};
//    class Net net;
//    net.initNet(cityName, "2022-04-25");
//    FILE *fp=fopen("../data.txt","r");
//    net.createNet(fp);
//    net.showNet();
    FlightSet set;
    set.initSet(cityName, "2022-04-26", 10);
    FILE *fp=fopen("../data.txt","r");
    set.createSet(fp);
    set.showSet();
    return 0;
}
