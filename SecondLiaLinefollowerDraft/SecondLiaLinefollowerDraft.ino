
const int pinLeft = A2;
const int pinMiddle = A1;
const int pinRight = A0;

int lineDetectMin = 250;// these values can vhange depending on brightnees of room DARKER the room LOWER the values
int lineDetectMax = 850;// these values can vhange depending on brightnees of room DARKER the room LOWER the values

int detectNotOnGround =950;// these values can vhange depending on brightnees of room DARKER the room LOWER the values

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(pinLeft,INPUT);
pinMode(pinMiddle, INPUT);
pinMode(pinRight, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int leftPinRead = analogRead(pinLeft);
  int middlePinRead = analogRead(pinMiddle);
  int rightPinRead = analogRead(pinRight);

  

  if( leftPinRead > detectNotOnGround  && middlePinRead > detectNotOnGround && rightPinRead > detectNotOnGround){
   Serial.print("\t");
  Serial.print("NOT On Ground");
  }else
  Serial.print("\t");
  Serial.print("ON Ground");
  
  
  if(lineDetectMin <= leftPinRead && leftPinRead <= lineDetectMax){
  Serial.print("\t");
  Serial.print("LeftTrue");
  }else
  Serial.print("\t");
  Serial.print("LeftFalse");
  

  if(lineDetectMin <= middlePinRead && middlePinRead <= lineDetectMax){
   Serial.print("\t");
  Serial.print("MiddleTrue");
  }else
   Serial.print("\t");
  Serial.print("MiddleFalse");
  

  if(lineDetectMin <= rightPinRead && rightPinRead <= lineDetectMax){
   Serial.print("\t");
  Serial.print("RightTrue");
  }else
  Serial.print("\t");
  Serial.print("RightFalse");
  
  Serial.print("\t");
  Serial.print("Analog Reading Left=");
  Serial.print(leftPinRead);
  Serial.print("\t Analog Reading Middle=");
  Serial.print(middlePinRead);
  Serial.print("\t Analog Reading Right=");
  Serial.println(rightPinRead);
  delay(1000);
}





