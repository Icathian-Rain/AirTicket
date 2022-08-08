<template>
    <div class="loading">
        <p>{{ props.title }}</p>
        <img src="../assets/icons/loading.gif" alt="无法加载" />
    </div>
</template>

<script setup>
const props = defineProps({
    title: {
        type: String,
        default: "加载中...",
    },
});
</script>

<style scoped>
.loading {
    background-color: #ffffff;
    display: flex;
    flex-direction: column;
    align-items: center;
    width: 920px;
    height: 100vh;
    z-index: 100;
}
.loading p {
    position: relative;
    top: 20px;
    text-align: center;
    font-size: 25px;
    color: #999999;
}

.loading img {
    align-content: center;
}
</style>