#ifndef __WIFIUSER_H__
#define __WIFIUSER_H__


#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <HTTPClient.h>
#include <Preferences.h>
#include <esp_wifi.h>     //用于esp_wifi_restore() 删除保存的wifi信息



WebServer ConfigWifiServer;
String WifiSSID;
String WifiPassword;
bool bSetWifiSuccess;

HTTPClient http;


// wifi 账号密码最大长度  
#define WIFI_STR_LEN    255

// 热点名
#define AP_SSID         "ESP32C3"
#define AP_PASSWORD     ""


// 配置wifi页面 
String FrontHtml = "<!DOCTYPE html><head><meta charset='UTF-8'>"\
    "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
    "<title>config wifi</title>"
    "<style type='text/css'>body{background-color:rgb(225,250,250);font-size:18px;font-weight:600;}"
    ".formbox{position:relative;height:200px;width:350px;top:150px;margin:0 auto;background:#fff;border:5px solid #ccc;}"
    ".lineblock{display:block;}"\
    ".middle{max-width:400px; text-align:center;}"\
    ".inputbox{display:inline-block;margin:10px 20px;height:60px;text-align:left;}"\
    ".ssidinput{margin:15px 0px;}"\
    ".submitbtn{margin:-30px auto;}"\
    ".connectBtn{width:50%;height:40px;border-radius:5px;background:#4ad0f1;font-size:20px;font-weight:600;}</style>"\
    "<script>function SelectWifi(){var select=document.getElementById('SelectSSID');var tsw=document.getElementById('tsw');if (select.options[select.selectedIndex].value=='Other'){tsw.style.display='inline-block';}else{tsw.style.display='none';}}</script>"\
    "</head><body onload='SelectWifi();'><div class='formbox'>"\
    "<form name='input' action='/' method='POST'><div class='lineblock middle inputbox'>"\
    "<div class=''>选择Wifi: <select id='SelectSSID' name='SelectSSID' onchange='SelectWifi();'>";

String AfterHtml = "<option value='Other'>隐藏的网络</option></select></div>"\
    "<div id='tsw' class='ssidinput'>SSID: <input id='wifiname' type='text' name='ssid'>"\
    "</div></div><div class='lineblock middle inputbox'>密码: <input type='text' name='password'>"\
    "</div><div class='lineblock middle submitbtn'><input class='connectBtn' type='submit' value='连接'>"\
    "</div></form></div></body></html>";




// 扫描到的wifi列表，放在html的option中 
String GetWifiOptionList()
{
    static String wifilist;
    static time_t last_time = 0;
    time_t current = time(NULL);
    if (last_time+3 < current)
    {
        wifilist = "";
        WiFiScanClass scanwifi;
        scanwifi.scanNetworks();
        while(true)
        {
            if (scanwifi.scanComplete() != WIFI_SCAN_RUNNING)
            {
                break;
            }
            delay(30);
        }

        int16_t nCount = scanwifi.scanComplete();
        if (nCount != WIFI_SCAN_FAILED)
        {
            for (int i=0; i<nCount; i++)
            {
                String ssid;
                uint8_t encType;
                int32_t rssi;
                uint8_t* bssid;
                int32_t channel;
                if (scanwifi.getNetworkInfo(i, ssid, encType, rssi, bssid, channel))
                {
                    wifilist = wifilist + "<option value='" + ssid + "'>" + ssid + "</option>";
                    Serial.println("SSID: " + ssid);
                }
            }
        }
        scanwifi.scanDelete();
        last_time = time(NULL);
    }
    return wifilist;
}

// 设置wifi页面 
void WifiConnectPage() 
{
    String arg = ConfigWifiServer.uri();
    ConfigWifiServer.send(200, "text/html", FrontHtml+GetWifiOptionList()+AfterHtml);
}

// 获取wifi配置 
void HomeConnectPage()
{
    if (ConfigWifiServer.args() == 3)
    {
        WifiSSID = ConfigWifiServer.arg(0);
        if (WifiSSID == "Other")
        {
            WifiSSID = ConfigWifiServer.arg(1);
        }
        WifiPassword = ConfigWifiServer.arg(2);
        bSetWifiSuccess = true;

        ConfigWifiServer.send(200, "text/plain", "config wait...");
    }
    else
    {
        WifiConnectPage();
    }
}



void ConfigWifi()
{
    IPAddress myIP;

    WiFi.mode(WIFI_AP);
    WiFi.disconnect();
    WiFi.setTxPower(WIFI_POWER_5dBm);
    
    // 设置热点 
    WiFi.softAP(AP_SSID, AP_PASSWORD);
    myIP = WiFi.softAPIP();
    // Serial.print("AP IP address: ");
    // Serial.println(myIP);

    // 所有dns查询都被重定向到ap热点ip 
    DNSServer dnsserver;
    dnsserver.start(53, "*", myIP);
    delay(100);
    // 拦截http请求 
    ConfigWifiServer.on("/", HTTP_POST, HomeConnectPage);
    ConfigWifiServer.onNotFound(WifiConnectPage);
    ConfigWifiServer.begin(80);
    bSetWifiSuccess = false;
    while(!bSetWifiSuccess)
    {
        // 边解析dns，边http请求处理 
        dnsserver.processNextRequest(); 
        ConfigWifiServer.handleClient();
        delay(100);
    }
    dnsserver.stop();
    ConfigWifiServer.close();
    WiFi.softAPdisconnect();
}

// nvs/SPIClass/Preferences 
bool ReadWifiConfig()
{
    Preferences prefs;
    if ( !prefs.begin("wifispace", false, "nvs") )
    {
        Serial.println("read open preferences error");
    }
    // WifiSSID = prefs.getString("ssid", "");
    // WifiPassword = prefs.getString("password", "");
   // 保存热点及密码
    prefs.putString("ssid", WifiSSID);
    prefs.putString("password", WifiPassword);
    prefs.end();

    // Serial.printf("read ssid: %s, password: %s\n", WifiSSID.c_str(), WifiPassword.c_str());

    if (WifiSSID.length()>0)
    {
        return true;
    }
    return false;    
}


bool ConnectWifi()
{
    bool conn_result = false;
    if (WifiSSID.length() == 0)
    {
        return conn_result;
    }
    
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    WiFi.setTxPower(WIFI_POWER_5dBm);

    WiFi.begin(WifiSSID.c_str(), WifiPassword.c_str());

    while (true) {
        // 查询连接结果 
        int status = WiFi.status();
        if (
            status == WL_CONNECT_FAILED || 
            status == WL_NO_SSID_AVAIL || 
            status == WL_CONNECTION_LOST
            )
        {
            conn_result = false;
            break;
        }
        else if (status == WL_CONNECTED)
        {
            conn_result = true;
            Serial.print("\nWiFi connected, IP address:");
            Serial.println(WiFi.localIP());
            delay(500);
            break;
        }
        Serial.println(status);
    }
    return conn_result;
}



#endif
