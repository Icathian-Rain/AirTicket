<template>
    <div class="agent">
        <span class="inline-block"> {{ title }}</span>
        <div class="mt-2 inline-block right-1/10 absolute">
            <el-button
                @click="selectAll()"
                class="mr-5"
                type="success"
                round
                >全选</el-button
            >
            <el-button @click="unselectAll()" type="danger" round
                >全不选</el-button
            >
        </div>
        <el-checkbox-group v-model="value" class="mt-5 block" size="large">
            <el-checkbox-button
                v-for="item in options"
                :key="item.id"
                :label="item.name"
            >
                {{ item.name }}
            </el-checkbox-button>
        </el-checkbox-group>
    </div>
</template>

<script setup>
import { ref, onMounted, computed } from "vue";
const emit = defineEmits(["update:modelValue"]);

const options = ref([]);
onMounted(async () => {
    const res = await fetch("agents.json");
    const data = await res.json();
    options.value = data;
});

const value = computed({
    get() {
        return props.modelValue;
    },
    set(value) {
        emit("update:modelValue", value);
    },
});

const props = defineProps({
    title: {
        type: String,
        default: "",
    },
    modelValue: {
        type: Array,
        default: [],
    },
});

const selectAll = () => {
    for (let i = 0; i < options.value.length; i++) {
        if (value.value.indexOf(options.value[i].name) === -1) {
            value.value.push(options.value[i].name);
        }
    }
};

const unselectAll = () => {
    value.value = [];
};
</script>

<style scoped>
.agent {
    height: 100%;
    margin-bottom: 10px;
}
.agent span {
    position: relative;
    top: 5px;
    font-size: 20px;
}
</style>