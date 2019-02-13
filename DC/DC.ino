int motorPin1 = 10;
int motorPin2 = 3;

int curSpeed = 255;

int isOn = 1;
int speedUp = 0;
int speedDown = 0;
int isClockwise = 1;

const int stopPin = 9;
const int speedUpPin = 8;
const int speedDownPin = 7;
const int directionPin = 6;

int stopPinState = 1;  
int speedUpPinState = 1;  
int speedDownPinState = 1;  
int directionPinState = 1;  

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(stopPin, INPUT);
  pinMode(speedUpPin, INPUT);
  pinMode(speedDownPin, INPUT);
  pinMode(directionPin, INPUT);

  curSpeed = 255;
  analogWrite(motorPin1, curSpeed);
  analogWrite(motorPin2, 0);

  Serial.begin(9600);// rate at which the arduino communicates
  Serial.println("DC Motor");
}
void loop()
{
  stopPinState = digitalRead(stopPin);
  speedUpPinState = digitalRead(speedUpPin);
  speedDownPinState = digitalRead(speedDownPin);
  directionPinState = digitalRead(directionPin);
  
  if (stopPinState == LOW) 
  {
    while(stopPinState == LOW) {
      stopPinState = digitalRead(stopPin);
    }
    isOn = 1 - isOn;   
    if(isOn)
      curSpeed = 255;   
    else 
      curSpeed = 0; 
  } 
  if (speedUpPinState == LOW) 
  {
    while(speedUpPinState == LOW) {
      speedUpPinState = digitalRead(speedUpPin);
    }
    speedUp = 1;       
  } 
  if (speedDownPinState == LOW) 
  {
    while(speedDownPinState == LOW) {
      speedDownPinState = digitalRead(speedDownPin);
    }
    speedDown = 1;       
  }
  if (directionPinState == LOW) 
  {
    while(directionPinState == LOW) {
      directionPinState = digitalRead(directionPin);
    }
    Serial.println("direction changed!");//print on the serial
    isClockwise = 1 - isClockwise;       
  }

  if(isOn) 
  {
    if(speedUp) 
    {
      speedUp = 0;  
      curSpeed  = curSpeed + 10;
      if(curSpeed > 255)
        curSpeed = 255;
      Serial.println(curSpeed);//print on the serial
    }
    else if (speedDown)
    {
      speedDown = 0;
      curSpeed = curSpeed - 10;
      if(curSpeed < 0)
        curSpeed = 0;
      Serial.println(curSpeed);//print on the serial
    }
  }
  else 
  {
    curSpeed = 0;
  }


  if(isClockwise)
  {
    analogWrite(motorPin1, curSpeed);
    analogWrite(motorPin2, 0); 
  }
  else 
  {
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, curSpeed);
  }
  
}
