#include <Servo.h>
//Next, we create an object of the servo library

Servo servo;
//Next, we move proceed to the void setup function where we attach the servo object to a digital pin and set the servo angle to 0. This is known as centering the servo.

void setup() {
  servo.attach(8);
  servo.write(angle);
}
//Next, is the loop function. To turn make the servo rotate to a particular degree, we use the servo.write() function to write the degree of rotation we desire to the servo. We used the function to turn the servo from one to the other and back.

void loop() 
{ 
 // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
}
