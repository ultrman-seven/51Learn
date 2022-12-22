# 中断系统

## 中断相关的寄存器

### 寄存器总览

|地址|符号|描述|
|-|-|-|
||||

### 寄存器描述

#### IE

<table>
    <tr align="center">
        <th>7</th><th>6</th><th>5</th><th>4</th><th>3</th><th>2</th><th>1</th><th>0</th>
    </tr>
    <tr align="center">
        <td>EA</td><td></td><td>ET2</td><td>ES</td><td>ET1</td><td>EX1</td><td>ET0</td><td>EX0</td>
    </tr>
</table>

$$
\left |
\begin{matrix}
7 \\
\color{#f6bec8}{\mathbf{EA}}
\end{matrix}
\right |
\left .
\begin{matrix}
6 \\
NULL
\end{matrix}
\right |
\left .
\begin{matrix}
5 \\
\color{#dc6b82}{\mathbf{ET2}}
\end{matrix}
\right |
\left .
\begin{matrix}
4 \\
\color{#fff143}{\mathbf{ES}}
\end{matrix}
\right |
\left .
\begin{matrix}
3 \\
\color{#dc6b82}{\mathbf{ET1}}
\end{matrix}
\right |
\left .
\begin{matrix}
2 \\
\color{#4b5cc4}{\mathbf{EX1}}
\end{matrix}
\right |
\left .
\begin{matrix}
1 \\
\color{#dc6b82}{\mathbf{ET0}}
\end{matrix}
\right |
\left .
\begin{matrix}
0 \\
\color{#4b5cc4}{\mathbf{EX0}}
\end{matrix}
\right |
$$

#### X_ICON

<table>
    <tr align="center">
        <th>7</th><th>6</th><th>5</th><th>4</th><th>3</th><th>2</th><th>1</th><th>0</th>
    </tr>
    <tr align="center">
        <td>PX3</td><td>EX3</td><td>IE3</td><td>IT3</td><td>PX2</td><td>EX2</td><td>IE2</td><td>IT2</td>
    </tr>
</table>

$$
\left |
\begin{matrix}
7 \\
\color{#FFFFFF}{\mathbf{PX3}}
\end{matrix}
\right |
\left .
\begin{matrix}
6 \\
\color{#4b5cc4}{\mathbf{EX3}}
\end{matrix}
\right |
\left .
\begin{matrix}
5 \\
\color{#4b5cc4}{\mathbf{IE3}}
\end{matrix}
\right |
\left .
\begin{matrix}
4 \\
\color{#dc6b82}{\mathbf{IT3}}
\end{matrix}
\right |
\left .
\begin{matrix}
3 \\
\color{#FFFFFF}{\mathbf{PX2}}
\end{matrix}
\right |
\left .
\begin{matrix}
2 \\
\color{#4b5cc4}{\mathbf{EX2}}
\end{matrix}
\right |
\left .
\begin{matrix}
1 \\
\color{#4b5cc4}{\mathbf{IE2}}
\end{matrix}
\right |
\left .
\begin{matrix}
0 \\
\color{#dc6b82}{\mathbf{IT2}}
\end{matrix}
\right |
$$

## 外部中断 `#4b5cc4`

## 定时器中断 `#dc6b82`

## 串口中断 `#fff143`
