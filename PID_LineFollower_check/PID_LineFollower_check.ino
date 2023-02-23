#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4
#define IR6 A5

#define RMotor 2
#define LMotor 4
float MAX_SPEED=120;
int MotorBasespeed = 70;

int IR_val[6] = {0, 0, 0, 0, 0, 0};
int IR_weights[6] = {-20,-10,-5,5,10,20};

float P, I, D;
float error = 0;
float previousError = 0;
float Kp = 5.5;
float Kd = 10; 
float Ki = 0;

void setup()
{
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);

  pinMode(LMotor, OUTPUT);
  pinMode(RMotor, OUTPUT);
}


void loop()
{
  IR_val[0] = digitalRead(IR1);
  IR_val[1] = digitalRead(IR2);
  IR_val[2] = digitalRead(IR3);
  IR_val[3] = digitalRead(IR4);
  IR_val[4] = digitalRead(IR5);
  IR_val[5] = digitalRead(IR6);
  
  error =0;

  for (int i = 0; i < 6; i++)
  {
    error += IR_weights[i] * IR_val[i];
  }

  P = error;
  I = I + error;
  D = error - previousError;

  previousError = error;

  float speedAdjust = (Kp * P + Ki * I + Kd * D);

  float LMotorSpeed = MotorBasespeed - speedAdjust;
  float RMotorSpeed = MotorBasespeed + speedAdjust;

  if (LMotorSpeed < 0)
  {
    LMotorSpeed = 0;
  }
  if (RMotorSpeed < 0)
  {
    RMotorSpeed = 0;
  }
  if (LMotorSpeed > MAX_SPEED)
  {
    LMotorSpeed = MAX_SPEED;
  }
  if (RMotorSpeed > MAX_SPEED)
  {
    RMotorSpeed = MAX_SPEED;
  }
  
  analogWrite(LMotor, LMotorSpeed);
  analogWrite(RMotor, RMotorSpeed);
  delay(100);
}
