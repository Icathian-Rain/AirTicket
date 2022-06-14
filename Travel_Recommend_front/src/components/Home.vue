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
import axios from 'axios';

const instance = axios.create({
    baseURL: '127.0.0.1:8080',
    timeout: 10000,
    headers: {
        'Content-Type': 'application/json'
    }
});

export default {
    setup() {
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
                    value: "AQG",
                    label: "安庆(AQG)",
                },
                {
                    value: "AOG",
                    label: "鞍山(AOG)",
                },
                {
                    value: "AVA",
                    label: "安顺(AVA)",
                },
                {
                    value: "AEB",
                    label: "百色(AEB)",
                },
                {
                    value: "BSD",
                    label: "保山(BSD)",
                },
                {
                    value: "BAV",
                    label: "包头(BAV)",
                },
                {
                    value: "BHY",
                    label: "北海(BHY)",
                },
                {
                    value: "PEK",
                    label: "北京首都(PEK)",
                },
                {
                    value: "BFU",
                    label: "蚌埠(BFU)",
                },
                {
                    value: "CGQ",
                    label: "长春(CGQ)",
                },
                {
                    value: "CGD",
                    label: "常德(CGD)",
                },
                {
                    value: "CSX",
                    label: "长沙(CSX)",
                },
                {
                    value: "CZX",
                    label: "常州(CZX)",
                },
                {
                    value: "CTU",
                    label: "成都(CTU)",
                },
                {
                    value: "CIF",
                    label: "赤峰(CIF)",
                },
                {
                    value: "CKG",
                    label: "重庆(CKG)",
                },
                {
                    value: "DLU",
                    label: "大理(DLU)",
                },
                {
                    value: "DLC",
                    label: "大连(DLC)",
                },
                {
                    value: "DNH",
                    label: "敦煌(DNH)",
                },
                {
                    value: "ENH",
                    label: "恩施(ENH)",
                },
                {
                    value: "FUO",
                    label: "佛山(FUO)",
                },
                {
                    value: "FUG",
                    label: "阜阳(FUG)",
                },
                {
                    value: "HMI",
                    label: "哈密(HMI)",
                },
                {
                    value: "HGH",
                    label: "杭州(HGH)",
                },
                {
                    value: "HZG",
                    label: "汉中(HZG)",
                },
                {
                    value: "HFE",
                    label: "合肥(HFE)",
                },
                {
                    value: "HEK",
                    label: "黑河(HEK)",
                },
                {
                    value: "HNY",
                    label: "衡阳(HNY)",
                },
                {
                    value: "TXN",
                    label: "黄山(TXN)",
                },
                {
                    value: "HET",
                    label: "呼和浩特(HET)",
                },
                {
                    value: "HUZ",
                    label: "徽州(HUZ)",
                },
                {
                    value: "JMU",
                    label: "佳木斯(JMU)",
                },
                {
                    value: "KNC",
                    label: "吉安(KNC)",
                },
                {
                    value: "JGN",
                    label: "嘉峪关(JGN)",
                },
                {
                    value: "JIL",
                    label: "吉林(JIL)",
                },
                {
                    value: "TNA",
                    label: "济南(TNA)",
                },
                {
                    value: "JDZ",
                    label: "景德镇(JDZ)",
                },
                {
                    value: "JNG",
                    label: "济宁(JNG)",
                },
                {
                    value: "JNZ",
                    label: "锦州(JNZ)",
                },
                {
                    value: "JIU",
                    label: "九江(JIU)",
                },
                {
                    value: "CHW",
                    label: "酒泉(CHW)",
                },
                {
                    value: "JZH",
                    label: "九寨沟(JZH)",
                },
                {
                    value: "KHG",
                    label: "喀什(KHG)",
                },
                {
                    value: "KRY",
                    label: "克拉玛依(KRY)",
                },
                {
                    value: "KRL",
                    label: "库尔勒(KRL)",
                },
                {
                    value: "KMG",
                    label: "昆明(KMG)",
                },
                {
                    value: "LHW",
                    label: "兰州(LHW)",
                },
                {
                    value: "LXA",
                    label: "拉萨(LXA)",
                },
                {
                    value: "LYG",
                    label: "连云港(LYG)",
                },
                {
                    value: "LJG",
                    label: "丽江(LJG)",
                },
                {
                    value: "LYI",
                    label: "临沂(LYI)",
                },
                {
                    value: "LHN",
                    label: "梨山(LHN)",
                },
                {
                    value: "LZH",
                    label: "柳州(LZH)",
                },
                {
                    value: "LYA",
                    label: "洛阳(LYA)",
                },
                {
                    value: "LUZ",
                    label: "庐山(LUZ)",
                },
                {
                    value: "LZO",
                    label: "泸州(LZO)",
                },
                {
                    value: "LUM",
                    label: "芒市(LUM)",
                },
                {
                    value: "NZH",
                    label: "满州里(NZH)",
                },
                {
                    value: "MIG",
                    label: "绵阳(MIG)",
                },
                {
                    value: "MDG",
                    label: "牡丹江(MDG)",
                },
                {
                    value: "KHN",
                    label: "南昌(KHN)",
                },
                {
                    value: "NAO",
                    label: "南充(NAO)",
                },
                {
                    value: "NKG",
                    label: "南京(NKG)",
                },
                {
                    value: "NNG",
                    label: "南宁(NNG)",
                },
                {
                    value: "NTG",
                    label: "南通(NTG)",
                },
                {
                    value: "NNY",
                    label: "南阳(NNY)",
                },
                {
                    value: "NGB",
                    label: "宁波(NGB)",
                },
                {
                    value: "PZI",
                    label: "攀枝花(PZI)",
                },
                {
                    value: "TAO",
                    label: "青岛(TAO)",
                },
                {
                    value: "IQN",
                    label: "庆阳(IQN)",
                },
                {
                    value: "SHP",
                    label: "秦皇岛(SHP)",
                },
                {
                    value: "NDG",
                    label: "齐齐哈尔(NDG)",
                },
                {
                    value: "JUZ",
                    label: "衢州(JUZ)",
                },
                {
                    value: "SYX",
                    label: "三亚(SYX)",
                },
                {
                    value: "SHA",
                    label: "上海虹桥(SHA)",
                },
                {
                    value: "PVG",
                    label: "上海浦东(PVG)",
                },
                {
                    value: "SWA",
                    label: "汕头(SWA)",
                },
                {
                    value: "SHS",
                    label: "荆沙(SHS)",
                },
                {
                    value: "SHE",
                    label: "沈阳(SHE)",
                },
                {
                    value: "SZX",
                    label: "深圳(SZX)",
                },
                {
                    value: "SJW",
                    label: "石家庄(SJW)",
                },
                {
                    value: "SZV",
                    label: "苏州(SZV)",
                },
                {
                    value: "TYN",
                    label: "太原(TYN)",
                },
                {
                    value: "TSN",
                    label: "天津(TSN)",
                },
                {
                    value: "TNH",
                    label: "通化(TNH)",
                },
                {
                    value: "TGO",
                    label: "通辽(TGO)",
                },
                {
                    value: "TEN",
                    label: "铜仁(TEN)",
                },
                {
                    value: "WEF",
                    label: "潍坊(WEF)",
                },
                {
                    value: "WEH",
                    label: "威海(WEH)",
                },
                {
                    value: "WNZ",
                    label: "温州(WNZ)",
                },
                {
                    value: "WUH",
                    label: "武汉(WUH)",
                },
                {
                    value: "WHU",
                    label: "芜湖(WHU)",
                },
                {
                    value: "HLH",
                    label: "乌兰浩特(HLH)",
                },
                {
                    value: "URC",
                    label: "乌鲁木齐(URC)",
                },
                {
                    value: "WUX",
                    label: "无锡(WUX)",
                },
                {
                    value: "WUS",
                    label: "武夷山(WUS)",
                },
                {
                    value: "WUZ",
                    label: "梧州(WUZ)",
                },
                {
                    value: "XMN",
                    label: "厦门(XMN)",
                },
                {
                    value: "XIY",
                    label: "西安(XIY)",
                },
                {
                    value: "SIA",
                    label: "咸阳(SIA)",
                },
                {
                    value: "XIC",
                    label: "西昌(XIC)",
                },
                {
                    value: "XIL",
                    label: "锡林浩特(XIL)",
                },
                {
                    value: "XNN",
                    label: "西宁(XNN)",
                },
                {
                    value: "XUZ",
                    label: "徐州(XUZ)",
                },
                {
                    value: "ENY",
                    label: "延安(ENY)",
                },
                {
                    value: "YNZ",
                    label: "盐城(YNZ)",
                },
                {
                    value: "YNT",
                    label: "烟台(YNT)",
                },
                {
                    value: "YBP",
                    label: "宜宾(YBP)",
                },
                {
                    value: "YIH",
                    label: "宜昌(YIH)",
                },
                {
                    value: "YIN",
                    label: "伊宁(YIN)",
                },
                {
                    value: "YIW",
                    label: "义乌(YIW)",
                },
                {
                    value: "LLF",
                    label: "永州(LLF)",
                },
                {
                    value: "DYG",
                    label: "张家界(DYG)",
                },
                {
                    value: "ZHA",
                    label: "湛江(ZHA)",
                },
                {
                    value: "ZAT",
                    label: "昭通(ZAT)",
                },
                {
                    value: "CGO",
                    label: "郑州(CGO)",
                },
                {
                    value: "HJJ",
                    label: "芷江(HJJ)",
                },
                {
                    value: "ZUH",
                    label: "珠海(ZUH)",
                },
                {
                    value: "ZYI",
                    label: "遵义(ZYI)",
                },
            ],
        };
    },
    methods: {
        formSubmit() {
            instance
                .get("")
                .then((response) => console.log(response))
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

