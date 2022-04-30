<template>
    <div class="home">
        <form @submit="formSubmit()" class="search-form">
            <!-- 第一层选择栏 -->
            <div class="search-form-top">
                <!-- 行程方式选择 -->
                <div>
                    <el-radio-group v-model="selectedType">
                        <el-radio :label="item" v-for="(item, i) in tripType">{{
                            item
                        }}</el-radio>
                    </el-radio-group>
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
                        <div class="select-box">
                            <el-select
                                v-model="depart"
                                filterable
                                placeholder="出发地"
                            >
                                <el-option
                                    v-for="item in options"
                                    :key="item.value"
                                    :label="item.label"
                                    :value="item.value"
                                />
                            </el-select>
                        </div>
                    </div>
                    <!-- 交换按钮 -->
                    <div class="switch-button" @click="exchange">
                        <img src="/exchangeIcon.svg" alt="" />
                    </div>
                    <!-- 终点 -->
                    <div class="flt-arrival">
                        <span>目的地</span>
                        <div class="select-box">
                            <el-select
                                v-model="arrival"
                                filterable
                                placeholder="出发地"
                            >
                                <el-option
                                    v-for="item in options"
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
                        <el-date-picker
                            v-model="departTime"
                            type="date"
                            placeholder="Pick a day"
                        />
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
            // 出发时间
            departTime: "",
            options: [
                {
                    value: "HRB",
                    label: "哈尔滨(HRB)",
                },
                {
                    value: "MDG",
                    label: "牡丹江(MDG)",
                },
                {
                    value: "NDG",
                    label: "齐齐哈尔(NDG)",
                },
                {
                    value: "JMU",
                    label: "佳木斯(JMU)",
                },
                {
                    value: "CGQ",
                    label: "长春(CGQ)",
                },
                {
                    value: "YNJ",
                    label: "延吉(YNJ)",
                },
                {
                    value: "JIL",
                    label: "吉林(JIL)",
                },
                {
                    value: "NBS",
                    label: "白山(NBS)",
                },
                {
                    value: "SHE",
                    label: "沈阳(SHE)",
                },
                {
                    value: "DDG",
                    label: "丹东(DDG)",
                },
                {
                    value: "JNZ",
                    label: "锦州(JNZ)",
                },
                {
                    value: "DLC",
                    label: "",
                },
                {
                    value: "CHG",
                    label: "",
                },
                {
                    value: "TNA",
                    label: "",
                },
                {
                    value: "TNA",
                    label: "",
                },
                {
                    value: "YNT",
                    label: "",
                },
                {
                    value: "WEF",
                    label: "",
                },
                {
                    value: "TAO",
                    label: "",
                },
                {
                    value: "WEH",
                    label: "",
                },
                {
                    value: "LYI",
                    label: "",
                },
                {
                    value: "TNA",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
                {
                    value: "",
                    label: "",
                },
            ],
        };
    },
    methods: {
        formSubmit() {
            console.log("form submit");
        },
        exchange() {
            let temp = this.depart;
            this.depart = this.arrival;
            this.arrival = temp;
        },
    },
};
</script>

<style scoped>
.home {
    /* 相对定位 */
    position: relative;
    top: 30px;
    /* 页面100% */
    /* width: 2179px; */
    width: 100%;
    height: 100%;
    /* 以 flex 形式 */
    display: flex;
    /* 纵向排布 */
    flex-direction: column;
    /* 垂直居中 */
    align-items: center;
}

/* 搜索表单 */
.search-form {
    /* flex布局 */
    display: flex;
    /* 纵向布局 */
    flex-direction: column;
    /* 主轴居中对齐 */
    justify-content: center;
    /* 交叉轴上居中 */
    align-items: center;
    position: relative;
    /* 宽度固定 */
    width: 800px;
    /* 高度100% */
    height: 100%;
    /* 背景颜色 */
    background: #fff;
    /* 边框 */
    padding: 10px;
    /* 圆角 */
    border-radius: 6px;
}

.search-form-top {
    /* 相对定位 */
    position: relative;
    display: flex;
    /* 宽度 100% */
    width: 100%;
    /* 不换行 */
    flex-wrap: nowrap;
    /* space-button */
    justify-content: space-between;
    /* 横向排布 */
    flex-direction: row;
    /* 垂直居中 */
    align-items: center;
    /* 下margin */
    margin-bottom: 10px;
}
.form-checkboxs {
    /* 选择行程类型 */
    display: inline-block;
    margin-right: 10px;
}

.chooseSeat {
    display: inline-block;
    /* 无边框 */
    border-style: none;
    background-color: #ffffff;
    padding: 5px;
    margin: 0px;
    /* 不可选中 */
    user-select: none;
    border-radius: 6px;
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
    left: calc(50% + 265px);
    list-style: none;
    padding: 0px;
    border: solid #ffffff 1px;
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
    /* 横向排布 */
    flex-direction: row;

    justify-content: space-between;
    /* 相对定位 */
    position: relative;
    background-color: #ffffff;
    height: 100%;
    width: 100%;
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
</style>

