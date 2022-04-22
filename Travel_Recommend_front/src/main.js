import { createApp } from 'vue'
import App from './App.vue'
import router from './router'

// 创建app实例
const app = createApp(App)
// 挂载路由
app.use(router).mount('#app')
