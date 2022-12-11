#include "common.h"
#include "reg51.h"

enum calculatorKey
{
    keyPlus = 5,
    keyMinus = 4,
    keyMultiply = 0xa,
    keyDivide = 0xb,
    keyEqual = 0xd,
    keyToZero = 0xf // keyDot=0xf
};
code uint8_t key2num[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                            0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

int8_t matrixKeyScan(void);            // 矩阵按键.c
void smgShowIntNumInLoop(int32_t num); // 数码管.c

int main()
{
    int8_t keyVal;
    int32_t leftNum = 0, inputNum = 0;
    uint8_t state = keyPlus;
    int32_t displayNum = 0;

    while (1)
    {
        keyVal = matrixKeyScan();
        if (!(keyVal & 0x80))
        {
            switch (keyVal)
            {
            case keyPlus:
            case keyMinus:
            case keyMultiply:
            case keyDivide:
                leftNum += inputNum;
                displayNum = inputNum = 0;
                state = keyVal;
                break;
            case keyEqual:
                switch (state)
                {
                case keyPlus:
                    displayNum = leftNum + inputNum;
                    break;
                case keyMinus:
                    displayNum = leftNum - inputNum;
                    break;
                case keyMultiply:
                    displayNum = leftNum * inputNum;
                    break;
                case keyDivide:
                    displayNum = leftNum / inputNum;
                    break;
                default:
                    break;
                }
                inputNum = 0;
                leftNum = displayNum;
                break;

            case keyToZero:
                leftNum = inputNum = displayNum = 0;
                state = keyPlus;
                break;

            default:
                inputNum *= 10;
                inputNum += key2num[keyVal];
                displayNum = inputNum;
                break;
            }
        }
        smgShowIntNumInLoop(displayNum);
    }
}
