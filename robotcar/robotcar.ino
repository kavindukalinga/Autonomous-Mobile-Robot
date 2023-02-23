const float sec_to_microsec = 1000000.0;
const float meter_to_cm = 100.0;
const float speed_of_sound = 340.0; //meters per second
float MAX_SPEED=120;
int MotorBasespeed = 70;
int usdelay=100;


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
  
  Serial.begin(9600);
}
void loop() {
  analogWrite(IN5,250);//right speed
  analogWrite(IN6,250); // left speed
  digitalWrite(IN1,HIGH);digitalWrite(IN3,HIGH);
  delay(10);
  digitalWrite(IN1,LOW);digitalWrite(IN3,LOW);
  delay(20);
  //LineFollow(10000);
  //Serial.println("RobotX is starting Now");
  //IRsensorarray();
  //delay(100);

  //irfd();Serial.print(IR7);Serial.print("   ");Serial.print(IR8);
  
  //usfd(); Serial.print(d1); delay(100);Serial.print("  ");
  //usleftfd(); Serial.print(d2); delay(100);Serial.print("  ");
  //usleftbd(); Serial.print(d3); delay(100);Serial.print("  ");
  //usrightfd(); Serial.print(d4); delay(100);Serial.print("  ");
  //usrightbd(); Serial.print(d5); delay(100);Serial.print("  ");
  //Serial.println();
  
}


void fd(){  //Car goes Forward
  digitalWrite(IN1,HIGH);digitalWrite(IN3,HIGH); delay(100);  //we should change the delay time when practise
  digitalWrite(IN1,LOW);digitalWrite(IN3,LOW);
}

void bw(){  //Car goes backward
  digitalWrite(IN2,HIGH);digitalWrite(IN4,HIGH); delay(100);  //we should change the delay time when practise
  digitalWrite(IN2,LOW);digitalWrite(IN4,LOW);
}

void right(){  //Car turns right
  digitalWrite(IN2,HIGH);digitalWrite(IN3,HIGH); delay(100);  //we should change the delay time when practise
  digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);
}

void left(){  //Car turns left
  digitalWrite(IN1,HIGH);digitalWrite(IN4,HIGH); delay(100);  //we should change the delay time when practise
  digitalWrite(IN1,LOW);digitalWrite(IN4,LOW);
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
  delay(1000);
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
  
  if(sense0>500) IR1=1;
  else IR1=0;
  
  if(sense1>250) IR2=1;
  else IR2=0;

  if(sense2<700) IR3=1;
  else IR3=0;

  if(sense3<700) IR4=1;
  else IR4=0;

  if(sense4>500) IR5=1;
  else IR5=0;

  if(sense5>400) IR6=1;
  else IR6=0;

  
//  Serial.print(IR1);Serial.print(" ");
//  Serial.print(IR2);Serial.print(" ");
//  Serial.print(IR3);Serial.print(" ");
//  Serial.print(IR4);Serial.print(" ");
//  Serial.print(IR5);Serial.print(" ");
//  Serial.println(IR6);delay(100);
  
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

void LineFollow(int LineFollowDuration){
  int IR_val[6] = {0, 0, 0, 0, 0, 0};
  int IR_weights[6] = {-20,-10,-5,5,10,20};

  float P, I, D;
  float error = 0;
  float previousError = 0;
  float Kp = 5.5;
  float Kd = 10; 
  float Ki = 0;
  int LineItter= LineFollowDuration/100;
  for(int j=0;j<LineItter;j++){
  IRsensorarray();
  IR_val[0] = IR1;IR_val[1] =IR2;IR_val[2] = IR3;IR_val[3] = IR4;
  IR_val[4] = IR5;IR_val[5] = IR6;
  error =0;
  for (int i = 0; i < 6; i++){
    error += IR_weights[i] * IR_val[i];}

  P = error;
  I = I + error;
  D = error - previousError;

  previousError = error;

  float speedAdjust = (Kp * P + Ki * I + Kd * D);

  float LMotorSpeed = MotorBasespeed - speedAdjust;
  float RMotorSpeed = MotorBasespeed + speedAdjust;

  if (LMotorSpeed < 0) LMotorSpeed = 0;
  if (RMotorSpeed < 0) RMotorSpeed = 0;
  if (LMotorSpeed > MAX_SPEED) LMotorSpeed = MAX_SPEED;
  if (RMotorSpeed > MAX_SPEED) RMotorSpeed = MAX_SPEED; 

  analogWrite(IN3, LMotorSpeed);
  analogWrite(IN1, RMotorSpeed);
  delay(100); }
}
