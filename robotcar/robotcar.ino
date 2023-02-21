// Motors
# define IN1 2  // motors - right fd
# define IN2 3  // motors - right bw
# define IN3 4  // motors - left fd
# define IN4 5  // motors - left bw

// Sensors

//IR sensor array
int IR1; //A0 
int IR2; //A1
int IR3; //A2
int IR4; //A3
int IR5; //A4
int IR6; //A5

//Front IR sensors
int IR7; //A6
int IR8; //A7

//Side IR sensors
int IR9; //A8  // left
int IR10; //A9  // right

//Front Ultrasonic sensor
# define US1 6  // echo
# define US2 22  // trigger

//Left Ultrasonic sensors
# define US3 7  // front-echo
# define US4 24  // front-trigger
# define US5 8  // back-echo
# define US6 26  // back-trigger

//Right Ultrasonic sensors
# define US7 9  // front-echo
# define US8 28  // front-trigger
# define US9 10  // back-echo
# define US10 30  // back-trigger

  bool startstatus = 0;
  bool mazestatus = 0;
  bool wallstatus = 0;
  bool boxstatus = 0;
  bool linestatus = 0;
  bool finishstatus = 0;

void setup() {
  
  pinMode(IN1,OUTPUT);pinMode(IN2,OUTPUT);pinMode(IN3,OUTPUT);pinMode(IN4,OUTPUT); // Car movements
  Serial.begin(9600);
}
void loop() {

  Serial.println("RobotX is starting Now");
 
  // Start
  if ( (startstatus==0) && (mazestatus==0) && (wallstatus ==0) && (boxstatus==0) && (linestatus==0) && (finishstatus==0) ) start();

  // Maze Solving
  if ( (startstatus==1) && (mazestatus==0) && (wallstatus ==0) && (boxstatus==0) && (linestatus==0) && (finishstatus==0) ) maze();
  
  // Wall following
  if ( (startstatus==1) && (mazestatus==1) && (wallstatus ==0) && (boxstatus==0) && (linestatus==0) && (finishstatus==0) ) wall();

  // Blind Box
  if ( (startstatus==1) && (mazestatus==1) && (wallstatus ==1) && (boxstatus==0) && (linestatus==0) && (finishstatus==0) ) box();

  // Line Following
  if ( (startstatus==1) && (mazestatus==1) && (wallstatus ==1) && (boxstatus==1) && (linestatus==0) && (finishstatus==0) ) line();

  // Finish
  if ( (startstatus==1) && (mazestatus==1) && (wallstatus ==1) && (boxstatus==1) && (linestatus==1) && (finishstatus==0) ) finish();

  if ( (startstatus==1) && (mazestatus==1) && (wallstatus ==1) && (boxstatus==1) && (linestatus==1) && (finishstatus==1) ) {
      Serial.println("Robot X is finished");
      delay(100000);
  }
  
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

  
  Serial.print(IR1);
  Serial.print(" ");
      
  Serial.print(IR2);
  Serial.print(" ");
      
  Serial.print(IR3);
  Serial.print(" ");
  
  Serial.print(IR4);
  Serial.print(" ");

  Serial.print(IR5);
  Serial.print(" ");
  
  Serial.println(IR6);
  delay(100);
  
}
