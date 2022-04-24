<template>
    <div class="home">
        <form @submit="formSubmit()" class="search-form">
            <!-- 第一层选择栏 -->
            <div class="search-form-top">
                <!-- 行程方式选择 -->
                <div>
                    <div class="form-checkboxs" v-for="item in tripType">
                        <input type="radio" :value="item" name="tripType" v-model="selectedType"/>
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
                        <span>出发地</span>
                        <input type="text" class="depart" v-model="depart">
                    </div>
                    <!-- 交换按钮 -->
                    <div class="switch-button" @click="exchange">
                        <img src="/exchangeIcon.svg" alt="">
                    </div>
                    <!-- 终点 -->
                    <div class="flt-arrival">
                        <span>目的地</span>
                        <input type="text" class="arrival" v-model="arrival">
                    </div>
                </div>
                <div class="date-box">
                    <span>出发日期</span>
                    <input type="text" class="date" v-model="date"/>
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
            // 选择的方式
            selectedType: "",
            // 座位类型
            seatClass: ["不限舱位", "经济舱", "公务/头等舱"],
            // 选择的座位类型
            selectedSeat: "不限舱位",
            // 座位类型选择框是否显示
            menuVisible: false,

            // 出发地
            depart: "",
            // 目的地
            arrival: "",

        };
    },
    methods: {
        formSubmit() {
            console.log("form submit");
        },
        exchange () {
            let temp = this.depart;
            this.depart = this.arrival;
            this.arrival = temp;
        }
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
    border-radius: 6px;
}

.search-form-top {
    position: relative;
    display: flex;
    flex-wrap: nowrap;
    justify-content: space-between;
    flex-direction: row;
    align-items: center;
    /* width: auto; */
    margin-bottom: 10px;
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
    width: 130px;
    position: absolute;
    top: 25px;
    left: 840px;
    list-style: none;
    padding: 0px;
    border: solid  #ffffff 1px;
    z-index: 1;
}
.list li {
    padding-bottom: 10px;
    padding: 5px;
    user-select: none;
    cursor: pointer;
    background-color: #fff;
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


.form-line {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
    position: relative;
    background-color: #ffffff;
    height: 64px;
    width: 960px;
}


.flt-box {
    display: flex;
    flex-direction: row;
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
    height: 20px;
    width: 140px;
}



.switch-button {
    position: relative;
    border: 1px solid;
    border-radius: 50%;
    width: 30px;
    height: 30px;
    left: -10px;
    transform: translateX(-50%);
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
    
}

.flt-arrival span {
    color: #3187f9;
    font-size: 10px;
    margin: 10px 0px 4px 10px;
}

.flt-arrival input {
    margin: 0px 3px 10px 10px;
    border: none;
    height: 20px;
    width: 140px;
}

.date-box {
    display: flex;
    flex-direction: column;
    border: 1px solid;
    border-radius: 6px;
    width: 300px;
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
.date-box input{
    margin: 0px 3px 10px 10px;
    border: none;
    height: 20px;
    width: 250px;
}

</style>

