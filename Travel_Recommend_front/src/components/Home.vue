<template>
    <div class="home" @click="menuVisible = false">
        <form class="search-form">
            <!-- 第一层选择栏 -->
            <div class="search-form-top">
                <!-- 行程方式选择 -->
                <div class="passenger-box">
                    <span>乘客人数</span>
                    <el-input v-model="passenger" type="number" />
                </div>
                <!-- 代理人选择 -->
                <div class="agent-box">
                    <span>代理人</span>
                    <el-checkbox-group v-model="agent">
                        <el-checkbox-button
                            v-for="item in agentOptions"
                            :key="item"
                            :label="item"
                        >
                            {{ item }}
                        </el-checkbox-button>
                    </el-checkbox-group>
                </div>
            </div>
            <!-- 第二层选择 -->
            <div
                class="form-line"
                :id="'form-line' + i"
                v-for="(seg, i) in segments"
            >
                <div class="segIndex">
                    <span>第 {{ i + 1 }} 段</span>
                </div>
                <!-- 起始地选择 -->
                <div class="flt-box">
                    <!-- 起点 -->
                    <div class="flt-depart">
                        <span>出发地</span>
                        <div class="select-box">
                            <el-select
                                v-model="seg.depart"
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
                                v-model="seg.arrival"
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
                            v-model="seg.departtime"
                            type="date"
                            placeholder="选择出发日期"
                        />
                    </div>
                </div>
                <div class="remove-segs">
                    <el-button size="small" circle @click="removeSegs(i)" />
                    <svg
                        viewBox="0 0 1024 1024"
                        xmlns="http://www.w3.org/2000/svg"
                        data-v-ba633cb8=""
                    >
                        <path
                            fill="currentColor"
                            d="M512 64a448 448 0 1 1 0 896 448 448 0 0 1 0-896zm0 393.664L407.936 353.6a38.4 38.4 0 1 0-54.336 54.336L457.664 512 353.6 616.064a38.4 38.4 0 1 0 54.336 54.336L512 566.336 616.064 670.4a38.4 38.4 0 1 0 54.336-54.336L566.336 512 670.4 407.936a38.4 38.4 0 1 0-54.336-54.336L512 457.664z"
                        ></path>
                    </svg>
                </div>
                <div class="remove-tips"></div>
            </div>
            <div class="add-segs">
                <el-button size="small" circle @click="addSegs()" />
                <svg
                    viewBox="0 0 1024 1024"
                    xmlns="http://www.w3.org/2000/svg"
                    data-v-ba633cb8=""
                >
                    <path
                        fill="currentColor"
                        d="M512 64a448 448 0 1 1 0 896 448 448 0 0 1 0-896zm-38.4 409.6H326.4a38.4 38.4 0 1 0 0 76.8h147.2v147.2a38.4 38.4 0 0 0 76.8 0V550.4h147.2a38.4 38.4 0 0 0 0-76.8H550.4V326.4a38.4 38.4 0 1 0-76.8 0v147.2z"
                    ></path>
                </svg>
            </div>
            <div class="search">
                <el-button class="search-button" @click="formSubmit()">
                    搜索</el-button
                >
                <svg
                    viewBox="0 0 1024 1024"
                    xmlns="http://www.w3.org/2000/svg"
                    data-v-ba633cb8=""
                >
                    <path
                        fill="currentColor"
                        d="m795.904 750.72 124.992 124.928a32 32 0 0 1-45.248 45.248L750.656 795.904a416 416 0 1 1 45.248-45.248zM480 832a352 352 0 1 0 0-704 352 352 0 0 0 0 704z"
                    ></path>
                </svg>
            </div>
        </form>
    </div>
</template>

<script >
import { getCurrentInstance } from "vue";

export default {
    setup() {
        const internalInstance = getCurrentInstance();
        const http = internalInstance.appContext.config.globalProperties.$http; 
        return {
            http,
        }
    },
    data() {
        return {
            // 乘客数
            passenger: 1,
            // 代理人选项
            agentOptions: ["携程", "美团", "滴滴"],
            // 代理人
            agent: [""],
            // 座位类型
            seatClass: ["不限舱位", "经济舱", "公务/头等舱"],
            // 选择的座位类型
            selectedSeat: "不限舱位",
            // 航段
            segments: [
                {
                    // 出发地
                    depart: "",
                    // 目的地
                    arrival: "",
                    // 出发时间
                    departTime: "",
                    // 座位类型
                    seatClass: "",
                },
            ],
            // 机场选项
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
            this.http.get("https://www.runoob.com/try/ajax/json_demo.json")
                .then((response) => (console.log(response)))
                .catch(function (error) {
                    // 请求失败处理
                    console.log(error);
                });
        },
        exchange() {
            let temp = this.depart;
            this.depart = this.arrival;
            this.arrival = temp;
        },
        getLabel(value) {
            for (let i in this.options) {
                if (this.options[i].value === value) {
                    return this.options[i].label;
                }
            }
        },
        addSegs() {
            this.segments.push({
                depart: "",
                arrival: "",
                departTime: "",
                seatClass: "",
            });
        },
        removeSegs(i) {
            this.segments.splice(i, 1);
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
    padding: 10px 5% 80px 5%;
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

.passenger-box span,
.el-input {
    display: inline;
}

.passenger-box span {
    margin-right: 10px;
}

.agent-box span,
.el-checkbox-group {
    display: inline-block;
}
.agent-box span {
    position: relative;
    top: 5px;
    margin-right: 10px;
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
    border: 1px solid #eee;
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 6%);
    padding: 10px;
    margin-bottom: 10px;
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

.add-segs {
    position: relative;
    top: 10px;
    height: 0px;
    width: 90%;
    border-bottom: 1px dashed rgba(0, 0, 0, 0.2);
}

.add-segs .el-button {
    position: absolute;
    left: 50%;
}

.add-segs svg {
    position: absolute;
    height: 20px;
    left: 50%;
    transform: translateX(10%) translateY(10%);
    z-index: 0;
}

.add-segs .el-button {
    position: absolute;
    z-index: 1;
    background: none;
}

.add-segs:hover {
    border-bottom: 1px dashed rgba(0, 0, 0, 1);
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
.remove-segs svg {
    color: red;
    position: absolute;
    height: 20px;
    left: 0%;
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

.search svg {
    position: absolute;
    left: 20%;
    top: 45%;
    transform: translateY(-50%);
    height: 20px;
    width: 20px;
    color: #fff;
}
</style>

