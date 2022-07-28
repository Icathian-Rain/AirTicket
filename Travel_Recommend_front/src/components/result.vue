<script setup>
import { ref } from "vue";

const pros = defineProps(["resData", "cityOptions"]);

const seatType = ref({
    F: "头等舱",
    C: "商务舱",
    Y: "经济舱",
});

function getSeatType(type) {
    return seatType.value[type];
}

function getDate(date) {
    let year = date.substring(0, 4);
    let month = date.substring(4, 6);
    let day = date.substring(6, 8);
    let hour = date.substring(8, 10);
    let minute = date.substring(10, 12);
    return year + "-" + month + "-" + day + " " + hour + ":" + minute;
}

function getCity(city) {
    for (let i in pros.cityOptions) {
        if (pros.cityOptions[i].value === city) {
            return pros.cityOptions[i].label;
        }
    }
}
</script>

<template>
    <div class="home">
        <span class="tips"> 搜索到 {{ pros.resData["ansNum"] }} 条结果 </span>
        <div
            class="ans"
            :id="'ans' + i"
            v-for="(ans_a, i) in pros.resData['ans']"
        >
            <div class="ans_tips">
                <span> 结果: {{ i + 1 }} </span>
                <span>
                    代理人:
                    <span v-for="(agc_a, i) in ans_a['agc']">
                        {{ agc_a }}
                    </span>
                </span>
                <span> 总价格: {{ ans_a["ticketPrice"] }} </span>
            </div>
            <div
                class="flights"
                :id="'flight' + j"
                v-for="(flight_a, j) in ans_a['flight']"
            >
                <div class="flight-box">
                    <div class="flight-tip">
                        <span> 航班号: {{ flight_a["flightNo"] }} </span>
                        <span
                            v-for="(seat, k) in flight_a['passengetSeatList']"
                        >
                            座位{{ k + 1 }}: {{ getSeatType(seat) }}
                        </span>
                    </div>
                    <div class="flight-info-box">
                        <div class="depart-box">
                            <span class="departTime">
                                {{ getDate(flight_a["takeOffTime"]) }}
                            </span>
                            <span class="departCity">
                                {{ getCity(flight_a["sCity"]) }}
                            </span>
                        </div>
                        <div class="arrow">
                            <img
                                src="../assets/icons/arrow-right.svg"
                                alt=""
                                class="arrow-right"
                            />
                        </div>
                        <div class="depart-box">
                            <span class="departTime">
                                {{ getDate(flight_a["arriveTime"]) }}
                            </span>
                            <span class="departCity">
                                {{ getCity(flight_a["dCity"]) }}
                            </span>
                        </div>
                    </div>
                    <div class="left-seat">
                        <span style="">
                            剩余座位信息:
                            <br />
                            头等舱: {{ String.fromCharCode(flight_a["seatF"]) }}
                            <br />
                            商务舱: {{ String.fromCharCode(flight_a["seatC"]) }}
                            <br />
                            经济舱: {{ String.fromCharCode(flight_a["seatY"]) }}
                        </span>
                    </div>
                    <div class="price">
                        <span> 价格: {{ flight_a["price"] }} </span>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>


<style scoped>
.home {
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
    width: 100%;
    /* 背景颜色 */
    background: #fff;
    /* 边框 */
    padding: 10px 5% 30px 5%;
    /* 圆角 */
    border-radius: 6px;
    top:100px;
}

.tips {
    /* 字体大小 */
    font-size: 20px;
    /* 字体颜色 */
    color: #333;
    /* 字体粗细 */
    font-weight: bold;
    width: 870px;
    padding-bottom: 20px;
}

.ans {
    display: flex;
    /* 横向排布 */
    flex-direction: column;
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

.ans_tips {
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 10px;
}
.flight-box {
    display: flex;
    flex-direction: row;
    align-content: center;
    justify-content: space-between;
    position: relative;
    border-radius: 6px;
    border: 1px solid #eee;
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 6%);
    padding-top: 10px;
    padding-left: 30px;
    padding-bottom: 10px;
    padding-right: 30px;
    margin-bottom: 20px;
}
.flight-box:hover {
    box-shadow: 0 0 12px 0 rgb(0 0 0 / 12%);
}

.flight-tip {
    width: auto;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
}

.flight-info-box {
    display: flex;
    flex-direction: row;
    justify-content: space-around;
    align-items: center;
}

.depart-box {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.arrow-right {
    height: 20px;
    width: 50px;
}

.price {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.price span {
    color: #0078f5;
    font: bold;
}
</style>