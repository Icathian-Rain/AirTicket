<template>
    <div class="add-seg">
            <el-button size="small" circle @click="$emit('addSeg')" />
            <img src="../assets/icons/plus.svg" alt="">
        </div>
</template>


<script setup>
defineEmits(['addSeg'])

</script>

<style scoped>
.add-seg {
    position: relative;
    top: 10px;
    height: 0px;
    width: 100%;
    border-bottom: 1px dashed rgba(0, 0, 0, 0.2);
}

.add-seg .el-button {
    position: absolute;
    left: 50%;
}

.add-seg img {
    position: absolute;
    height: 20px;
    left: 50%;
    transform: translateX(10%) translateY(10%);
    z-index: 0;
}

.add-seg .el-button {
    position: absolute;
    z-index: 1;
    background: none;
}

.add-seg:hover {
    border-bottom: 1px dashed rgba(0, 0, 0, 1);
}

</style>