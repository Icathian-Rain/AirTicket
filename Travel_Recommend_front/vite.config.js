import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'



// https://vitejs.dev/config/
export default defineConfig({
    plugins: [vue(),
    ],
    server: {
        open: true,
        proxy: {
            '/api': {
                target: 'http://192.168.31.110:8080',
                changeOrigin: true,
                rewrite: (path) => path.replace(/^\/api/, "")
            }
        }
    }
})
