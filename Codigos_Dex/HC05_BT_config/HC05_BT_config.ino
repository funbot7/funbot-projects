/*
ConfigBluetooth HC-05 from Arduino.
Change name, password and baud using serial port with AT commands, only configurate one time
After upload the sketch connect your module, the LED should blinking every 2 seconds.
If LED is blinking too fast, you need to disconnect and connect again but this time pressing the reset little button of the BT module
Then you can open your serial (Both NL & CR 9600 baud) and should appear and "OK" message means is ready to recieve AT commands. (AT+NAME=)
After setup you can pair your module
HC-05 GND --- Arduino GND Pin
HC-05 VCC (5V) --- Arduino 5V
HC-05 TX --- Arduino Pin 10 (soft RX)
HC-05 RX --- Arduino Pin11 (soft TX)
HC-05 Key (PIN 34) --- Arduino Pin 9
*/
// Options:
  int ArduLED=13;       //Internal Arduino´s LED
  char ssid[10]   = "Zowi"; // Name for Bluetooth.
  char baudios     = '4';      // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (default), 5=>19200, 6=>38400, 7=>57600, 8=>115200
  char password[10] = "1234"; 

void setup()
{
Serial.begin(38400);    //9600bauds is the deafult baudrate for these modules.
          //if it´s not working try changing this baudrate to match your HC-06 initial setup
  
  // Waiting time (10 seconds) onboard LED is ON:
    pinMode(ArduLED,OUTPUT);
    digitalWrite(ArduLED,HIGH);
    delay(10000);
    digitalWrite(ArduLED,LOW);
  
Serial.print("AT"); delay(1000); // Now configuration start

Serial.print("AT+NAME"); Serial.print(ssid); delay(1000);   // Change Name of BT

Serial.print("AT+BAUD"); Serial.print(baudios); delay(1000);    // Change Baud

Serial.print("AT+PIN"); Serial.print(password); delay(1000);      // Change Password
}

void loop()
{
// After programing bluetooth, onboard LED will Blink.
  digitalWrite(ArduLED, !digitalRead(ArduLED));
  delay(500);
}
