#include "common.h"
#include "reg51.h"

/**
 * According to the user hardware schematic diagram,
 *  modify the definition of the following three pins
 */
// #define hc595_data P34
// #define hc595_transfer P36
// #define hc595_out P35
sbit hc595_data = def_s_bit(P3, 4);
sbit hc595_transfer = def_s_bit(P3, 6);
sbit hc595_out = def_s_bit(P3, 5);


/**
 * @brief set the output of hc595. 
 * 
 * This function will set up the parallel output of the hc595.
 * Before using this function, you need to make sure that 
 * the 3 pins of hc595 are set to be consistent with the hardware schematic.
 * @param uint8_t dat
 * @return void
 */
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
            while (dl--)
                _nop_();
        }
    }
}
