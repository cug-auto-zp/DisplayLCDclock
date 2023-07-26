#ifndef __STYLECONFIG_H__
#define __STYLECONFIG_H__

// #include "clock14SEG.h"
#include "clockBINA.h"
#include "clockButterfly.h"
#include "clockDigital.h"
#include "clockFlip.h"
#include "clockFlower.h"
#include "clockInk.h"
#include "clockLixieCyan.h"
#include "clockLixiePurple.h"
#include "clockMatrix.h"
// #include "clockNIMO.h"
#include "clockNixie.h"
#include "clockPixie.h"
#include "clockPredator.h"
#include "clockRGB.h"
#include "clockStargate.h"
#include "clockVFD.h"
// #include "clockWood.h"
// #include "clockFlags.h"

/*   屏幕引脚配置   */

#define CS1_PIN 0  // 1
#define CS2_PIN 1  // 18 //2
#define CS3_PIN 7  // 13//5 //3
#define CS4_PIN 12 // 4
#define CS5_PIN 18 // 19
#define CS6_PIN 13 // 7 //6

#define RESET_PIN 10    //    res
#define DC_PIN    6     //    DC
#define MOSI_PIN  3     //    SDA
#define SCK_PIN   2     //    SCL
#define LED_PIN   11    //    BLK   LCD背光
#define MISO_PIN -1     //    引脚为空


#define colon  10
#define space  11
#define heart  12
    



/*   style切换   */
// #define SEG14           0
#define BINA            0 // 1 
#define Butterfly       1 // 2
// #define Digital         3
#define Flip            2 // 4 
#define Flower          3 // 5
#define Ink             4 // 6
// #define LixieCyan       7
#define LixiePurple     5 // 8
// #define Matrix          9
// #define NIMO            10
#define Nixie           6 // 11
// #define Pixie           12
// #define Predator        13
#define RGB             7 // 14
// #define Stargate        15
#define VFD             8 // 16
// #define Wood            17
// #define Flags           18


#endif
