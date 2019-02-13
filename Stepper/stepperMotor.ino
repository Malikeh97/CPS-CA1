#include <LiquidCrystal.h>//Library for LCD
#include <Stepper.h>     //Library for Stepper motor

const int stepsPerRevolution = 36;  

// initialize the stepper library on pins
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);
const int ClkWisePin = 8;     
const int AntiClkWisePin = 9;    
const int StopPin = 10;     
int ClkWisePinState = 1; 
int AntiClkWisePinState =1;
int StopPinState =1;
int  flag = 1;
void setup() {
  // set the speed at 60 rpm
  myStepper.setSpeed(6);
  // initialize the serial port:
pinMode(ClkWisePin, INPUT);
pinMode(AntiClkWisePin, INPUT);
pinMode(StopPin, INPUT);

Serial.begin(9600);// rate at which the arduino communicates
Serial.println("Stepper Motor");
 delay(500);
}

void loop() {

  ClkWisePinState = digitalRead(ClkWisePin);
  AntiClkWisePinState = digitalRead(AntiClkWisePin);
  StopPinState = digitalRead(StopPin);
  
  if (ClkWisePinState == LOW) {
//    while(ClkWisePinState == LOW){
//        digitalRead(ClkWisePin);
//    }
      flag = 1;
      Serial.println("CLKWise");
  }
  if(AntiClkWisePinState == LOW){   
//    while(AntiClkWisePinState == LOW){
//      digitalRead(AntiClkWisePin);
//    }
    flag =-1;
    Serial.println("AntiCLKWise");
  }
  if(StopPinState == LOW){ 
//    while(StopPinState == LOW){
//      digitalRead(StopPin);
//    }
     flag =0;
     Serial.println("STOP");
  }
  if(flag==1){
    myStepper.step(1);
  }
  else if (flag ==-1){
    myStepper.step(-1);
    
  }
  else if(flag ==0){
    myStepper.step(0);
   
  }
  
}
