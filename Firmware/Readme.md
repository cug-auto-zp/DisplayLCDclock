# Readme

## Code

### 1. 引脚配置

主控引脚定义：

![引脚定义](../Readme-Fig/%25E5%25BC%2595%25E8%2584%259A%25E5%25AE%259A%25E4%25B9%2589.png)

上图预留给出了GPIO 0~13 和 18~19，下面进行本项目的功能复用，使用了一根SPI总线

`注意：`其中 GPIO 11 原来是给flash供电使用，所以需要解锁才能作为正常的 GPIO 使用，flash可以使用外部供电，不用担心解锁后存在的问题。解锁教程链接：[GPIO 11 解锁](https://gitee.com/dreamcmi/LuatOS-ESP32/blob/master/doc/VDD_SPI_AS_GPIO.md)

|  GPIO   |  功能复用   |               说明                |
| :-----: | :---------: | :-------------------------------: |
| GPIO 0  |     CS1     |           控制第一块LCD           |
| GPIO 1  |     CS2     |           控制第二块LCD           |
| GPIO 2  | SCL（SCK）  |             SPI的时钟             |
| GPIO 3  | MOSI（SDA） |                                   |
| GPIO 4  |      A      |            PCB-按键 A             |
| GPIO 5  |      B      |            PCB-按键 B             |
| GPIO 6  |     DC      |                                   |
| GPIO 7  |     CS3     |           控制第三块LCD           |
| GPIO 8  |      X      |            PCB-按键 X             |
| GPIO 9  |      Y      |            PCB-按键 Y             |
| GPIO 10 |     RES     |              res复位              |
| GPIO 11 |     BLK     | 屏幕背光解锁后可以使用PWM调节背光 |
| GPIO 12 |     CS4     |           控制第四块LCD           |
| GPIO 13 |     CS5     |           控制第五块LCD           |
| GPIO 18 |     CS6     |           控制第六块LCD           |
| GPIO 19 |      O      |            PCB-按键 O             |
|         |             |                                   |

### 2. code-v1.0

由于：Hardware 中 contrl-v1.0 板子有点小失误 GPIO18 控制第5块 LCD，GPIO13 控制第6块 LCD

