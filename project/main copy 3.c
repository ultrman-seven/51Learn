#include "oled.h"
code uint8_t char_S[16] = {
    0x00, 0x70, 0xd8, 0x8c, 0x04, 0x04, 0x0c, 0x18,
    0x00, 0x30, 0x20, 0x21, 0x21, 0x33, 0x1e, 0x00};

code uint8_t blankScreen[1024] = {0};
int main()
{
    OLED_Init();
    OLED_displayPicture(blankScreen, 0, 0, 128, 64);
    OLED_displayPicture(char_S, 0, 0, 8, 16);
    while (1)
    {
    }
}
