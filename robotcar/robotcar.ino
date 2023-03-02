const float sec_to_microsec = 1000000.0;
const float meter_to_cm = 100.0;
const float speed_of_sound = 340.0; //meters per second
float MAX_SPEED=80;
int MotorBasespeed = 60;
int usdelay=50;
int mspd=90;
int k=400;


// Motors
# define IN1 2  // motors - right fd
# define IN2 3  // motors - right bw
# define IN3 5  // motors - left fd
# define IN4 4  // motors - left bw
# define IN5 11  // motors - right speed
# define IN6 12  // motors - left speed

// Sensors

//IR sensor array
int IR1; //A0  Left
int IR2; //A1
int IR3; //A2
int IR4; //A3
int IR5; //A4
int IR6; //A5  Right

//Front IR sensors
int IR7; //A6 right
int IR8; //A7 left

//Side IR sensors
int IR9; //A8  // left
int IR10; //A9  // right

//Front Ultrasonic sensor
int d1;
# define US1 6  // echo
# define US2 22  // trigger

//Left Ultrasonic sensors
int d2;
# define US3 7  // front-echo
# define US4 24  // front-trigger
int d3;
# define US5 8  // back-echo
# define US6 26  // back-trigger

//Right Ultrasonic sensors
int d4;
# define US7 9  // front-echo
# define US8 28  // front-trigger
int d5;
# define US9 10  // back-echo
# define US10 30  // back-trigger

  bool startstatus = 0;
  bool mazestatus = 0;
  bool wallstatus = 0;
  bool boxstatus = 0;
  bool linestatus = 0;
  bool finishstatus = 0;

void setup() {
  
  pinMode(IN1,OUTPUT);pinMode(IN2,OUTPUT);pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);pinMode(IN5,OUTPUT);pinMode(IN6,INPUT); 
  pinMode(US2,OUTPUT);pinMode(US1,INPUT);
  pinMode(US4,OUTPUT);pinMode(US3,INPUT);
  pinMode(US6,OUTPUT);pinMode(US5,INPUT);
  pinMode(US8,OUTPUT);pinMode(US7,INPUT);
  pinMode(US10,OUTPUT);pinMode(US9,INPUT);
  analogWrite(IN5,mspd);//right speed
  analogWrite(IN6,mspd); // left speed
  Serial.begin(9600);
}
void loop() {

//  usfd();
//  usrightfd();
//  Serial.println(d4);
//  Serial.println(d1);
//  if (d1<12) left();
//  else if(d1>=12) {
//  if (d4>=5 && d4<=15) fd();
//  else if (d4<5) left();
//  else if (d4>15) fd();delay(500);right();
//  }
//  wallfollowingright();

  LineFollow();
//  analogWrite(IN5,250);//right speed
//  analogWrite(IN6,250); // left speed
//  digitalWrite(IN1,HIGH);digitalWrite(IN3,HIGH);
//  delay(10);
//  digitalWrite(IN1,LOW);digitalWrite(IN3,LOW);
//  delay(20);
  //LineFollow(10000);
  //Serial.println("RobotX is starting Now");
  //IRsensorarray();
  //delay(100);

  //irfd();Serial.print(IR7);Serial.print("   ");Serial.print(IR8);
  
//  usfd(); Serial.print(d1); delay(100);Serial.print("  ");
//  usleftfd(); Serial.print(d2); delay(100);Serial.print("  ");
//  usleftbd(); Serial.print(d3); delay(100);Serial.print("  ");
//  usrightfd(); Serial.print(d4); delay(100);Serial.print("  ");
//  usrightbd(); Serial.print(d5); delay(100);Serial.print("  ");
//  Serial.println();
  
}


void fd(){  //Car goes Forward
  analogWrite(IN1,60);analogWrite(IN3,60);delay(k);
  analogWrite(IN1,0);analogWrite(IN3,0);
}

void hoow(){
  digitalWrite(IN1,LOW);digitalWrite(IN3,LOW);digitalWrite(IN2,LOW);digitalWrite(IN4,LOW);
}

void bw(){  //Car goes backward
  analogWrite(IN2,60); analogWrite(IN4,60);delay(k);
  analogWrite(IN2,0); analogWrite(IN4,0);
}

void right(){  //Car turns right
  analogWrite(IN3,60);analogWrite(IN2,10);delay(k);
  analogWrite(IN3,0);analogWrite(IN2,0);
}

void left(){  //Car turns left
  analogWrite(IN1,60);analogWrite(IN4,10);delay(k);
  analogWrite(IN1,0);analogWrite(IN4,0);
}

void start() {
  Serial.println("Start started");
  startstatus=1;
  delay(1000);
  Serial.println("Start finished");
}

void maze() {
  Serial.println("Maze started");
  delay(1000);
  mazestatus=1;
  Serial.println("Maze finished");
  
}

void wall() {
  Serial.println("Wall started");
  delay(1000);
  wallstatus=1;
  Serial.println("Wall finished");
}

void box() {
  Serial.println("Box started");
  bool wentout=0;
  left();
  usleftfd();
  while (!wentout){
  while (d2<30){
    wallfollowingleft();
    delay(100);}
  left();fd();
  IRsensorarray();
  if(IR1==1 || IR2==1 || IR3==1 || IR4==1 || IR5==1 || IR6==1 ){
    wentout=1;fd();
  }
  else {
    bw();right();fd();
  }
  }
  
  boxstatus=1;
  Serial.println("Box finished");
}

void line() {
  Serial.println("Line started");
  delay(1000);
  linestatus=1;
  Serial.println("Line finished");
}

void finish() {
  Serial.println("Finish started");
  delay(1000);
  finishstatus=1;
  Serial.println("Finish finished");
}

void usfd() {
  int triggerPin=US2; 
  int echoPin=US1;
  long duration; int distance;
  
  // Initiate triggerPin as LOW
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Set the triggerPin HIGH for atleast 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Monitor the echoPin and
  duration = pulseIn(echoPin, HIGH); //Returns the length of the pulse in microseconds
  
  // Calculate distance and print on Serial Monitor
  distance = (duration / sec_to_microsec) * (speed_of_sound * meter_to_cm) / 2.0;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  d1=distance;
  delay(usdelay);
}

void usleftfd() {
  int triggerPin=US4; 
  int echoPin=US3;
  long duration; int distance;
  
  // Initiate triggerPin as LOW
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Set the triggerPin HIGH for atleast 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Monitor the echoPin and
  duration = pulseIn(echoPin, HIGH); //Returns the length of the pulse in microseconds
  
  // Calculate distance and print on Serial Monitor
  distance = (duration / sec_to_microsec) * (speed_of_sound * meter_to_cm) / 2.0;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  d2=distance;
  delay(usdelay);
}

void usleftbd() {
  int triggerPin=US6; 
  int echoPin=US5;
  long duration; int distance;
  
  // Initiate triggerPin as LOW
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Set the triggerPin HIGH for atleast 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Monitor the echoPin and
  duration = pulseIn(echoPin, HIGH); //Returns the length of the pulse in microseconds
  
  // Calculate distance and print on Serial Monitor
  distance = (duration / sec_to_microsec) * (speed_of_sound * meter_to_cm) / 2.0;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  d3=distance;
  delay(usdelay);
}

void usrightfd() {
  int triggerPin=US8; 
  int echoPin=US7;
  long duration; int distance;
  
  // Initiate triggerPin as LOW
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Set the triggerPin HIGH for atleast 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Monitor the echoPin and
  duration = pulseIn(echoPin, HIGH); //Returns the length of the pulse in microseconds
  
  // Calculate distance and print on Serial Monitor
  distance = (duration / sec_to_microsec) * (speed_of_sound * meter_to_cm) / 2.0;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  d4=distance;
  delay(usdelay);
}

void usrightbd() {
  int triggerPin=US10; 
  int echoPin=US9;
  long duration; int distance;
  
  // Initiate triggerPin as LOW
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Set the triggerPin HIGH for atleast 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Monitor the echoPin and
  duration = pulseIn(echoPin, HIGH); //Returns the length of the pulse in microseconds
  
  // Calculate distance and print on Serial Monitor
  distance = (duration / sec_to_microsec) * (speed_of_sound * meter_to_cm) / 2.0;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  d5=distance;
  delay(usdelay);
}

void IRsensorarray() {
  int  sense0 = analogRead(A0);
  int  sense1 = analogRead(A1);
  int  sense2 = analogRead(A2);
  int  sense3 = analogRead(A3);
  int  sense4 = analogRead(A4);
  int  sense5 = analogRead(A5);
  
  if(sense0>150) IR1=1;
  else IR1=0;
  
  if(sense1>150) IR2=1;
  else IR2=0;

  if(sense2<500) IR3=1;
  else IR3=0;

  if(sense3<500) IR4=1;
  else IR4=0;

  if(sense4>150) IR5=1;
  else IR5=0;

  if(sense5>150) IR6=1;
  else IR6=0;

  
  Serial.print(IR1);Serial.print(" ");
  Serial.print(IR2);Serial.print(" ");
  Serial.print(IR3);Serial.print(" ");
  Serial.print(IR4);Serial.print(" ");
  Serial.print(IR5);Serial.print(" ");
  Serial.println(IR6);delay(100);
  
}
//Front IR sensors
//int IR7; //A6 right
//int IR8; //A7 left
void irfd(){
  int  sense6 = analogRead(A6);
  int  sense7 = analogRead(A7);
  delay(100);

  if(sense6>780) IR7=0;
  else IR7=1;
  
  if(sense7>780) IR8=0;
  else IR8=1;
}

void LineFollow(){

// Define the motor pins
const int leftMotor = IN3;
const int rightMotor = IN1;

// Define the PID constants
const double Kp = 0.5;
const double Ki = 0.1;
const double Kd = 0.2;

// Define the setpoint
const int setpoint = 80;

// Initialize the PID variables
double error = 0;
double lastError = 0;
double integral = 0;
double derivative = 0;

  int IR_val[6];
  IRsensorarray();
  IR_val[0] = IR1;IR_val[1] =IR2;IR_val[2] = IR3;IR_val[3] = IR4;
  IR_val[4] = IR5;IR_val[5] = IR6;
  // Calculate the error
  error = 0;
  for (int i = 0; i < 6; i++) {
    error += (i - 2.5) * IR_val[i];
  }
  Serial.println(error);

  // Calculate the integral
  integral += error;

  // Calculate the derivative
  derivative = error - lastError;
  lastError = error;

  // Calculate the output
  double output = Kp * error + Ki * integral + Kd * derivative;
  output*=5;
  Serial.println(output);
  // Apply the output to the motors
  int leftSpeed = constrain(setpoint + output, 0, 70);
  int rightSpeed = constrain(setpoint - output, 0, 70);
  analogWrite(leftMotor, leftSpeed);
  analogWrite(rightMotor, rightSpeed);
}



//  int IR_val[6] = {0, 0, 0, 0, 0, 0};
//  int IR_weights[6] = {-3,-2,-1,1,2,3};
//
//  float P, I, D;
//  float error = 0;
//  float previousError = 0;
//  float Kp = 6.3;
//  float Kd = 10; 
//  float Ki = 0;
//  int LineItter= LineFollowDuration/10;
//  for(int j=0;j<LineItter;j++){
//  IRsensorarray();
//  IR_val[0] = IR1;IR_val[1] =IR2;IR_val[2] = IR3;IR_val[3] = IR4;
//  IR_val[4] = IR5;IR_val[5] = IR6;
//  error =0;
//  for (int i = 0; i < 6; i++){
//    error += IR_weights[i] * IR_val[i];}
//
//  P = error;
//  I = I + error;
//  D = error - previousError;
//
//  previousError = error;
//
//  float speedAdjust = (Kp * P + Ki * I + Kd * D);
//
//  float LMotorSpeed = MotorBasespeed - speedAdjust;
//  float RMotorSpeed = MotorBasespeed + speedAdjust;
//
//  if (LMotorSpeed < 0) LMotorSpeed = 0;
//  if (RMotorSpeed < 0) RMotorSpeed = 0;
//  if (LMotorSpeed > MAX_SPEED) LMotorSpeed = MAX_SPEED;
//  if (RMotorSpeed > MAX_SPEED) RMotorSpeed = MAX_SPEED; 
//
//  analogWrite(IN1, LMotorSpeed);
//  analogWrite(IN3, RMotorSpeed);
//  delay(10); }

void wallfollowingright(){
  usfd();usrightfd();
  //Serial.println(d4);
  Serial.println(d1);
  if (d1<12) left();
  else {
  if (d4>=5 && d4<=15) fd();
  else if (d4<5) left();
  else if (d4>15) fd();delay(500);right(); }    

}
    
  //  usfd(); Serial.print(d1); delay(100);Serial.print("  ");
//  usleftfd(); Serial.print(d2); delay(100);Serial.print("  ");
//  usleftbd(); Serial.print(d3); delay(100);Serial.print("  ");
//  usrightfd(); Serial.print(d4); delay(100);Serial.print("  "); 6
//  usrightbd(); Serial.print(d5); delay(100);Serial.print("  "); 7
//  Serial.println();
  
void wallfollowingleft() {
  usfd();usleftfd();
  //Serial.println(d4);
  Serial.println(d1);
  if (d1<12) right();
  else {
  if (d2>=5 && d2<=15) fd();
  else if (d2<5) right();
  else if (d2>15) fd();delay(100);left(); }   
}
