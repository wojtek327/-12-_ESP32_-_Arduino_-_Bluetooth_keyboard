#include <BleKeyboard.h>
#include <Keypad.h>
//-------------------------------------------------
#define NORMAL_KEY_TO_SEND
//-------------------------------------------------
#define ROW_NUM     4 // four rows
#define COLUMN_NUM  4 // four columns
 
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte pin_rows[ROW_NUM]      = {23, 22, 21, 19};
byte pin_column[COLUMN_NUM] = {18, 5, 4, 15};
 
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
BleKeyboard bleKeyboard("BLE KEYBOARD V1.0", "Bluetooth Device Manufacturer", 100);
 
void setup() {
  Serial.begin(115200);
  Serial.println("Device Enabled");
  bleKeyboard.begin();
}
 
void loop() {
  char key = keypad.getKey();
  
  if(bleKeyboard.isConnected()) {
    if(key){
      #if defined(NORMAL_KEY_TO_SEND)
      bleKeyboard.write(key);
      #else
      SendResponseToKey(key);
      #endif
    }
  }

  void SendResponseToKey(char clickedKey) {
  if(clickedKey == '1') {
    bleKeyboard.write(KEY_MEDIA_STOP);
  }
  else if(clickedKey == '2') {
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  }
  else if(clickedKey == '3') {
    bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
  }
  else if(clickedKey == '4') {
    bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);    
  }
  else if(clickedKey == '5') {
    bleKeyboard.write(KEY_MEDIA_STOP);
  }
  else if(clickedKey == '6') {
     bleKeyboard.write(KEY_MEDIA_WWW_HOME);   
  }
  else if(clickedKey == '7') {
    bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);    
  }
  else if(clickedKey == '8') {
    bleKeyboard.write(KEY_MEDIA_CALCULATOR);    
  }
  else if(clickedKey == '9') {
     bleKeyboard.write(KEY_MEDIA_WWW_SEARCH);   
  }
  else if(clickedKey == '0') {
     bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);   
  }
  else if(clickedKey == '*') {
    bleKeyboard.write(KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION);
  }
  else if(clickedKey == '#') {
    bleKeyboard.write(KEY_MEDIA_EMAIL_READER);    
  }
  else if(clickedKey == 'A') {
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
  }
  else if(clickedKey == 'B') {
    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  }
  else if(clickedKey == 'C') {
    bleKeyboard.write(KEY_MEDIA_MUTE);
  }
  else if(clickedKey == 'D') {
    bleKeyboard.write(KEY_MEDIA_WWW_STOP);
  }
}
