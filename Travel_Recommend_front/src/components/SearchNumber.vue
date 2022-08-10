<template>
    <div class="number">
        <span> {{ props.title }}</span>
        <el-input
            v-model="value"
            type="number"
            style="width: 200px; left: 20px; font-size: 20px"
            :min="props.min"
            :max="props.max"
        />
    </div>
</template>

<script setup>
import { computed } from "vue";

const props = defineProps({
    title: {
        type: String,
        default: "",
    },
    modelValue: {
        type: Number,
        default: 0,
    },
    min: {
        type: Number,
        default: 0,
    },
    max: {
        type: Number,
        default: 0,
    },
});

const showMsg = (msg, type) => {
    ElMessage({
        showClose: true,
        duration: 2000,
        message: msg,
        type: type,
    });
};

const emit = defineEmits(["update:modelValue"]);
const value = computed({
    get() {
        return props.modelValue;
    },
    set(value) {
        value = Number(value);
        if (value >= props.min && value <= props.max) {
            emit("update:modelValue", value);
        }
        else {
            showMsg(`请输入${props.min}-${props.max}之间的数字`, "warning");
        }
        
    },
});
</script>

<style scoped>
.number {
    height: 30px;
    margin-top: 10px;
    margin-bottom: 10px;
}

.number span {
    font-size: 20px;
    display: inline-block;
}
</style>