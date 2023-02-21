void setup() {
  Serial.begin(9600);
}

void loop() {
  int  sense0 = analogRead(A0);
  if(sense0>500){
    sense0=1;
  }
  else{
    sense0=0;
  }
  Serial.print(sense0);
  Serial.print(" ");
  int  sense1 = analogRead(A1);
  if(sense1>250){
    sense1=1;
  }
  else{
    sense1=0;
  }
  Serial.print(sense1);
  Serial.print(" ");
  int  sense2 = analogRead(A2);
  if(sense2<700){
    sense2=1;
  }
  else{
    sense2=0;
  }
  Serial.print(sense2);
  Serial.print(" ");
  int  sense3 = analogRead(A3);
  if(sense3<700){
    sense3=1;
  }
  else{
    sense3=0;
  }
  Serial.print(sense3);
  Serial.print(" ");
  int  sense4 = analogRead(A4);
  if(sense4>500){
    sense4=1;
  }
  else{
    sense4=0;
  }
  Serial.print(sense4);
  Serial.print(" ");
  int  sense5 = analogRead(A5);
  if(sense5>400){
    sense5=1;
  }
  else{
    sense5=0;
  }
  Serial.println(sense5);
  delay(100);
}
