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
}

/*
 * 1 -> //SCH pn //(PLACE -> NET LABEL) 
 * 2 -> //SCH pw //(PLACE -> WIRE) 
 * 3 -> //SCH pr //(PLACE -> PORT)
 * 4 -> //SCH pt //(PLACE -> TEXT STRING)
 * 5 -> //SCH po //(PLACE -> POWER PORT)
 * 6 -> //SCH 
 * 7 -> //SCH 
 * 8 -> //SCH 
 * 9 -> //PCB pv //(PLACE -> VIA)
 * * -> //PCB pp //(PLACE -> PAD)
 * 0 -> //PCB pt //(PLACE -> INTERACTIVE ROUTING)
 * # -> //PCB ps //(PLACE -> STRING)
 * A -> //PCB pg //(PLACE -> POLYGON POUR)
 * B -> //PCB tga //(TOOLS -> POLYGON POURS -> REBUILD ALL)
 * C -> //PCB
 * D -> //PCB
 */

//#1 -  bleKeyboard.print("pn"); 
//#2 -  bleKeyboard.write('p');
//      bleKeyboard.write('w');

void SendResponseToKey(char clickedKey) {
  if(clickedKey == '1') {     
    bleKeyboard.print("pn");
  }
  else if(clickedKey == '2') {    
    bleKeyboard.print("pw");
  }
  else if(clickedKey == '3') {
    bleKeyboard.print("pr");
  }
  else if(clickedKey == '4') {
    bleKeyboard.print("pt");
  }
  else if(clickedKey == '5') {
    bleKeyboard.print("po");
  }
  else if(clickedKey == '6') {   
  }
  else if(clickedKey == '7') {  
  }
  else if(clickedKey == '8') {   
  }
  else if(clickedKey == '9') {
    bleKeyboard.print("pv");
  }
  else if(clickedKey == '0') {
    bleKeyboard.print("pp");
  }
  else if(clickedKey == '*') {
    bleKeyboard.print("pt");
  }
  else if(clickedKey == '#') {
    bleKeyboard.print("ps");   
  }
  else if(clickedKey == 'A') {
    bleKeyboard.print("pg");
  }
  else if(clickedKey == 'B') {
    bleKeyboard.print("tga");
  }
  else if(clickedKey == 'C') {
  }
  else if(clickedKey == 'D') {
  }
}