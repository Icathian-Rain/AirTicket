<template>
    <div class="home" @click="menuVisible = false">
        <div class="button" @click="reset">
            <div class="button-icon">
                <svg
                    t="1656147758001"
                    class="icon"
                    viewBox="0 0 1024 1024"
                    version="1.1"
                    xmlns="http://www.w3.org/2000/svg"
                    p-id="2345"
                    width="200"
                    height="200"
                >
                    <path
                        d="M510.37806 337.803609c-98.010221 0-177.748287 78.842673-177.748287 175.75284 0 96.91426 79.738066 175.763073 177.748287 175.763073 9.537214 0 19.620873-0.978281 31.797194-3.088338 18.196431-3.281743 30.290887-20.538779 26.963095-38.471197-2.924609-15.732309-16.693194-27.152407-32.747845-27.152407-2.071172 0-4.15974 0.196475-6.123464 0.563842-7.937786 1.402953-14.233166 2.056845-19.807115 2.056845-61.159942 0-110.915136-49.201585-110.915136-109.671819 0-60.467163 49.679469-109.661585 110.747313-109.661585 61.116963 0 110.832248 49.194422 110.832248 109.661585 0 5.892197-0.656963 12.0832-2.088568 19.531845-3.327792 17.928325 8.769734 35.189454 26.959002 38.464033 2.006703 0.360204 4.045129 0.546446 6.070252 0.546446 16.204054 0 30.019711-11.43033 32.832779-27.116591 2.13871-11.45182 3.13848-21.435195 3.13848-31.41857 0.042979-46.873564-18.435884-90.990341-52.033074-124.223233C602.407056 356.106464 557.790906 337.803609 510.37806 337.803609z"
                        p-id="2346"
                    ></path>
                    <path
                        d="M938.476161 432.79917c-2.185782-11.426237-11.037381-20.499893-22.563902-23.12058-41.909505-9.508561-76.781734-34.929534-98.185206-71.550593-21.334911-36.560684-26.191522-79.099523-13.68979-119.709429 3.52836-11.123338 0.007163-23.235191-8.951883-30.840402-41.860387-35.721573-89.536222-62.938448-141.695163-80.885192-3.152806-1.088798-6.437619-1.639337-9.776667-1.639337-8.256034 0-16.182564 3.431146-21.724791 9.376555-29.236881 31.04404-68.840878 48.140417-111.5107 48.140417-42.673915 0-82.305541-17.125029-111.607914-48.230468-7.877411-8.333806-20.510126-11.512195-31.580253-7.726985-52.483328 18.171871-100.131535 45.416376-141.640927 80.988546-8.815783 7.591909-12.322653 19.620873-8.934486 30.67258 12.586666 40.645722 7.759731 83.180468-13.597693 119.78106-21.306258 36.5965-56.149834 62.006216-98.17395 71.561849-11.540847 2.709715-20.396539 11.812023-22.559808 23.166629-5.228071 27.169803-7.877411 54.346769-7.877411 80.770582 0 26.426883 2.64934 53.603849 7.873318 80.763418 2.174526 11.411911 11.023054 20.488637 22.552645 23.12058 41.913599 9.512654 76.785827 34.922371 98.19237 71.547523 21.349237 36.59343 26.177196 79.128175 13.583366 119.795387-3.363607 10.969842 0.121773 23.013133 8.973372 30.758538 41.84913 35.707246 89.494267 62.920028 141.662417 80.902588 11.466146 3.885494 23.738657 0.549515 31.454386-7.680936 29.29828-31.091112 68.925812-48.216141 111.593588-48.216141s82.302471 17.125029 111.560842 48.183396c5.556553 5.955642 13.494339 9.380648 21.782096 9.380648 3.27765 0 6.537903-0.520863 9.829879-1.599428 52.126194-17.968234 99.774401-45.184085 141.652184-80.912821 8.791224-7.577582 12.308327-19.628036 8.94165-30.758538-12.597923-40.678468-7.745405-83.20605 13.672394-119.773897 21.324678-36.625152 56.192813-62.030775 98.19237-71.547523 11.390421-2.592035 20.23588-11.633968 22.549575-23.106254 5.223978-27.184129 7.870248-54.358025 7.870248-80.770582C946.342316 487.171522 943.697069 459.965903 938.476161 432.79917zM728.572524 789.878798c-26.02677 20.157085-54.736649 36.553521-85.487 48.818869-36.682457-32.144094-83.60207-49.779753-132.792399-49.779753-48.926316 0-95.838765 17.635659-132.767839 49.786916-30.744211-12.262278-59.45716-28.655643-85.491093-48.812729 9.894348-47.441499 1.889023-96.449679-22.763446-138.627291-24.448832-41.966811-63.427588-73.339332-110.186542-88.840374-2.381234-16.343223-3.584642-32.758078-3.584642-48.869011 0-16.043395 1.203408-32.451086 3.584642-48.851615 46.612621-15.389502 85.584214-46.758953 110.186542-88.850607 24.523533-42.024116 32.525788-91.033319 22.74912-138.620128 26.0237-20.149922 54.735625-36.543288 85.494163-48.815799 36.821627 32.201399 83.73817 49.861618 132.778072 49.861618 49.194422 0 96.109941-17.635659 132.792399-49.779753 30.751375 12.269441 59.45716 28.662807 85.48086 48.812729-9.809413 47.63388-1.835811 96.634898 22.667256 138.620128 24.445762 41.966811 63.416332 73.343425 110.182448 88.850607 2.381234 16.386202 3.584642 32.801057 3.584642 48.940642 0.143263 15.443737-1.031493 31.797194-3.499707 48.701189-46.763047 15.504112-85.73771 46.873564-110.186542 88.836281C726.84416 693.189665 718.845998 742.190683 728.572524 789.878798z"
                        p-id="2347"
                    ></path>
                </svg>
            </div>
            <div class="button-text">随机重置数据</div>
        </div>
        <form class="search-form">
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
                            v-model="seg.departTime"
                            type="date"
                            placeholder="选择出发日期"
                            value-format="YYYYMMDD000000"
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
        <result :res_data="res_data" :options="options" v-if="res_data !== null "/>
    </div>
</template>

<script >
import axios from "axios";
import result from "./result.vue";

axios.defaults.baseURL = "/api";

export default {
    setup() {},
    data() {
        return {
            // 乘客数
            passenger: 1,
            // 代理人选项
            agentOptions: [
                "SHS",
                "XIC",
                "WUX",
                "SHE",
                "NNG",
                "DNH",
                "SZX",
                "AOG",
                "XUZ",
                "CGQ",
            ],
            // 代理人
            agent: [],
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
            res_data: null,
        };
    },
    methods: {
        reset() {
            axios
                .get("/reset")
                .then((response) => {
                    if(response.status === 200)
                    {
                        alert("重置成功");
                    } else {
                        alert("重置失败");
                    }
                })
                .catch((err) => {
                    console.log(err);
                });
        },
        formSubmit() {
            let req_data = {
                N: Number(this.passenger),
                M: this.segments.length,
                agency: [],
                date: [],
                sCity: [],
                dCity: [],
            };
            for (let i = 0; i < this.agent.length; i++) {
                req_data.agency.push(this.agent[i] + "001");
            }
            for (let i = 0; i < this.segments.length; i++) {
                req_data.date.push(this.segments[i].departTime);
                req_data.sCity.push(this.segments[i].depart);
                req_data.dCity.push(this.segments[i].arrival);
            }
            axios
                .post("/query", req_data, {
                    headers: {
                        "Content-Type": "text/plain",
                    },
                })
                .then((response) => {
                    if(response.data.meta.status == 200) {
                        this.res_data = response.data.data;
                    } else {
                        this.res_data = null;
                        alert("查询失败");
                    }
                }
                )
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
    components: {
        result,
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

.button {
    user-select: none;
    cursor: pointer;
    /* background-color: #090723; */
    position: fixed;
    width: 150px;
    height: 10px;
    top: 20px;
    right: 20px;
    z-index: 1;
    border-radius: 5px;
    padding: 10px;
}
.button-icon {
    position: relative;
    display: inline-block;
    height: 20px;
}
.button-icon svg {
    width: 100%;
    height: 100%;
}

.button-text {
    height: 100%;
    display: inline-block;
    font-size: 20px;
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

.passenger-box {
    /* 相对定位 */
    position: relative;
    display: flex;
    /* 宽度 100% */
    width: 100%;
    /* 不换行 */
    flex-wrap: nowrap;
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
    width: 80px;
}

.agent-box {
    width: 100%;
    display: flex;
    flex-direction: row;
    align-items: center;
    margin-bottom: 10px;
}

.agent-box span,
.el-checkbox-group {
    display: inline-block;
}
.agent-box span {
    position: relative;
    margin-right: 35px;
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

