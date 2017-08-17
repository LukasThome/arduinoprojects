int pinBotao = 1;
int pinLed = 0;
int estado = 0;
int buzzer = 7;
int sensor = A0;
int pinLedVerde = 2;
int pinLedAmarelo = 3;

void setup(){
 pinMode(pinBotao, INPUT);
 pinMode(pinLed, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(sensor, INPUT);
 pinMode(pinLedAmarelo, OUTPUT);
 pinMode(pinLedVerde, OUTPUT);
 }

void loop(){
  
  
  if (digitalRead(pinBotao) == 1 && estado == 0){ //se botao ativado ...
    while (digitalRead(pinBotao) ==1);    //enquanto botao ativado ...   
    digitalWrite(pinLedVerde, HIGH);
    digitalWrite(pinLed, LOW);
    digitalWrite(pinLedAmarelo, LOW);
    
    estado = 1; 
    noTone(buzzer);
    
   }
     
  if (digitalRead(1) == 1 && estado == 1){
     while (digitalRead(1) ==1);        
     digitalWrite(pinLedVerde, LOW);
     digitalWrite(pinLed, LOW);
     digitalWrite(pinLedAmarelo, HIGH);
    
     estado = 0;
     noTone(buzzer);
	}
  
  if (digitalRead(A0) == 1 && estado == 1){
     while (digitalRead(1) ==1);        
     digitalWrite(pinLedVerde, LOW);
     digitalWrite(pinLed, HIGH);
     digitalWrite(pinLedAmarelo, LOW);
    
     estado = 2;
     tone(buzzer,3500);   
  }
     if (estado == 2 && digitalRead(1) ==1){
     while (digitalRead(1) ==1);        
     digitalWrite(pinLedVerde, LOW);
     digitalWrite(pinLed, LOW);
     digitalWrite(pinLedAmarelo, HIGH);
    
     estado = 0;
     noTone(buzzer);

    
  
  }
  
}
  