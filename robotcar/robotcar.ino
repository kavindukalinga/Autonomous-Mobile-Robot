// Motors
# define IN1 4  // motors - right fd
# define IN2 5  // motors - right bw
# define IN3 6  // motors - left fd
# define IN4 7  // motors - left bw

// Sensors

//IR sensor array
# define IN1 4  
# define IN2 5
# define IN3 6
# define IN4 7
# define IN1 4
# define IN2 5

//Front IR sensors
# define IN3 6
# define IN4 7

//Front Ultrasonic sensor
# define IN3 6  // echo
# define IN4 7  // trigger

//Left Ultrasonic sensors
# define IN3 6  // front-echo
# define IN4 7  // front-trigger
# define IN3 6  // back-echo
# define IN4 7  // back-trigger

//Right Ultrasonic sensors
# define IN3 6  // front-echo
# define IN4 7  // front-trigger
# define IN3 6  // back-echo
# define IN4 7  // back-trigger

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
