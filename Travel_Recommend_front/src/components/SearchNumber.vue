<template>
    <div class="number">
        <span> {{ props.title }}</span>
        <el-input v-model="value" type="number" style="width: 200px; left: 20px; font-size: 20px;" min="0"/>
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
});

const emit = defineEmits(['update:modelValue'])
const value = computed({
    get() {
        return props.modelValue;
    },
    set(value) {
        emit("update:modelValue", value);
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