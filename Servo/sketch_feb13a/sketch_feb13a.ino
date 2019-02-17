#include <Servo.h>
 
Servo myservo;  
int pos = 1500;    
int clockwise = 8;
int anticlockwise = 9;
int deg4 = 200/9; 
 
void setup() 
{ 
  myservo.attach(10);
  pinMode(clockwise, INPUT);
  pinMode(anticlockwise, INPUT);
}
 
void loop() 
{ 
  if(digitalRead(clockwise) == LOW)
  {
     pos = pos + deg4;
     myservo.writeMicroseconds(pos);
     while(digitalRead(clockwise) == LOW){}
  }
  if(digitalRead(anticlockwise) == LOW)
  {
    pos = pos - deg4;
    myservo.writeMicroseconds(pos);
    while(digitalRead(anticlockwise) == LOW){}
  }
  
}
