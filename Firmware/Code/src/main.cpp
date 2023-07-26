#include "WiFiUser.h"     //  连接wifi热点选择配置网络
#include "displaystyle.h" //  展示样式

// //填写WIFI入网信息
// const char *ssid = "zp-laptop";     // WIFI账户
// const char *password = "cugautozp"; // WIFI密码

#define NTP1 "ntp1.aliyun.com"
#define NTP2 "ntp2.aliyun.com"
#define NTP3 "ntp3.aliyun.com"

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP,"ntp.ntsc.ac.cn");

#define Key0 4  //  A
#define Key1 5  //  B
#define Key2 8  // x
#define Key3 9  // y
#define Key4 19 // o 暂时没有使用

// ST7735 width height
#define DISPLAY_WIDTH 160
#define DISPLAY_HEIGHT 80

int64_t stylenum = 1;
int64_t stylenum1 = 1;

uint8_t secondsCounter = 0;
uint8_t secondsStatus = 0;
uint8_t prevHours, prevMinutes;
struct tm timeinfo;

uint8_t b = 0;

int64_t blkpwm = 512; // 背光初始状态
int64_t blkpwm1 = 0;  // 保存当前背光状态
int64_t blkpwm2 = 0;  // 附状态机状态
int64_t keyFlag = 0;  // 按键状态
int64_t keyFlag1 = 0; // 按键状态

void setClock()
{
  if (!getLocalTime(&timeinfo))
  { //如果获取失败，就开启联网模式，获取时间
    Serial.println("Failed to obtain time");

    /*
       WIFI 直接连接
    */
    // WiFi.disconnect(false);
    // WiFi.mode(WIFI_STA); //开启网络
    // WiFi.begin(ssid, password);
    // while (WiFi.status() != WL_CONNECTED)
    // {
    //   delay(500);
    //   Serial.print(".");
    // }

    // 读取之前的wifi配置
    if (!ReadWifiConfig())
    {
      ConfigWifi();
    }

    // 连接wifi
    while (!ConnectWifi())
    {
      ConfigWifi();
    }
    spilcdWriteString(&lcd[5], 0, 0, (char *)"WIFI ok!", 0xffff, 0x0000, FONT_8x8, DRAW_TO_LCD);

    configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
    return;
  }
  // Serial.println(&timeinfo, "%F %T %A"); // 格式化输出:2021-10-24 23:00:44 Sunday
  // Serial.println(timeinfo.tm_hour);
  WiFi.disconnect(true);
}

void LCD_init()
{

  ledcWrite(1, 0);
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH);
  digitalWrite(RESET_PIN, LOW);
  delay(50);
  digitalWrite(RESET_PIN, HIGH);

  for (int i = 0; i < 6; i++)
  {
    spilcdInit(&lcd[i], LCD_ST7735S_B, FLAGS_INVERT | FLAGS_SWAP_RB, 40000000, cs[i], DC_PIN, -1, -1, MISO_PIN, MOSI_PIN, SCK_PIN);
    spilcdSetOrientation(&lcd[i], LCD_ORIENTATION_180);
    lcdDrawNumber(i, 11, stylenum);
  }
  ledcWrite(1, blkpwm);
}

// void wifi_init()
// {
//   uint8_t wifiConectionAttmps = 0;
//   WiFi.mode(WIFI_STA); // wifi 连接模式
//   WiFi.begin(ssid, password);

//   Serial.print("Connecting to ");
//   Serial.print(ssid);
//   while (WiFi.status() != WL_CONNECTED & wifiConectionAttmps < 20)
//   {
//     delay(500);
//     Serial.print(".");
//     wifiConectionAttmps++;
//   }

//   if (WiFi.status() == WL_CONNECTED)
//   {
//     Serial.println("OK. WiFi connected!");
//   }
//   else
//   {
//     Serial.println("ERROR.");
//     Serial.println("Connection Failed!, please check credentials and try again.");
//   }
// }

void gethour(uint8_t stylenum)
{
  if (timeinfo.tm_hour != prevHours | stylenum1 != stylenum)
  {
    prevHours = timeinfo.tm_hour;
    // Serial.println(timeinfo.tm_hour);
    if (timeinfo.tm_hour < 10)
    {
      lcdDrawNumber(0, 0, stylenum);
      lcdDrawNumber(1, timeinfo.tm_hour, stylenum);
    }
    else if (timeinfo.tm_hour < 20)
    {
      lcdDrawNumber(0, 1, stylenum);
      lcdDrawNumber(1, timeinfo.tm_hour - 10, stylenum);
    }
    else
    {
      lcdDrawNumber(0, 2, stylenum);
      lcdDrawNumber(1, timeinfo.tm_hour - 20, stylenum);
    }
  }
}

void getmin(uint8_t stylenum)
{
  if (timeinfo.tm_min != prevMinutes | stylenum1 != stylenum)
  {
    prevMinutes = timeinfo.tm_min;
    // Serial.println(timeinfo.tm_min);
    if (timeinfo.tm_min < 10)
    {
      lcdDrawNumber(3, 0, stylenum);
      lcdDrawNumber(4, timeinfo.tm_min, stylenum);
    }
    else if (timeinfo.tm_min < 20)
    {
      lcdDrawNumber(3, 1, stylenum);
      lcdDrawNumber(4, timeinfo.tm_min - 10, stylenum);
    }
    else if (timeinfo.tm_min < 30)
    {
      lcdDrawNumber(3, 2, stylenum);
      lcdDrawNumber(4, timeinfo.tm_min - 20, stylenum);
    }
    else if (timeinfo.tm_min < 40)
    {
      lcdDrawNumber(3, 3, stylenum);
      lcdDrawNumber(4, timeinfo.tm_min - 30, stylenum);
    }
    else if (timeinfo.tm_min < 50)
    {
      lcdDrawNumber(3, 4, stylenum);
      lcdDrawNumber(4, timeinfo.tm_min - 40, stylenum);
    }
    else
    {
      lcdDrawNumber(3, 5, stylenum);
      lcdDrawNumber(4, timeinfo.tm_min - 50, stylenum);
    }
  }
}

void getmin1(uint8_t stylenum)
{
  if (timeinfo.tm_min != prevMinutes | stylenum1 != stylenum)
  {
    prevMinutes = timeinfo.tm_min;
    // Serial.println(timeinfo.tm_min);
    if (timeinfo.tm_min < 10)
    {
      lcdDrawNumber(2, 0, stylenum);
      lcdDrawNumber(3, timeinfo.tm_min, stylenum);
    }
    else if (timeinfo.tm_min < 20)
    {
      lcdDrawNumber(2, 1, stylenum);
      lcdDrawNumber(3, timeinfo.tm_min - 10, stylenum);
    }
    else if (timeinfo.tm_min < 30)
    {
      lcdDrawNumber(2, 2, stylenum);
      lcdDrawNumber(3, timeinfo.tm_min - 20, stylenum);
    }
    else if (timeinfo.tm_min < 40)
    {
      lcdDrawNumber(2, 3, stylenum);
      lcdDrawNumber(3, timeinfo.tm_min - 30, stylenum);
    }
    else if (timeinfo.tm_min < 50)
    {
      lcdDrawNumber(2, 4, stylenum);
      lcdDrawNumber(3, timeinfo.tm_min - 40, stylenum);
    }
    else
    {
      lcdDrawNumber(2, 5, stylenum);
      lcdDrawNumber(3, timeinfo.tm_min - 50, stylenum);
    }
  }
}

void getsec(uint8_t stylenum)
{
  if (timeinfo.tm_sec != prevMinutes | stylenum1 != stylenum)
  {
    prevMinutes = timeinfo.tm_sec;
    Serial.println(timeinfo.tm_sec);
    if (timeinfo.tm_sec < 10)
    {
      lcdDrawNumber(4, 0, stylenum);
      lcdDrawNumber(5, timeinfo.tm_sec, stylenum);
    }
    else if (timeinfo.tm_sec < 20)
    {
      lcdDrawNumber(4, 1, stylenum);
      lcdDrawNumber(5, timeinfo.tm_sec - 10, stylenum);
    }
    else if (timeinfo.tm_sec < 30)
    {
      lcdDrawNumber(4, 2, stylenum);
      lcdDrawNumber(5, timeinfo.tm_sec - 20, stylenum);
    }
    else if (timeinfo.tm_sec < 40)
    {
      lcdDrawNumber(4, 3, stylenum);
      lcdDrawNumber(5, timeinfo.tm_sec - 30, stylenum);
    }
    else if (timeinfo.tm_sec < 50)
    {
      lcdDrawNumber(4, 4, stylenum);
      lcdDrawNumber(5, timeinfo.tm_sec - 40, stylenum);
    }
    else
    {
      lcdDrawNumber(4, 5, stylenum);
      lcdDrawNumber(5, timeinfo.tm_sec - 50, stylenum);
    }
  }
}

void clkcolon(uint8_t stylenum )
{

  // if 
 
  if ((stylenum1 != stylenum) | (secondsCounter > 25 & secondsStatus == 0) )
  {
    lcdDrawNumber(2, 10, stylenum);
    // lcdDrawNumber(6,10);
    secondsStatus = 1;
    secondsCounter = 0;
  }
  else if (  (secondsCounter > 25 & secondsStatus == 1) | (stylenum1 != stylenum))
  {
    lcdDrawNumber(2, 11, stylenum);
    // lcdDrawNumber(6,11);
    secondsStatus = 0;
    secondsCounter = 0;
  }

  delay(20);
  secondsCounter++;

  // if (stylenum1 != stylenum)
  // {
  //   secondsCounter = 0;
  //   secondsStatus = 0;
  // }


}

// void KeyScan()
// {

//   if (keyFlag == 1)
//   {
//     // 检查按键是否释放
//     if (digitalRead(Key0) == 0)
//       return;
//     else if (digitalRead(Key1) == 0)
//       return;
//     else if (digitalRead(Key2) == 0)
//       return;
//     else if (digitalRead(Key3) == 0)
//       return;
//     else if (digitalRead(Key4) == 0)
//       return;
//     else
//       keyFlag = 0; //按键已经释放
//   }

//   else
//   {
//     if (digitalRead(Key0) == 0)
//     {
//       keyFlag = 1;
//       stateFlag = stateFlag + 20;
//       if (stateFlag > 1024)
//         stateFlag = 0;
//       return;
//     }
//     else if (digitalRead(Key1) == 0)
//     {
//       keyFlag = 1;
//       if (stateFlag > 0)
//         stateFlag = stateFlag - 20;
//       else
//         stateFlag = 1024;
//       return;
//     }
//     else if (digitalRead(Key2) == 0)
//     {
//       keyFlag = 1;
//       if (b == 0)
//         b = 1;
//       else
//         b = 0;

//       return;
//     }
//     else if (digitalRead(Key3) == 0)
//     {
//       keyFlag = 1;

//       stateFlag2 = stateFlag2 + 1;
//       if (stateFlag2 > 2)
//         stateFlag2 = 0;
//       return;
//     }
//     else if (digitalRead(Key4) == 0)
//     {
//       keyFlag = 1;

//       if (stateFlag > 0)
//       {
//         a = stateFlag;
//         stateFlag = 0;
//       }
//       else
//         stateFlag = a;
//       return;

//       if (stateFlag > 0)
//       {
//         a = stateFlag;
//         stateFlag = 0;
//       }
//       else
//         stateFlag = a;
//       return;
//     }
//   }
// }

void KeyScan()
{

  if (keyFlag == 0)
  {
    // 检查按键是否释放
    if (digitalRead(Key0) == 0)
    {

      spilcdWriteString(&lcd[5], 0, 40, (char *)"Seting", 0xffff, 0x0000, FONT_8x8, DRAW_TO_LCD);
      keyFlag = 1;
      return;
    }
    else if (digitalRead(Key1) == 0)
      return;
    else if (digitalRead(Key2) == 0)
      return;
    else if (digitalRead(Key3) == 0)
      return;
    else if (digitalRead(Key4) == 0)
      return;
    else
      keyFlag = 0; //按键已经释放
  }
  else if (keyFlag == 1)
  {
    if (keyFlag1 == 1)
    {
      if (digitalRead(Key0) == 0)
        return;
      else if (digitalRead(Key1) == 0)
        return;
      else if (digitalRead(Key2) == 0)
        return;
      else if (digitalRead(Key3) == 0)
        return;
      else if (digitalRead(Key4) == 0)
        return;
      else
        keyFlag1 = 0; //按键已经释放
    }
    else if (keyFlag1 == 0)
    {
      if (digitalRead(Key0) == 0)
      {
        keyFlag1 = 1;
        blkpwm = blkpwm + 20;
        if (blkpwm > 1024)
          blkpwm = 0;
        return;
      }
      else if (digitalRead(Key1) == 0)
      {
        keyFlag1 = 1;
        if (blkpwm > 0)
          blkpwm = blkpwm - 20;
        else
          blkpwm = 1024;
        return;
      }
      else if (digitalRead(Key2) == 0)
      {
        keyFlag1 = 1; 
        stylenum1 =stylenum;
        stylenum = stylenum + 1;
        
        if (stylenum > 8) 
          stylenum = 0;
        return;
      }
      else if (digitalRead(Key3) == 0)
      {
        keyFlag1 = 1;
        stylenum1 =stylenum;
        stylenum = stylenum - 1;
        if (stylenum < 0)       
          stylenum = 8;
        return;
      }
      else if (digitalRead(Key4) == 0)
      {
        keyFlag1 = 1;

        if (blkpwm > 0)
        {
          blkpwm1 = blkpwm;
          blkpwm = 0;
        }
        else
          blkpwm = blkpwm1;
        return;
      }
    }
  }
}

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  pinMode(11, OUTPUT);
  ledcSetup(1, 1000, 10);
  ledcAttachPin(11, 1);
  ledcWrite(1, blkpwm);

  pinMode(Key0, INPUT_PULLUP);
  pinMode(Key1, INPUT_PULLUP);
  pinMode(Key2, INPUT_PULLUP);
  pinMode(Key3, INPUT_PULLUP);
  pinMode(Key4, INPUT_PULLUP);

  LCD_init(); // 屏幕初始化

  // lcdDrawFlag(5, 3); //

  // wifi_init();                               // wifi初始化
  configTime(8 * 3600, 0, NTP1, NTP2, NTP3); // 时区设定 北京时间为 GTM +8
  setClock();
  // 读取之前的wifi配置
    if ( !ReadWifiConfig() )
    {
        ConfigWifi();
    }

    // 连接wifi
    while( !ConnectWifi() )
    {
        ConfigWifi();
    }

  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF); //关闭网络

  // Serial.println("WiFi disconnected!");
  // timeClient.begin();
  // timeClient.setTimeOffset(8*3600);     // 时区设定 北京时间为 GTM +8
  // timeClient.update();

  prevHours = 60;
  prevMinutes = 60;
}

void loop()
{

  Serial.println(stylenum);
  // Serial.println("up: ");
  KeyScan();
  ledcWrite(1, blkpwm);
  // Serial.print(blkpwm);
  setClock();

  switch (b)
  {
  case 0:
    gethour(stylenum);
    getmin(stylenum);
    clkcolon(stylenum);
    lcdDrawNumber(5, 12, stylenum);
    stylenum1 = stylenum;
    Serial.println(stylenum1);
    break;

  case 1:
    gethour(stylenum);

    // getmin();

    getmin1(stylenum);
    //
    getsec(stylenum);
    break;
  }
}
