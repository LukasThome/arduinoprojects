
int led1 = 0;
int led2 = 1;


void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}


void loop() {
  digitalWrite(led1, HIGH);   
  delay(1000);               
  digitalWrite(led1, LOW);    
  digitalWrite(led2, HIGH);
  delay(1000);
  digitalWrite(led2, LOW);
  
}