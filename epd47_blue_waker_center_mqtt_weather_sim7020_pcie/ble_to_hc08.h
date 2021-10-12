#include "BLEDevice.h"
#include <String.h>
#include <Arduino.h>

//定义是否接收蓝牙通知
//实际测试可以不接收蓝牙反馈字节，能节省1-2秒时间， 调试时可加上
//#define blue_notify

class Manager_blue_to_hc08
{
  private:

    int blue_doConnect_step = 0;
    bool blue_datasend = false;

    bool check_UUID_ok=false;

    BLEScan* pBLEScan;
    BLEClient* pClient ;

    BLERemoteCharacteristic* pRemoteCharacteristic;


    bool connectToServer(BLEAddress pAddress) ;
    void send_cmd_long(String cmd);  //300字节内调用
    void send_cmd_long_long(String cmd); //大于300字节调用, 如用前一函数，会丢失或数据混乱
    bool blue_send_cmd(String cmd, float delay_sec, int min_delay_sec);

  public:

    Manager_blue_to_hc08();
    ~Manager_blue_to_hc08();

    //连接到此蓝牙地址，并发送文字信息
    //  quick 跳过蓝牙扫描这一步，直接连接， 实测对减少连接时间有限？都需要3-6秒?
    bool blue_connect_sendmsg(String txt, bool quick);

};
