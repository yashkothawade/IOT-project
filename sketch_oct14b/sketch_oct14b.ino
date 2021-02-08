#include <Servo.h>

Servo servo;
int angle;
char command;
// = 'S';

boolean Direction1 = false;
boolean Direction2 = true;

int steps = 0;
int Steps1 = 0;
int Steps2 = 0;

//Stepper1
#define IN11  2
#define IN12  3
#define IN13  4
#define IN14  5

//Stepper2
#define IN21  6
#define IN22  7
#define IN23  8
#define IN24  9

void setup()
{      
    Serial.begin(9600);
  Serial.begin(9600); 

  pinMode(IN11, OUTPUT); 
  pinMode(IN12, OUTPUT); 
  pinMode(IN13, OUTPUT); 
  pinMode(IN14, OUTPUT); 
  pinMode(IN21, OUTPUT); 
  pinMode(IN22, OUTPUT); 
  pinMode(IN23, OUTPUT); 
  pinMode(IN24, OUTPUT); 
   servo.attach(13);
  servo.write(angle);
}

void loop(){
  if(Serial.available() > 0){
    command = Serial.read();    
 Serial.write(command);
   }

  if(command=='B')
  {
    Direction1=1;
    Direction2=0;
    Serial.println("Backward");
   // TowerDown();
  }
  else if(command=='F')
  {
    Direction1=0;
    Direction2=1;
    Serial.println("Forward");
    //TowerDown();
  } 
  else if(command=='R')
  {
    Direction1=0;
    Direction2=0;
    Serial.println("Right");
   // TowerUp();
  }    
  else if(command=='L')
  {
    Direction1=1;
    Direction2=1;
    Serial.println("Left");
    //TowerUp();
  } 
 
  
 
   
  if (command != "S")  
  {
   SetDirection1();
   SetDirection2(); 
   
  }
 
delay(1);




void stepper1(){
switch(Steps1){
   case 0:
     digitalWrite(IN11, LOW); 
     digitalWrite(IN12, LOW);
     digitalWrite(IN13, LOW);
     digitalWrite(IN14, HIGH);
   break; 
   case 1:
     digitalWrite(IN11, LOW); 
     digitalWrite(IN12, LOW);
     digitalWrite(IN13, HIGH);
     digitalWrite(IN14, HIGH);
   break; 
   case 2:
     digitalWrite(IN11, LOW); 
     digitalWrite(IN12, LOW);
     digitalWrite(IN13, HIGH);
     digitalWrite(IN14, LOW);
   break; 
   case 3:
     digitalWrite(IN11, LOW); 
     digitalWrite(IN12, HIGH);
     digitalWrite(IN13, HIGH);
     digitalWrite(IN14, LOW);
   break; 
   case 4:
     digitalWrite(IN11, LOW); 
     digitalWrite(IN12, HIGH);
     digitalWrite(IN13, LOW);
     digitalWrite(IN14, LOW);
   break; 
   case 5:
     digitalWrite(IN11, HIGH); 
     digitalWrite(IN12, HIGH);
     digitalWrite(IN13, LOW);
     digitalWrite(IN14, LOW);
   break; 
     case 6:
     digitalWrite(IN11, HIGH); 
     digitalWrite(IN12, LOW);
     digitalWrite(IN13, LOW);
     digitalWrite(IN14, LOW);
   break; 
   case 7:
     digitalWrite(IN11, HIGH); 
     digitalWrite(IN12, LOW);
     digitalWrite(IN13, LOW);
     digitalWrite(IN14, HIGH);
   break; 
   default:
     digitalWrite(IN11, LOW); 
     digitalWrite(IN12, LOW);
     digitalWrite(IN13, LOW);
     digitalWrite(IN14, LOW);
   break;  
}
} 

void stepper2(){
switch(Steps2){
   case 0:
     digitalWrite(IN21, LOW); 
     digitalWrite(IN22, LOW);
     digitalWrite(IN23, LOW);
     digitalWrite(IN24, HIGH);
   break; 
   case 1:
     digitalWrite(IN21, LOW); 
     digitalWrite(IN22, LOW);
     digitalWrite(IN23, HIGH);
     digitalWrite(IN24, HIGH);
   break; 
   case 2:
     digitalWrite(IN21, LOW); 
     digitalWrite(IN22, LOW);
     digitalWrite(IN23, HIGH);
     digitalWrite(IN24, LOW);
   break; 
   case 3:
     digitalWrite(IN21, LOW); 
     digitalWrite(IN22, HIGH);
     digitalWrite(IN23, HIGH);
     digitalWrite(IN24, LOW);
   break; 
   case 4:
     digitalWrite(IN21, LOW); 
     digitalWrite(IN22, HIGH);
     digitalWrite(IN23, LOW);
     digitalWrite(IN24, LOW);
   break; 
   case 5:
     digitalWrite(IN21, HIGH); 
     digitalWrite(IN22, HIGH);
     digitalWrite(IN23, LOW);
     digitalWrite(IN24, LOW);
   break; 
     case 6:
     digitalWrite(IN21, HIGH); 
     digitalWrite(IN22, LOW);
     digitalWrite(IN23, LOW);
     digitalWrite(IN24, LOW);
   break; 
   case 7:
     digitalWrite(IN21, HIGH); 
     digitalWrite(IN22, LOW);
     digitalWrite(IN23, LOW);
     digitalWrite(IN24, HIGH);
   break; 
   default:
     digitalWrite(IN21, LOW); 
     digitalWrite(IN22, LOW);
     digitalWrite(IN23, LOW);
     digitalWrite(IN24, LOW);
   break; 
}
}

void SetDirection1(){
  Serial.println("Dir1");
if(Direction1==1){ Steps1++;}
if(Direction1==0){ Steps1--; }
if(Steps1>7){Steps1=0;}
if(Steps1<0){Steps1=7; }

stepper1();
}
void SetDirection2(){
  Serial.println("Dir2");
if(Direction2==1){ Steps2++;}
if(Direction2==0){ Steps2--; }
if(Steps2>7){Steps2=0;}
if(Steps2<0){Steps2=7; }
stepper2(); 
}

void TowerUp() 
{ 
 // scan from 0 to 180 degrees
  for(angle = 0; angle < 25; angle++)  
  {                                  
    servo.write(angle);               
    delay(120);                   
  } 
}
void TowerDown()
{
  // now scan back from 180 to 0 degrees
  for(angle = 25; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(100);       
  } 
 } 
