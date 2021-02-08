int Red_LED_Pin = 9; // PWM Pin for Red LED
int Green_LED_Pin = 10; // PWM Pin for Green LED
int Blue_LED_Pin = 11; // PWM Pin for Blue LED

//Varibles to hold brightness values ranging from 0 (off) to 255 (fully on)
int Red_value=0;
int Green_value=0;
int Blue_value=0;
char BluetoothData; // the data received from Bluetooth serial link
 
void setup() {
  // Initialize LED pins as outputs
pinMode(Red_LED_Pin, OUTPUT);
pinMode(Green_LED_Pin, OUTPUT);
pinMode(Blue_LED_Pin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  //Process any info coming from the bluetooth serial link
if (Serial.available()){
BluetoothData=Serial.read(); //Get next character from bluetooth
if(BluetoothData=='R')
{
  Direction1=0;
  Direction2=0;
}

if(BluetoothData=='L')
{
  Direction1=1;
  Direction2=1; 
}
if(BluetoothData=='B')
{
  Direction1=1;
  Direction2=0; 
}
if(BluetoothData=='F')
{
  Direction1=0;
  Direction2=1; 
}

  }


  //update LED Brightness
analogWrite(Red_LED_Pin, Red_value);
analogWrite(Green_LED_Pin, Green_value);
analogWrite(Blue_LED_Pin, Blue_value);
delay(10);
}
