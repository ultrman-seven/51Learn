#ifndef __STC90C5xAD_H_
#define __STC90C5xAD_H_

/////////////////////////////////////////////////
#ifndef __VS_CODE_
#define def_s_bit(_r, _bit) ((_r) ^ (_bit))
#else
#define def_s_bit(_r, _bit) (0)
#endif
/* The following is STC additional SFR */

/* sfr  AUXR  = 0x8e; */
/* sfr  AUXR1 = 0xa2; */
/* sfr  IPH   = 0xb7; */

sfr  P4  = 0xc0;
sbit P46  = def_s_bit( P4, 6);
sbit P45  = def_s_bit( P4, 5);
sbit P44  = def_s_bit( P4, 4);
sbit P43  = def_s_bit( P4, 3);
sbit P42  = def_s_bit( P4, 2);
sbit P41  = def_s_bit( P4, 1);
sbit P40  = def_s_bit( P4, 0);

sfr  XICON = 0xe8;

sfr  WDT_CONTR = 0xe1;

sfr ISP_DATA  = 0xe2;
sfr ISP_ADDRH = 0xe3;
sfr ISP_ADDRL = 0xe4;
sfr ISP_CMD   = 0xe5;
sfr ISP_TRIG  = 0xe6;
sfr ISP_CONTR = 0xe7;

/* Above is STC additional SFR */

/*--------------------------------------------------------------------------
REG51F.H

Header file for 8xC31/51, 80C51Fx, 80C51Rx+
Copyright (c) 1988-1999 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.

Modification according to DataSheet from April 1999
 - SFR's AUXR and AUXR1 added for 80C51Rx+ derivatives
--------------------------------------------------------------------------*/

/*  BYTE Registers  */
sfr P0   = 0x80;
sbit P00  = def_s_bit( P0, 0);
sbit P01  = def_s_bit( P0, 1);
sbit P02  = def_s_bit( P0, 2);
sbit P03  = def_s_bit( P0, 3);
sbit P04  = def_s_bit( P0, 4);
sbit P05  = def_s_bit( P0, 5);
sbit P06  = def_s_bit( P0, 6);
sbit P07  = def_s_bit( P0, 7);
sfr P1   = 0x90;
sbit P10  = def_s_bit( P1, 0);
sbit P11  = def_s_bit( P1, 1);
sbit P12  = def_s_bit( P1, 2);
sbit P13  = def_s_bit( P1, 3);
sbit P14  = def_s_bit( P1, 4);
sbit P15  = def_s_bit( P1, 5);
sbit P16  = def_s_bit( P1, 6);
sbit P17  = def_s_bit( P1, 7);
sfr P2   = 0xA0;
sbit P20  = def_s_bit( P2, 0);
sbit P21  = def_s_bit( P2, 1);
sbit P22  = def_s_bit( P2, 2);
sbit P23  = def_s_bit( P2, 3);
sbit P24  = def_s_bit( P2, 4);
sbit P25  = def_s_bit( P2, 5);
sbit P26  = def_s_bit( P2, 6);
sbit P27  = def_s_bit( P2, 7);
sfr P3   = 0xB0;
sbit P30  = def_s_bit( P3, 0);
sbit P31  = def_s_bit( P3, 1);
sbit P32  = def_s_bit( P3, 2);
sbit P33  = def_s_bit( P3, 3);
sbit P34  = def_s_bit( P3, 4);
sbit P35  = def_s_bit( P3, 5);
sbit P36  = def_s_bit( P3, 6);
sbit P37  = def_s_bit( P3, 7);
sfr PSW  = 0xD0;
sfr ACC  = 0xE0;
sfr B    = 0xF0;
sfr SP   = 0x81;
sfr DPL  = 0x82;
sfr DPH  = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr IE   = 0xA8;
sfr IP   = 0xB8;
sfr SCON = 0x98;
sfr SBUF = 0x99;

/*  80C51Fx/Rx Extensions  */
sfr AUXR   = 0x8E;
sfr AUXR1  = 0xA2;
sfr SADDR  = 0xA9;
sfr IPH    = 0xB7;
sfr SADEN  = 0xB9;
sfr T2CON  = 0xC8;
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;

/* PCA SFR
sfr CCON   = 0xD8;
sfr CMOD   = 0xD9;
sfr CCAPM0 = 0xDA;
sfr CCAPM1 = 0xDB;
sfr CCAPM2 = 0xDC;
sfr CCAPM3 = 0xDD;
sfr CCAPM4 = 0xDE;
sfr CL     = 0xE9;
sfr CCAP0L = 0xEA;
sfr CCAP1L = 0xEB;
sfr CCAP2L = 0xEC;
sfr CCAP3L = 0xED;
sfr CCAP4L = 0xEE;
sfr CH     = 0xF9;
sfr CCAP0H = 0xFA;
sfr CCAP1H = 0xFB;
sfr CCAP2H = 0xFC;
sfr CCAP3H = 0xFD;
sfr CCAP4H = 0xFE;
*/

/*  BIT Registers  */
/*  PSW   */
sbit CY    = def_s_bit( PSW, 7);
sbit AC    = def_s_bit( PSW, 6);
sbit F0    = def_s_bit( PSW, 5);
sbit RS1   = def_s_bit( PSW, 4);
sbit RS0   = def_s_bit( PSW, 3);
sbit OV    = def_s_bit( PSW, 2);
sbit F1    = def_s_bit( PSW, 1);
sbit P     = def_s_bit( PSW, 0);

/*  TCON  */
sbit TF1   = def_s_bit( TCON, 7);
sbit TR1   = def_s_bit( TCON, 6);
sbit TF0   = def_s_bit( TCON, 5);
sbit TR0   = def_s_bit( TCON, 4);
sbit IE1   = def_s_bit( TCON, 3);
sbit IT1   = def_s_bit( TCON, 2);
sbit IE0   = def_s_bit( TCON, 1);
sbit IT0   = def_s_bit( TCON, 0);

/*  IE   */
sbit EA    = def_s_bit( IE, 7);
sbit EC    = def_s_bit( IE, 6);
sbit ET2   = def_s_bit( IE, 5);
sbit ES    = def_s_bit( IE, 4);
sbit ET1   = def_s_bit( IE, 3);
sbit EX1   = def_s_bit( IE, 2);
sbit ET0   = def_s_bit( IE, 1);
sbit EX0   = def_s_bit( IE, 0);

/*  IP   */ 
/*  sbit PPC   = def_s_bit( IP, 6);
sbit PT2   = def_s_bit( IP, 5);
sbit PS    = def_s_bit( IP, 4);
sbit PT1   = def_s_bit( IP, 3);
sbit PX1   = def_s_bit( IP, 2);
sbit PT0   = def_s_bit( IP, 1);
sbit PX0   = def_s_bit( IP, 0);

/*  P3  */
sbit RD    = def_s_bit( P3, 7);
sbit WR    = def_s_bit( P3, 6);
sbit T1    = def_s_bit( P3, 5);
sbit T0    = def_s_bit( P3, 4);
sbit INT1  = def_s_bit( P3, 3);
sbit INT0  = def_s_bit( P3, 2);
sbit TXD   = def_s_bit( P3, 1);
sbit RXD   = def_s_bit( P3, 0);

/*  SCON  */
sbit SM0   = def_s_bit( SCON, 7);
sbit FE    = def_s_bit( SCON, 7);
sbit SM1   = def_s_bit( SCON, 6);
sbit SM2   = def_s_bit( SCON, 5);
sbit REN   = def_s_bit( SCON, 4);
sbit TB8   = def_s_bit( SCON, 3);
sbit RB8   = def_s_bit( SCON, 2);
sbit TI    = def_s_bit( SCON, 1);
sbit RI    = def_s_bit( SCON, 0);
             
/*  P1  */
/* PCA
sbit CEX4  = def_s_bit( P1, 7);
sbit CEX3  = def_s_bit( P1, 6);
sbit CEX2  = def_s_bit( P1, 5);
sbit CEX1  = def_s_bit( P1, 4);
sbit CEX0  = def_s_bit( P1, 3);
sbit ECI   = def_s_bit( P1, 2);
*/

sbit T2EX  = def_s_bit( P1, 1);
sbit T2    = def_s_bit( P1, 0);

/*  T2CON  */
sbit TF2    = def_s_bit( T2CON, 7);
sbit EXF2   = def_s_bit( T2CON, 6);
sbit RCLK   = def_s_bit( T2CON, 5);
sbit TCLK   = def_s_bit( T2CON, 4);
sbit EXEN2  = def_s_bit( T2CON, 3);
sbit TR2    = def_s_bit( T2CON, 2);
sbit C_T2   = def_s_bit( T2CON, 1);
sbit CP_RL2 = def_s_bit( T2CON, 0);

/*  CCON  */
/*  PCA
sbit CF     = def_s_bit( CCON, 7);
sbit CR     = def_s_bit( CCON, 6);

sbit CCF4   = def_s_bit( CCON, 4);
sbit CCF3   = def_s_bit( CCON, 3);
sbit CCF2   = def_s_bit( CCON, 2);
sbit CCF1   = def_s_bit( CCON, 1);
sbit CCF0   = def_s_bit( CCON, 0);
*/

/////////////////////////////////////////////////

#endif

