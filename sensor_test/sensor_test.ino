int sense0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

void loop(){
  // put your main code here, to run repeatedly:
  sense0=analogRead(A0);
  Serial.println(sense0);
  delay(200);
}
