# Travel_Recommend_front 行程推荐项目前端

**!!! tab键建议使用4个空格，使用vscode自带的代码格式化工具**


使用 yarn 安装功能包

使用 vite + vue3构建

路由使用 vue-router

# 信息：
    组件位于./src/components/内
    assets 位于./src/assets
    路由管理位于 ./src/router/index.js


开发环境下使用
```bash
# 安装依赖包
yarn
# 以dev模式运行
yarn dev
```

其他环境下使用
```bash
# build
yarn build

# preview
yarn preview
```

添加了Element-Plus组件，全局引入，运行前请执行yarn更新
使用方法见官方文档
https://element-plus.gitee.io/zh-CN/


# api接口
## 搜索请求

- 请求路径: query
- 请求方法: post
- 请求参数
  
| 参数名    | 参数说明           | 备注      |
| --------- | ------------------ | --------- |
| N        | 旅客总数     | <=8 |
| agency | 允许的代理人 | 1或多个 |
| M     | 航段数 | 1或多个 |
| date    | 起飞日期         |           |
| sCity | 起飞城市         | 三字码 |
| dCity | 抵达城市     | 可为    |
|        |              |         |

eg

```json
{
    "N":"1",
    "agency":[
        "CIF001",
        "BHY001",
        "AOG001",
        "CZX001",
        "BFU001",
        "DLU001",
        "CKG001",
        "CTU001",
        "DNH001"
    ],
    "M":4,
    "date":[
        "20220621000000",
        "20220622000000",
        "20220623000000",
        "20220624000000"
    ],
    "sCity":[
        "SHA",
        "PEK",
        "PEK",
        "SHA",
    ],
    "dCity":[
        "PEK",
        "SHA",
        "SHA",
        "P"
    ]
    
    
    
}
```





响应数据

```json
{
    "data": {
        "ticketPrice": 100000,
        "agency": [
            "携程",
            "滴滴",
        ],
        "flight": [
            {
                "carrier": "东方航空",
                "flightNo": "N101",
                ""
                "takeOffTime": "", // 起飞时间
                "arrivalTime": "", // 抵达时间
                "sCity": "ShangHai", // 起飞城市
                "dCity": "Beijing", // 抵达城市
                "price": 1000, // 票价
            },
            {
                // 第二段
            }
        ]
    },
    "meta": {
        "msg": "获取成功",
        "status": 200
    }
}
```

