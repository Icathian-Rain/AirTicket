<template>
    <div
        class="
            absolute
            left-3
            top-3
            border-solid border-1
            rounded-md
            border-white
        "
    >
        <span class="text-lg"> 航段时间: {{ timeBegin }} ~ {{ timeEnd }}</span>
    </div>
    <div class="body">
        <Update
            @setLoading="setLoading"
            @unsetLoading="unsetLoading"
            @setResData="setResData"
        />
        <Loading v-show="isLoading" :title="LoadingMsg" />
        <SearchForm
            v-model:resData="resData"
            :cityOptions="cityOptions"
            @setLoading="setLoading"
            @unsetLoading="unsetLoading"
        />
        <Result
            :resData="resData"
            :cityOptions="cityOptions"
            v-if="resData !== null"
        />
    </div>
</template>

<script setup>
import Loading from "./Loading.vue";
import Update from "./Update.vue";
import SearchForm from "./SearchForm.vue";
import Result from "./Result.vue";
import { ref, reactive, onMounted } from "vue";
import Update1 from "./Update.vue";
const resData = ref(null);
const cityOptions = ref([]);
const isLoading = ref(false);
const LoadingMsg = ref("加载中...");
const timeBegin = ref("2022年9月1日");
const timeEnd = ref("2023年8月31日");
onMounted(async () => {
    const res = await fetch("cityOptions.json");
    const data = await res.json();
    cityOptions.value = data.Options;
});

let setLoading = (msg) => {
    isLoading.value = true;
    LoadingMsg.value = msg;
};

let unsetLoading = () => {
    isLoading.value = false;
};

let setResData = (data) => {
    resData.value = data;
};
</script>

<style scoped>
.body {
    position: relative;
    left: 20%;
    width: 60%;
    height: auto;
    z-index: 0;
    display: flex;
    flex-direction: column;
    align-items: center;
}
</style>