#include "oled.h"

// 骚
// printf重定向
#include "STDIO.H"
//char fputc(int c, FILE *stream)
char putchar (char c)
{
    OLED_putchar(c);
}


int main()
{
    int jbl = 123;
    OLED_Init();
    OLED_print("sjjNB\n!@#$\n");
    printf("sjj's jb is: %dcm", jbl);
    while (1)
    {
    }
}
