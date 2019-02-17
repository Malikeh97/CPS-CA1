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
}

void loop() {

  ClkWisePinState = digitalRead(ClkWisePin);
  AntiClkWisePinState = digitalRead(AntiClkWisePin);
  StopPinState = digitalRead(StopPin);

  //check state
  if (ClkWisePinState == LOW) {
     while(ClkWisePinState == LOW) {
      ClkWisePinState = digitalRead(ClkWisePin);
      }
      flag = 1;
  }
  if(AntiClkWisePinState == LOW){  
    while(AntiClkWisePinState == LOW) {
      AntiClkWisePinState = digitalRead(AntiClkWisePin);
    } 
    flag =-1;
  }
  if(StopPinState == LOW){ 
    while(StopPinState == LOW) {
      StopPinState = digitalRead(StopPin);
    }
    flag =0;
  }

  //check mode
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
