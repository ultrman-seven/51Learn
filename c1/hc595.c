#include "common.h"
#include "reg51.h"

sbit hc595_data = def_s_bit(P3, 4);
sbit hc595_transfer = def_s_bit(P3, 6);
sbit hc595_out = def_s_bit(P3, 5);

void hc595OutputData(uint8_t dat)
{

    uint8_t cnt = 8;
    while (cnt--)
    {
        hc595_data = dat & 0x01;
        _nop_();

        hc595_transfer = 0;
        _nop_();
        hc595_transfer = 1;
        _nop_();
        dat >>= 1;
    }

    hc595_out = 0;
    _nop_();
    hc595_out = 1;
    _nop_();
    hc595_out = 0;
    _nop_();
}

int main()
{
    uint8_t hcData[] = {0x60, 0xf0, 0xe0, 0xff, 0x7f, 0xf0, 0xf0, 0x60};
    while (1)
    {
        uint8_t cnt = 8;
        uint8_t dl;
        while (cnt--)
        {
            dl = 100;
            hc595OutputData(hcData[cnt]);
            P0 = ~((0x01) << cnt);
            while(dl--)
                _nop_();
        }
        
    }
}
