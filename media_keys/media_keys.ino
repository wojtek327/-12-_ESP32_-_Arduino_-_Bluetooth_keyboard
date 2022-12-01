#include <BleKeyboard.h>
 
#define Analog_12_VRx    12
#define Analog_14_VRy    14
 
int AN_Pot_VRx_Result = 0;
int AN_Pot_VRy_Result = 0;
 
uint8_t flag_UP = 0x00;
uint8_t flag_DOWN = 0x00;
uint8_t flag_RIGHT = 0x00;
uint8_t flag_LEFT = 0x00;
 
BleKeyboard bleKeyboard("BLE KEYBOARD V1.0", "Bluetooth Device Manufacturer", 100);
 
void setup()
{
   Serial.begin(115200);
   Serial.println("Device Enabled");
   bleKeyboard.begin();
}
 
void loop()
{
  if(bleKeyboard.isConnected()) { 
    SendResponseToKey();
  }
  delay(100);
}
 
void SendResponseToKey(void) {
  AN_Pot_VRx_Result = analogRead(Analog_12_VRx);
  AN_Pot_VRy_Result = analogRead(Analog_14_VRy);
 
  if((AN_Pot_VRx_Result == 0) && (flag_UP == 0))
  {
    bleKeyboard.write(KEY_MEDIA_MUTE);
    flag_UP = 1;
  }
  else
  {
    flag_UP = 0;
  }
  
  if((AN_Pot_VRx_Result == 4095) && (flag_DOWN == 0))
  {
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
    flag_DOWN = 1;
  }
  else
  {
    flag_DOWN = 0;
  }
  
  if((AN_Pot_VRy_Result == 0) && (flag_RIGHT == 0))
  {
    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    flag_RIGHT = 1;
  }
  else
  {
    flag_RIGHT = 0;
  }
 
  if((AN_Pot_VRy_Result == 4095) && (flag_LEFT == 0))
  {
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    flag_LEFT = 1;
  }
  else
  {
    flag_LEFT = 0;
  }