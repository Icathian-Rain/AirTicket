<template>
    <div class="home">
        <form @submit="formSubmit()" class="search-form">
            <!-- 第一层选择栏 -->
            <div class="search-form-top">
                <!-- 行程方式选择 -->
                <div>
                    <div class="form-checkboxs" v-for="item in tripType">
                        <input type="radio" :value="item" name="tripType" />
                        {{ item }}
                    </div>
                </div>
                <!-- 座次选择 -->
                <div class="seatclass">
                    <div @click="menuVisible = !menuVisible" class="chooseSeat">
                        {{ selectedSeat }}
                        <img src="/arrayDown.svg" alt="" v-if="menuVisible" />
                        <img src="/arrayLeft.svg" alt="" v-else />
                    </div>
                    <ul class="list" v-if="menuVisible">
                        <li
                            v-for="seat in seatClass"
                            :key="seat"
                            @click="selectedSeat = seat"
                        >
                            <img
                                src="/tick.svg"
                                alt=""
                                v-if="seat === selectedSeat"
                            />
                            <span v-else> &nbsp;&nbsp;&nbsp;&nbsp; </span>
                            <span
                                v-if="seat === selectedSeat"
                                style="color: #0076f5"
                                >{{ seat }}</span
                            >
                            <span v-else>{{ seat }}</span>
                        </li>
                    </ul>
                </div>
            </div>
            <!-- 第二层选择 -->
            <div class="form-line">
                <!-- 起始地选择 -->
                <div class="flt-box">
                    <!-- 起点 -->
                    <div class="flt-depart">
                    </div>
                    <!-- 交换按钮 -->
                    <div class="switch-button">
                    </div>
                    <!-- 终点 -->
                    <div class="flt-arrival">
                    </div>
                </div>
            </div>
        </form>
    </div>
</template>

<script >
export default {
    data() {
        return {
            // 行程方式
            tripType: ["单程", "往返", "多程"],
            seatClass: ["不限舱位", "经济舱", "公务舱位舱"],
            // 选择的座位类型
            selectedSeat: "不限舱位",
            menuVisible: false,
        };
    },
    methods: {
        formSubmit() {
            console.log("form submit");
        },
    },
};
</script>

<style scoped>
.home {
    /* 页面100% */
    width: 2179px;
    height: 100%;
    /* 以 flex 形式 */
    display: flex;
    /* 纵向排布 */
    flex-direction: row;
    /* 垂直居中 */
    align-content: center;
}

.search-form {
    /* flex */
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-content: center;
    position: relative;
    width: 100%;
    height: 100%;
    background: #fff;
    padding: 10px;
    margin: 0px 600px 0px 600px;
    border-radius: 5%;
}

.search-form-top {
    position: relative;
    display: flex;
    flex-wrap: nowrap;
    justify-content: space-between;
    flex-direction: row;
    align-items: center;
    /* width: auto; */
}
.form-checkboxs {
    display: inline-block;
    margin-right: 10px;
}

.chooseSeat {
    display: inline-block;
    border-style: none;
    background-color: #ffffff;
    padding: 5px;
    margin: 0px;
    user-select: none;
}
.chooseSeat img {
    width: 13px;
    height: 13px;
    margin-left: 5px;
}

.chooseSeat:hover {
    cursor: pointer;
    background-color: #f4f4f4;
}

.list {
    width: 120px;
    position: absolute;
    top: 25px;
    left: 840px;
    list-style: none;
    padding: 0px;
    border: solid 1px;
}
.list li {
    padding-bottom: 10px;
    padding: 5px;
    user-select: none;
    cursor: pointer;
}

.list li:hover {
    background-color: #f2f9ff;
}

.list img {
    position: relative;
    height: 18px;
    top: 2px;
    padding-right: 3px;
}
</style>

