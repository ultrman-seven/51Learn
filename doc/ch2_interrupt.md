# 中断系统

## 中断相关的寄存器

### 寄存器总览

|地址|描述|符号|7|6|5|4|3|2|1|0|
| ---- | ---- | :---: |-|-|-|-|-|-|-|-|
|      |      |  IE  | $\color{#f6bec8}{\mathbf{EA}}$   | null                               | $\color{#dc6b82}{\mathbf{ET2}}$  | $\color{#fff143}{\mathbf{ES}}$  | $\color{#dc6b82}{\mathbf{ET1}}$  | $\color{#4b5cc4}{\mathbf{EX1}}$  | $\color{#dc6b82}{\mathbf{ET0}}$  | $\color{#4b5cc4}{\mathbf{EX0}}$  |
|      |      | XICON | $\color{#4b5cc4}{\mathbf{PX3}}$  | $\color{#4b5cc4}{\mathbf{EX3}}$  | $\color{#4b5cc4}{\mathbf{IE3}}$  | $\color{#dc6b82}{\mathbf{IT3}}$ | $\color{#4b5cc4}{\mathbf{PX2}}$  | $\color{#4b5cc4}{\mathbf{EX2}}$  | $\color{#4b5cc4}{\mathbf{IE2}}$  | $\color{#dc6b82}{\mathbf{IT2}}$  |
|      |      |  IP  | null                               | null                               | $\color{#dc6b82}{\mathbf{PT2}}$  | $\color{#fff143}{\mathbf{PS}}$  | $\color{#dc6b82}{\mathbf{PT1}}$  | $\color{#4b5cc4}{\mathbf{PX1}}$  | $\color{#dc6b82}{\mathbf{PT0}}$  | $\color{#4b5cc4}{\mathbf{PX0}}$  |
|      |      |  IPH  | $\color{#4b5cc4}{\mathbf{PX3H}}$ | $\color{#4b5cc4}{\mathbf{PX2H}}$ | $\color{#dc6b82}{\mathbf{PT2H}}$ | $\color{#fff143}{\mathbf{PSH}}$ | $\color{#dc6b82}{\mathbf{PT1H}}$ | $\color{#4b5cc4}{\mathbf{PX1H}}$ | $\color{#dc6b82}{\mathbf{PT0H}}$ | $\color{#4b5cc4}{\mathbf{PX0H}}$ |
|||TCON|$\color{#dc6b82}{\mathbf{TF1}}$| $$| $$|$$|$$|$$|$$|$$|
|||SCON|$$|$$|$$|$$|$$|$$|$$|$$|
|||T2CON| $$| $$| $$| $$| $$| $$| $$| $$|

## 外部中断 $\color{#4b5cc4}{\spadesuit}$

## 定时器中断 $\color{#dc6b82}{\spadesuit}$

## 串口中断 $\color{#fff143}{\spadesuit}$
