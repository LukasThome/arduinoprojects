int pinBotao = 1;
int pinLed = 0;
int estado = 0;
int buzzer = 7;
int sensor = A0;

void setup(){
 pinMode(pinBotao, INPUT);
 pinMode(pinLed, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(sensor, INPUT);

 }

void loop(){
  
  if (digitalRead(1) == 1 && estado == 0){ //se botao ativado ...
    while (digitalRead(1) ==1);    //enquanto botao ativado ...   
    digitalWrite(pinLed, HIGH);
    estado = 1; 
    noTone(buzzer);
   }
     
  if (digitalRead(1) == 1 && estado == 1){
      while (digitalRead(1) ==1);        
      digitalWrite(pinLed, LOW);
      estado = 0;
      noTone(buzzer);
	}
  
  if (digitalRead(A0) == 1 && estado == 1) {
    estado = 2;
	}
  
  if (estado == 2){
 	 tone(buzzer,3500);   
  }else{
    noTone(buzzer);
  }
 
  
}
  
  