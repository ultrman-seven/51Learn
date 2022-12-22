# 中断系统

## 中断相关的寄存器

### 寄存器总览

|地址|描述|符号|7|6|5|4|3|2|1|0|
| ---- | ---- | :---: |-|-|-|-|-|-|-|-|
|0xa8|中断允许|IE| $\color{#f6bec8}{\mathbf{EA}}$   || $\color{#dc6b82}{\mathbf{ET2}}$  | $\color{#ca6924}{\mathbf{ES}}$  | $\color{#dc6b82}{\mathbf{ET1}}$  | $\color{#4b5cc4}{\mathbf{EX1}}$  | $\color{#dc6b82}{\mathbf{ET0}}$  | $\color{#4b5cc4}{\mathbf{EX0}}$  |
|0xc0|辅助中断控制| XICON | $\color{#4b5cc4}{\mathbf{PX3}}$  | $\color{#4b5cc4}{\mathbf{EX3}}$  | $\color{#4b5cc4}{\mathbf{IE3}}$  | $\color{#dc6b82}{\mathbf{IT3}}$ | $\color{#4b5cc4}{\mathbf{PX2}}$  | $\color{#4b5cc4}{\mathbf{EX2}}$  | $\color{#4b5cc4}{\mathbf{IE2}}$  | $\color{#dc6b82}{\mathbf{IT2}}$  |
|0xb8|中断优先级|IP||| $\color{#dc6b82}{\mathbf{PT2}}$  | $\color{#ca6924}{\mathbf{PS}}$  | $\color{#dc6b82}{\mathbf{PT1}}$  | $\color{#4b5cc4}{\mathbf{PX1}}$  | $\color{#dc6b82}{\mathbf{PT0}}$  | $\color{#4b5cc4}{\mathbf{PX0}}$  |
|0xb7|中断优先级|IPH| $\color{#4b5cc4}{\mathbf{PX3H}}$ | $\color{#4b5cc4}{\mathbf{PX2H}}$ | $\color{#dc6b82}{\mathbf{PT2H}}$ | $\color{#ca6924}{\mathbf{PSH}}$ | $\color{#dc6b82}{\mathbf{PT1H}}$ | $\color{#4b5cc4}{\mathbf{PX1H}}$ | $\color{#dc6b82}{\mathbf{PT0H}}$ | $\color{#4b5cc4}{\mathbf{PX0H}}$ |
|0x88|定时器控制|TCON|$\color{#dc6b82}{\mathbf{TF1}}$|$\color{#dc6b82}{\mathbf{TR1}}$|$\color{#dc6b82}{\mathbf{TF0}}$|$\color{#dc6b82}{\mathbf{TR0}}$|$\color{#4b5cc4}{\mathbf{IE1}}$|$\color{#dc6b82}{\mathbf{IT1}}$|$\color{#4b5cc4}{\mathbf{IE0}}$|$\color{#dc6b82}{\mathbf{IT0}}$|
|0x98|串口控制|SCON|$$|$$|$$|$$|$$|$$|$$|$$|
|0xc8|定时器控制|T2CON| $\color{#dc6b82}{\mathbf{TF2}}$| $\color{#dc6b82}{\mathbf{EXF2}}$| $\color{#dc6b82}{\mathbf{RCLK}}$| $\color{#dc6b82}{\mathbf{TCLK}}$| $\color{#dc6b82}{\mathbf{T}}$| $\color{#dc6b82}{\mathbf{T}}$| $\color{#dc6b82}{\mathbf{T}}$| $\color{#dc6b82}{\mathbf{T}}$|

## 外部中断 $\color{#4b5cc4}{\spadesuit}$

## 定时器中断 $\color{#dc6b82}{\spadesuit}$

## 串口中断 $\color{#ca6924}{\spadesuit}$
