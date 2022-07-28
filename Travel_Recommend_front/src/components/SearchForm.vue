<template>
    <div class="search-form">
        <SearchNumber title="乘客人数" v-model="number" />
        <SearchAgent title="代理人" v-model="agents" />
        <span style="font-size: 20px;">航段</span>
        <div class="serach-segments">
            <div v-for="(segs, i) in segments">
                <SearchSeg
                    v-model="segments[i]"
                    :id="i"
                    :cityOptions="props.cityOptions"
                    @removeSeg="
                        (t) => {
                            segments.splice(t, 1);
                        }
                    "
                />
            </div>
        </div>
        <addSeg
            @addSeg="
                () => {
                    segments.push({
                        depart: '',
                        arrival: '',
                        departTime: '',
                    });
                }
            "
        />
        <div class="search">
            <el-button class="search-button" @click="formSubmit()">
                搜索</el-button
            >
            <img src="../assets/icons/search.svg" alt="" />
        </div>
    </div>
</template>

<script setup>
import SearchNumber from "./SearchNumber.vue";
import SearchAgent from "./SearchAgent.vue";
import SearchSeg from "./SearchSeg.vue";
import addSeg from "./addSeg.vue";
import axios from "axios";
import { ref, reactive, onMounted } from "vue";

const props = defineProps(["cityOptions", "resData"]);
const emit = defineEmits(["setLoading", "unsetLoading", "update:resData"]);
const agents = ref([]);
const number = ref(0);
const segments = ref([
    {
        // 出发地
        depart: "",
        // 目的地
        arrival: "",
        // 出发时间
        departTime: "",
    },
]);

axios.defaults.baseURL = "http://api.hustairline.xyz/api/";
axios.defaults.timeout = 3000;

const formSubmit = () => {
    emit("setLoading", "搜索中...");
    let req_data = {
        N: Number(number.value),
        M: segments.value.length,
        agency: [],
        date: [],
        sCity: [],
        dCity: [],
    };
    for (let i = 0; i < agents.value.length; i++) {
        req_data.agency.push(agents.value[i] + "001");
    }
    for (let i = 0; i < segments.value.length; i++) {
        req_data.date.push(segments.value[i].departTime);
        req_data.sCity.push(segments.value[i].depart);
        req_data.dCity.push(segments.value[i].arrival);
    }
    if (req_data["N"] <= 0) {
        ElMessage({
            showClose: true,
            duration: 2000,
            message: "乘客数量不能为0",
            type: "error",
        });
        emit("unsetLoading");
        return;
    } else if (req_data["M"] === 0) {
        ElMessage({
            showClose: true,
            duration: 2000,
            message: "航程数量不能为0",
            type: "error",
        });
        emit("unsetLoading");
        return;
    } else if (req_data["agency"].length === 0) {
        ElMessage({
            showClose: true,
            duration: 2000,
            message: "代理商不能为空",
            type: "error",
        });
        emit("unsetLoading");
        return;
    }
    axios
        .post("/query", req_data, {
            headers: {
                "Content-Type": "text/plain",
            },
        })
        .then((response) => {
            if (response.data.meta.status == 200) {
                emit("update:resData", response.data.data);
                ElMessage({
                    showClose: true,
                    duration: 2000,
                    message: "搜索成功",
                    type: "success",
                });
            } else {
                emit("update:resData", null);
                ElMessage({
                    showClose: true,
                    duration: 2000,
                    message: "搜索失败",
                    type: "error",
                });
            }
        })
        .catch((error) => {
            ElMessage({
                showClose: true,
                duration: 2000,
                message: "输入数据有误",
                type: "error",
            });
            // 请求失败处理
            console.log(error);
        })
        .finally(() => {
            emit("unsetLoading");
        });
};
</script>

<style scoped>
.search-form {
    display: flex;
    flex-direction: column;
    justify-content: center;
    height: auto;
    background-color: #fff;
    /* 边框 */
    padding: 10px 5% 80px 5%;
    /* 圆角 */
    border-radius: 6px;
    position: relative;
    top: 50px;
}

.search {
    position: absolute;
    top: 100%;
    left: 50%;
    transform: translateX(-50%) translateY(-50%);
}
.search-button {
    border-radius: 28px;
    height: 50px;
    width: 120px;
    padding-left: 30px;
    background-color: #f70;
    background-image: linear-gradient(-90deg, #f70, #ffa50a);
}

.search img {
    position: absolute;
    left: 20%;
    top: 45%;
    transform: translateY(-50%);
    height: 20px;
    width: 20px;
    color: #fff;
}
</style>