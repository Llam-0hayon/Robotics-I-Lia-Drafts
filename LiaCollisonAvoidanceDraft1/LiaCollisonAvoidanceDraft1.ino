
#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo
 
int PWMA =5;
int AIN1=7; // Direction motor B
int BIN1=8;// Direction motor A
int PWMB =6;
int STBY =3;

int MINspeed = 50;// MINImum speed before car or atleast my car struggles

int SPEED1 = 100; //MINspeed for MOVING   TURNS

int SPEED2 = 150;
int SPEED3 = 200;

int MAXspeed = 255;// MAXimum speed before car or atleast my car struggles

int Echo = 12;  
int Trig = 13; 
 
int servoSig = 10;

int rightDistance = 0, leftDistance = 0, middleDistance = 0;
 
void forward(int speed){

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed);
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,1);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed);
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,1);
    
 
} 

void backward(int speed){

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed);
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,0);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed);
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,0);
    
 
} 
void left(int speed){ // Left means it just turns left meaning stop moving forward and just moves in places leftward or counterclockwise for aslong as delaspeed dictates

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed);
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,1);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed);
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,0);
}
 


void right(int speed){  //Right means it just turns right meaning stop moving forward and just moves in places rightward  or clockwise for aslong as delaspeed dictates

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed);
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,0);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed);
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,1);

  

}  

 void stop (){  

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,0);
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,1);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, 0);
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,1);
 
  

}


//Ultrasonic distance measurement Sub function
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}  
 
void setup() { 
  myservo.attach(servoSig);  // attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  
} 
 
void loop() { 
    myservo.write(90);  //setservo position according to scaled value
    delay(500); 
    middleDistance = Distance_test();
   forward(100);
    if(middleDistance <= 20) {     
      stop();
      delay(500);                         
      myservo.write(10);          
      delay(1000);      
      rightDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);
      if(rightDistance > leftDistance) {
        right(SPEED1);
        delay(360);
      }
      else if(rightDistance < leftDistance) {
        left(SPEED1);
        delay(360);
      }
      else if((rightDistance <= 20) || (leftDistance <= 20)) {
        backward(SPEED2);
        delay(180);
      }
      else {
        forward(SPEED2);
      }
    }  
    else {
        forward(SPEED2);
    }                     
}