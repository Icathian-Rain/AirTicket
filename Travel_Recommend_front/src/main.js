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



// 创建app实例
const app = createApp(App)
// 挂载路由
app.use(ElementPlus, {
    locale: zhCn
})
app.use(router).mount('#app')
