#include "common.h"
#include "reg51.h"

// #define __MAT_TEST_

#define matKeyPort P1

int8_t matrixKeyScan(void)
{
    uint8_t scanVal;
    uint8_t rowNum, colNum;
    // 先扫描行
    // 列(L)输出0000，看哪一行变成0
    // eg: scanVal = 10110000
    matKeyPort = 0xf0;
    scanVal = matKeyPort;
    scanVal >>= 4;
    if (scanVal >= 0xf)
        return -1;

    rowNum = 0;
    while (scanVal & 0x01)
    {
        rowNum++;
        scanVal >>= 1;
    }

    matKeyPort = ~(0x01 << (4 + rowNum));
    scanVal = matKeyPort & 0x0f;

    colNum = 0;
    while (scanVal & 0x01)
    {
        colNum++;
        scanVal >>= 1;
    }
    return rowNum * 4 + colNum;
}

#ifdef __MAT_TEST_
int main()
{
    int8_t keyNum;
    while (1)
    {
        keyNum = matrixKeyScan();
        if (keyNum >= 0)
            P2 = ~keyNum;
        else
            P2 = 0xff;
        delayMs(100);
    }
}
#endif
