<template>
    <el-button class="update" @click="visible = true" size="large">
        <img src="../assets/icons/update.svg" alt="" />
        <p>重置数据</p>
    </el-button>
    <el-dialog v-model="visible" :show-close="false" class="z-{1}">
        <template #header="{ close, titleId, titleClass }">
            <div class="my-header">
                <h4 :id="titleId" :class="titleClass">选择重置文件</h4>
                <el-button type="danger" @click="close"> 关闭 </el-button>
            </div>
        </template>
        <el-radio-group v-model="fileName" class="ml-4 mb-5">
            <el-radio :label="option" v-for="(option, i) in fileOptions">
                {{ option }}</el-radio
            >
        </el-radio-group>
        <el-button
            type="primary"
            class="relative left-1/2"
            style="display: block; transform: translateX(-50%)"
            @click="update()"
            >确认重置数据</el-button
        >
    </el-dialog>
</template>

<script setup>
import { ref, onMounted } from "vue";
import axios from "axios";
axios.defaults.baseURL = "http://api.hustairline.xyz/api/";
axios.defaults.timeout = 3000;
const emit = defineEmits(["setLoading", "unsetLoading", "setResData"]);
const visible = ref(false);
const fileName = ref("");
const fileOptions = ref([]);
const name2File = ref({});

onMounted(async () => {
    const res = await fetch("updateFiles.json");
    const data = await res.json();
    for (let i = 0; i < data.length; i++) {
        fileOptions.value.push(data[i].name);
        name2File.value[data[i].name] = data[i].fileName;
    }
});

let update = () => {
    emit("setLoading", "正在更新数据...");
    if (fileName.value === "") {
        emit("unsetLoading");
        ElMessage({
            showClose: true,
            duration: 2000,
            message: "更新失败，请选择更新文件",
            type: "error",
        });
        return;
    }
    visible.value = false;
    axios
        .get("/update", {
            params: {
                fileName: name2File.value[fileName.value],
            },
        })
        .then((response) => {
            if (response.status === 200) {
                ElMessage({
                    showClose: true,
                    duration: 2000,
                    message: "更新成功",
                    type: "success",
                });
                emit("setResData", null);
            } else {
                ElMessage({
                    showClose: true,
                    duration: 2000,
                    message: "更新失败,请联系管理员",
                    type: "error",
                });
                visible.value = true;
            }
        })
        .catch((err) => {
            console.log(err);
            ElMessage({
                showClose: true,
                duration: 2000,
                message: "更新失败,请联系管理员",
                type: "error",
            });
            visible.value = true;
        })
        .finally(() => {
            emit("unsetLoading");
        });
};
</script>

<style scoped>
.update {
    display: flex;
    align-items: center;
    position: fixed;
    top: 20px;
    right: 8%;
    z-index: 1;
}

.update p {
    font-size: 20px;
}
.update img {
    width: 30px;
    height: 30px;
}

.my-header {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
}
</style>
