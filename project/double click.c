#include "common.h"
// #include "reg52.h"

#ifndef __VS_CODE_
#define def_s_bit(_r, _bit) ((_r) ^ (_bit))
#else
#define def_s_bit(_r, _bit) (0)
#endif

// 在keil里面的写法如下：(C51语法)
// sbit led1 = P2 ^ 0;
// 但是在vs会报错，因为=后面必须跟常数(C语言语法)
sbit led1 = def_s_bit(P2, 0);
sbit led2 = def_s_bit(P2, 1);
sbit led8 = def_s_bit(P2, 7);
sbit key1 = def_s_bit(P3, 1);

int main()
{
    uint8_t maxWait;
    led1 = led2 = 1;
    led8 = 1;
    while (1)
    {
        // 按下key1，led1翻转一次，led8常亮，
        // key1双击，led2翻转一次
        // 不按key1时led8长灭
        if (!key1) // 如果按下
        {
            maxWait = 50;
            delayMs(4);
            if (!key1) // 如果真的按了
            {
                led8 = 0;
                led1 = !led1; // led1Flip();   // 单机操作
                while (!key1) // 等松手
                    ;
                led8 = 1;
            }
            delayMs(4);
            while (key1 && maxWait--) // 等按下
                delayMs(5);
            if (!key1) // 有双击可能，还要判断毛刺
            {
                delayMs(4);
                if (!key1) // 真的双击了
                {
                    led8 = 0;
                    led2 = !led2; // 双击操作
                    while (!key1) // 等松手
                        ;
                }
            }
            led8 = 1;
        }
    }
}
