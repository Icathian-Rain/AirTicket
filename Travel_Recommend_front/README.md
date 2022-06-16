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
    "N": 1,
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
        "CIF",
        "BSD",
        "DLU",
        "BHY"
    ],
    "dCity":[
        "BSD",
        "DNH",
        "AVA",
        "DLU"
    ]
}
```





响应数据

```json
{
	"data" : 
	{
		"ans" : 
		[
			{
				"agc" : 
				[
					"DNH001"
				],
				"flight" : 
				[
					{
						"agc" : 
						[
							"DNH001"
						],
						"arriveTime" : "20220621210000",
						"dCity" : "BSD",
						"flightNo" : "4482",
						"passengetSeatList" : "Y",
						"price" : 3400,
						"sCity" : "CIF",
						"seatC" : 65,
						"seatF" : 52,
						"seatY" : 65,
						"takeOffTime" : "20220621171500"
					},
					{
						"agc" : 
						[
							"DNH001"
						],
						"arriveTime" : "20220622101500",
						"dCity" : "DNH",
						"flightNo" : "3755",
						"passengetSeatList" : "Y",
						"price" : 1140,
						"sCity" : "BSD",
						"seatC" : 53,
						"seatF" : 49,
						"seatY" : 65,
						"takeOffTime" : "20220622093000"
					},
					{
						"agc" : 
						[
							"DLU001",
							"DNH001"
						],
						"arriveTime" : "20220623173000",
						"dCity" : "AVA",
						"flightNo" : "5787",
						"passengetSeatList" : "Y",
						"price" : 1390,
						"sCity" : "DLU",
						"seatC" : 54,
						"seatF" : 65,
						"seatY" : 65,
						"takeOffTime" : "20220623130000"
					},
					{
						"agc" : 
						[
							"DNH001"
						],
						"arriveTime" : "20220624083000",
						"dCity" : "DLU",
						"flightNo" : "9246",
						"passengetSeatList" : "Y",
						"price" : 3360,
						"sCity" : "BHY",
						"seatC" : 65,
						"seatF" : 48,
						"seatY" : 65,
						"takeOffTime" : "20220624071500"
					}
				],
				"ticketPrice" : 9290
			},
			{
				"agc" : 
				[
					"DNH001"
				],
				"flight" : 
				[
					{
						"agc" : 
						[
							"DNH001"
						],
						"arriveTime" : "20220621210000",
						"dCity" : "BSD",
						"flightNo" : "4482",
						"passengetSeatList" : "Y",
						"price" : 3400,
						"sCity" : "CIF",
						"seatC" : 65,
						"seatF" : 52,
						"seatY" : 65,
						"takeOffTime" : "20220621171500"
					},
					{
						"agc" : 
						[
							"DNH001"
						],
						"arriveTime" : "20220622101500",
						"dCity" : "DNH",
						"flightNo" : "3755",
						"passengetSeatList" : "Y",
						"price" : 1140,
						"sCity" : "BSD",
						"seatC" : 53,
						"seatF" : 49,
						"seatY" : 65,
						"takeOffTime" : "20220622093000"
					},
					{
						"agc" : 
						[
							"DNH001",
							"CIF001"
						],
						"arriveTime" : "20220623061500",
						"dCity" : "AVA",
						"flightNo" : "3098",
						"passengetSeatList" : "Y",
						"price" : 1500,
						"sCity" : "DLU",
						"seatC" : 56,
						"seatF" : 48,
						"seatY" : 65,
						"takeOffTime" : "20220623033000"
					},
					{
						"agc" : 
						[
							"DNH001"
						],
						"arriveTime" : "20220624083000",
						"dCity" : "DLU",
						"flightNo" : "9246",
						"passengetSeatList" : "Y",
						"price" : 3360,
						"sCity" : "BHY",
						"seatC" : 65,
						"seatF" : 48,
						"seatY" : 65,
						"takeOffTime" : "20220624071500"
					}
				],
				"ticketPrice" : 9400
			}
		],
		"ansNum" : 2
	},
	"meta" : 
	{
		"msg" : "获取成功",
		"status" : 200
	}
}
```

