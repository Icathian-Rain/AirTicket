import { createRouter, createWebHashHistory } from "vue-router";
// 导入主目录
import Home from "../components/Home.vue";

// 路由配置
const routes = [
    { path: '/', redirect: '/home' },
    { path: '/home', component: Home },
]

// 创建路由实例
const router = createRouter({
    history: createWebHashHistory(),
    routes
})


// 导出路由
export default router