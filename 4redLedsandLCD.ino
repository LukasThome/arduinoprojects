#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int led1 = 0;
int led2 = 1;
int chave1 = A3;
int chave2 = A2;
int chave3 = A1;
int chave4 = A0;


void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(chave1, INPUT);
  pinMode(chave2, INPUT);
  pinMode(chave3, INPUT);
  pinMode(chave4, INPUT);
  pinMode(1, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  lcd.begin(16, 2);
  
}


void loop() {  
  
//contador para o display	
int numerodepessoas = 0;
  		
//Se alguma chave for ativada  
if (digitalRead(A3)|| digitalRead(A2) || digitalRead(A1) || digitalRead(A0) == 1){   
	digitalWrite(led1, LOW);	
    	digitalWrite(led2, HIGH);	
  //Se todas desativadas
  }else{									      
    	digitalWrite(led2, LOW);	
    	digitalWrite(led1, HIGH);	
  }
  
  //Parâmetros do contador	
  if (digitalRead(A3) == 1){
    numerodepessoas++;
  }
  if (digitalRead(A2) == 1){
    numerodepessoas++;
  }  	
  if (digitalRead(A1) == 1){
    numerodepessoas++;
  }
  if (digitalRead(A0) == 1){
    numerodepessoas++;
  }
  
  if (numerodepessoas >=2){
   //leds vermelhos
   digitalWrite(6, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(10, HIGH);
   //leds verdes
   digitalWrite(0, LOW);
   digitalWrite(7, LOW);
   digitalWrite(9, LOW);
   delay(100);
  
 }else{
  //desliga os 3 leds vermelhos  
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10,LOW);
  }
  
  //informações para o lcd  
  lcd.print(numerodepessoas);
  lcd.print(" Pessoa(s)");
  lcd.setCursor(0, 1);
  lcd.print(" na sala");
  delay(1000);
  lcd.home();  
}
