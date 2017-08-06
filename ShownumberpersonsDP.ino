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

  lcd.begin(16, 2);
  
}


void loop() {  

  int numerodepessoas = 0;
  		
  if (digitalRead(A3)|| digitalRead(A2) || digitalRead(A1) || digitalRead(A0) == 1){   //Se todas as chaves estiverem desligadas ...
	digitalWrite(led1, LOW);	
    	digitalWrite(led2, HIGH);	
  	}else{									       //Se estiverem ligadas ...
    	digitalWrite(led2, LOW);	
    	digitalWrite(led1, HIGH);	
  }
  
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
  
  lcd.print(numerodepessoas);
  lcd.print(" Pessoa(s)");
  lcd.setCursor(0, 1);
  lcd.print(" na sala");
  delay(1000);
  lcd.home();  
}
