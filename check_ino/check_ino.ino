char command = 'S';

boolean Direction1 = false;
boolean Direction2 = true;

int steps = 0;
int Steps1 = 0;
int Steps2 = 0;

//Stepper1
#define IN11  6
#define IN12  7
#define IN13  8
#define IN14  9

//Stepper2
#define IN21  1
#define IN22  2
#define IN23  3
#define IN24  4

void setup()
{      
  Serial.begin(9600); 

  pinMode(IN11, OUTPUT); 
  pinMode(IN12, OUTPUT); 
  pinMode(IN13, OUTPUT); 
  pinMode(IN14, OUTPUT); 
  pinMode(IN21, OUTPUT); 
  pinMode(IN22, OUTPUT); 
  pinMode(IN23, OUTPUT); 
  pinMode(IN24, OUTPUT); 
}

void loop(){
  if(Serial.available()){
    Serial.println("Hii");
    command = Serial.read();    
   }

  if(command=="F")
  {
    Direction1=1;
    Direction2=0;
  }
  else if(command=="B")
  {
    Direction1=0;
    Direction2=1;
  } 
  else if(command=="L")
  {
    Direction1=0;
    Direction2=0;
  }    
  else if(command=="R")
  {
    Direction1=1;
    Direction2=1;
  }  
  if (command != "S")  
  {
    SetDirection1();
    SetDirection2();    
  }
  delay(1);
}


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
if(Direction1==1){ Steps1++;}
if(Direction1==0){ Steps1--; }
if(Steps1>7){Steps1=0;}
if(Steps1<0){Steps1=7; }
stepper1();
}
void SetDirection2(){
if(Direction2==1){ Steps2++;}
if(Direction2==0){ Steps2--; }
if(Steps2>7){Steps2=0;}
if(Steps2<0){Steps2=7; }
stepper2();
}
