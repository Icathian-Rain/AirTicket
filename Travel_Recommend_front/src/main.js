import { createApp } from 'vue'
import App from './App.vue'
// 导入路由
import router from './router'
// 导入全局样式
import './assets/css/global.css'
// 导入ElementPlus
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css'
import zhCn from 'element-plus/es/locale/lang/zh-cn'
import axios from 'axios'

const Axio = axios.create({
    baseURL: 'http://192.168.31.110:8080'
});

Axio.interceptors.response.use(function (response) {
    // 对响应数据做点什么
    return response;
}, function (error) {
    // 对响应错误做点什么
    return Promise.reject(error);
});

// 创建app实例
const app = createApp(App)
// 挂载路由
app.use(ElementPlus, {
    locale: zhCn
})

app.config.globalProperties.$http = Axio

app.use(router).mount('#app')

