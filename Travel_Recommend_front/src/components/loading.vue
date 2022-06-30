<template>
    <div class="loading">
        <p class="desc">{{ pros.title }}</p>
        <img src="../assets/icons/loading.gif" />
        
    </div>
</template>
<script setup>
const pros = defineProps({title: {type: String, default: '加载中'}});
</script>

<style scoped >
.loading {
    position: absolute;
    height: 100vh;
    width: 800px;
    text-align: center;
    /* 高度100% */
    height: 100%;
    /* 背景颜色 */
    background: #fff;
    /* 边框 */
    padding: 10px 5% 30px 5%;
    /* 圆角 */
    border-radius: 6px;
    z-index: 1;
}
.loading img {
    width: 200px;
    /* height: 100px; */
}

.desc{
    position: relative;
    top: 30px;
    margin-top: 10px;
    font-size: 25px;
    color: #999999;
}

</style>