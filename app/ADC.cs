P6SEL |= BIT6;
ADC12CTL0 |= ADC12ON + ADC12SHT0_9 + ADC12MSC;
ADC12CTL1 |= ADC12SHP + ADC12CONSEQ_2 + ADC12SSEL_2; // 选取MCLK
ADC12MCTL0 |= ADC12INCH_6;
//ADC12IE = BIT0;
ADC12CTL0 |= ADC12SC + ADC12ENC;




//音量播放部分
uint16_t volume = 0; // 全局变量


//volume 是12位值，需要右移9位变成3位值，最大值为7。这样结果就会最多减少2^7 = 127倍
//应该够小了

>>(volume >> 9);

//音量显示部分

//仅分成了 0 -> 7 八个档位，但是音量右移后的值是减小的倍数，需要显示的是放大的倍数。
//所以 7-volume>>9就行了，

Write_DATA(ADDR[6],NUM[8-(volume>>9)]);

//在stop_play中添加
ADC12CTL0 = 0;
