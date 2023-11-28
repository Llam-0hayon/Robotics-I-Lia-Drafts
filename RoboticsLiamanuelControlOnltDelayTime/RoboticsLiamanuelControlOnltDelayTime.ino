

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

void forward(int speed, int delayTime){
  pinMode(STBY,OUTPUT);
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
    
  delay(delayTime);
} 


void backward(int speed, int delayTime){

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
    
  delay(delayTime);
} 




void left(int speed, int delayTime){ // Left means it just turns left meaning stop moving forward and just moves in places leftward or counterclockwise for aslong as delaspeed dictates

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

  delay(delayTime);

}


 
void right(int speed, int delayTime){  //Right means it just turns right meaning stop moving forward and just moves in places rightward  or clockwise for aslong as delaspeed dictates

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
  digitalWrite (BIN1,1
  );

  delay(delayTime);

}  


void leftForward(int speed, int delayTime){ // means moving  left while moving forward

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed);// note that car will struggle to perfrom function below 100 speed
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,1);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed/2); // note that speed also determines turn radius 
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,1);
  
  delay(delayTime);
 
}

void leftBackward(int speed, int delayTime){ // means moving turning left while moving backward

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed);// note that car will struggle to perfrom function below 100 speed
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,0);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed/2);// note that speed also determines turn radius 
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,0);

  delay(delayTime);

}


void rightForward(int speed, int delayTime){ // means moving turning right while moving forward

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed/2);// note that speed also determines turn radius
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,1);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed);// note that car will struggle to perfrom function below 100 speed
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,1);
  
  delay(delayTime);

}


void rightBackward(int speed, int delayTime){ // means moving turning right while moving backward

  digitalWrite(STBY,1);

  //motor A
  pinMode(PWMA,OUTPUT);
  analogWrite (PWMA,speed/2);// note that speed also determines turn radius
  pinMode(AIN1,OUTPUT);
  digitalWrite (AIN1,0);

  //Motor B
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMB, speed);// note that car will struggle to perfrom function below 100 speed
  pinMode(BIN1,OUTPUT);
  digitalWrite (BIN1,0);
 
  delay(delayTime);

}


void stop (int delayTime){  

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
 
  delay(delayTime);

}


void setup() {
  // put your setup code here, to run once:
  
}
void loop() {
  // put your main code here, to run repeatedly:
  // put directions for car here:
  //put delay after every function to determine its duration
  /*to make it execute only one funtion for a certain amount of time enter funtion twice.
  Enter them one after the other. 
  Once with the desired speed and delay for how long you want that function to be executed and once with 0 speed and enter delays for how long you want pause*/
  //If you want function to go one indefineatly make delay + 0
 
 forward(100,1000);
 left(100,1000);
 

}