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
- 请求方法: get
- 请求参数
  
| 参数名    | 参数说明           | 备注      |
| --------- | ------------------ | --------- |
| n         | 航段总数           |           |
| date_list | 每个航段信息       | 1或多个   |
| date      | 每个航段的出发时间 |           |
| depart    | 起飞城市           |           |
| arrival   | 抵达城市           |           |
| agents    | 允许的出票人       | 可为空    |
| passenger    | 旅客数             | 1个或多个 |


