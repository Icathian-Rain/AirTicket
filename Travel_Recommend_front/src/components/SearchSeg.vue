<template>
    <div class="seg">
        <div class="segIndex">
            <span>第 {{ id + 1 }} 段</span>
        </div>
        <!-- 起始地选择 -->
        <div class="flt-box">
            <!-- 起点 -->
            <div class="flt-depart">
                <span>出发地</span>
                <div class="select-box">
                    <el-select
                        v-model="value.depart"
                        filterable
                        placeholder="出发地"
                    >
                        <el-option
                            v-for="item in cityOptions"
                            :key="item.value"
                            :label="item.label"
                            :value="item.value"
                        />
                    </el-select>
                </div>
            </div>
            <!-- 交换按钮 -->
            <div class="switch-button" @click="exchange">
                <img src="../assets/icons/exchangeIcon.svg" alt="" />
            </div>
            <!-- 终点 -->
            <div class="flt-arrival">
                <span>目的地</span>
                <div class="select-box">
                    <el-select
                        v-model="value.arrival"
                        filterable
                        placeholder="目的地"
                    >
                        <el-option
                            v-for="item in cityOptions"
                            :key="item.value"
                            :label="item.label"
                            :value="item.value"
                        />
                    </el-select>
                </div>
            </div>
        </div>
        <div class="date-box">
            <span>出发日期</span>
            <div class="date-picker">
                <el-config-provider :locale="zhCn">
                    <el-date-picker
                        v-model="value.departTime"
                        type="date"
                        placeholder="选择出发日期"
                        value-format="YYYYMMDD000000"
                        default-value="2022-09-01"
                    />
                </el-config-provider>
            </div>
        </div>
        <div class="remove-segs">
            <el-button size="small" circle @click="$emit('removeSeg', id)" />
            <img src="../assets/icons/remove.svg" alt="" />
        </div>
        <div class="remove-tips"></div>
    </div>
</template>

<script setup>
import { ref, onMounted, computed } from "vue";
import zhCn from "element-plus/dist/locale/zh-cn.mjs";
const emit = defineEmits(["update:modelValue", "removeSeg"]);
const props = defineProps({
    id: {
        type: Number,
        default: 0,
    },
    cityOptions: {
        type: Array,
        default: [],
    },
    modelValue: {
        type: Object,
        default: {
            depart: "",
            arrival: "",
            departTime: "",
        },
    },
});
const value = computed({
    get() {
        return props.modelValue;
    },
    set(value) {
        emit("update:modelValue", value);
    },
});

const exchange = () => {
    const depart = value.value.depart;
    const arrival = value.value.arrival;
    value.value.depart = arrival;
    value.value.arrival = depart;
};
</script>

<style scoped>
.seg {
    margin-top: 10px;
    margin-bottom: 10px;
    display: flex;
    flex-direction: row;
    justify-content: space-between;
    position: relative;
    background-color: #ffffff;
    border: 1px solid #eee;
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 6%);
    padding: 10px;
}

.flt-box {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
    position: relative;
    border-radius: 6px;
    border: 1px solid #eee;
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 6%);
}

.flt-box:hover {
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 10%);
}

.flt-depart {
    display: flex;
    flex-direction: column;
    border-right: 1px solid, #eee;
}

.flt-depart span {
    color: #3187f9;
    font-size: 10px;
    margin: 10px 0px 3px 10px;
}

.flt-depart input {
    margin: 0px 3px 10px 10px;
    border: none;
    height: 32px;
    width: 140px;
}

.switch-button {
    /* 相对定位 */
    position: relative;
    border: 1px solid;
    border-radius: 50%;
    width: 30px;
    height: 30px;
    top: 15px;
    cursor: pointer;
    background-color: #fff;
}

.switch-button:hover {
    background-color: #f4f4f4;
}

.switch-button img {
    height: 20px;
    width: 20px;
    position: relative;
    left: 5px;
    top: 5px;
}

.flt-arrival {
    display: flex;
    flex-direction: column;
    left: 30px;
}

.flt-arrival span {
    color: #3187f9;
    font-size: 10px;
    margin: 10px 0px 4px 10px;
}

.flt-arrival input {
    margin: 0px 3px 10px 10px;
    border: none;
    height: 32px;
    font-size: 20px;
    width: 140px;
}

.date-box {
    display: flex;
    flex-direction: column;
    border: 1px solid;
    border-radius: 6px;
    width: 240px;
    border: 1px solid #eee;
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 6%);
}
.date-box:hover {
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 10%);
}

.date-box span {
    color: #3187f9;
    font-size: 10px;
    margin: 10px 0px 3px 10px;
}

.date-picker {
    margin-left: 10px;
    margin-bottom: 10px;
}

.select-box {
    margin: 0px 10px 10px 10px;
    width: 140px;
}

.segIndex {
    position: absolute;
    left: -63px;
    top: 50%;
    transform: translateY(-50%);
    font-size: 16px;
    color: #3187f9;
    padding: 5px;
    border: 1px solid #000;
    border-right: #fff;
    border-radius: 6px;
}

.remove-segs {
    position: absolute;
    top: 50%;
    left: 100%;
    transform: translateY(-50%);
}

.remove-segs .el-button {
    background: none;
}
.remove-segs img {
    top: 0px;
    position: absolute;
    height: 20px;
    transform: translateX(10%) translateY(15%);
    z-index: -1;
}
.remove-tips {
    visibility: hidden;
    position: absolute;
    left: 0px;
    top: 0px;
    height: 100%;
    width: 100%;
    background-color: rgba(255, 255, 255, 0.7);
    filter: blur(10px);
}

.remove-segs:hover + .remove-tips {
    visibility: visible;
}
</style>
