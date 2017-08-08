#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//leds vermelhos
int vermelho1 = 1;
int vermelho2 = 6;
int vermelho3 = 8;
int vermelho4 = 10;
//chaves
int chave1 = A3;
int chave2 = A2;
int chave3 = A1;
int chave4 = A0;
//leds verdes
int verde1 = 0;
int verde2 = 7;
int verde3 = 9;
int verde4 = 13;

void setup() {
  //Declaração de saída para os leds verdes
  pinMode(verde1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(verde3, OUTPUT);
  pinMode(verde4, OUTPUT);
  // para os leds vermelhos
  pinMode(vermelho1, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(vermelho3, OUTPUT);
  pinMode(vermelho4, OUTPUT);
  // Declaração de entrada para as chaves
  pinMode(chave1, INPUT);
  pinMode(chave2, INPUT);
  pinMode(chave3, INPUT);
  pinMode(chave4, INPUT);
 // Inicia o lcd 16x2
  lcd.begin(16, 2);
  
}


void loop() {  

  int numerodecarros = 0;                   //variavel para guardar o numero de carros
 
  //Leitura da chave 1
  if (digitalRead(A3) == 1){
  	digitalWrite(verde1, LOW);
    digitalWrite(vermelho1, HIGH);
     
    }else{
    digitalWrite(verde1, HIGH);
    digitalWrite(vermelho1, LOW);
    numerodecarros++; 
  }
  //leitura da chave 2
  if (digitalRead(A2) == 1){
  	digitalWrite(verde2, LOW);
    digitalWrite(vermelho2, HIGH);
     
 	  }else{
    digitalWrite(verde2, HIGH);
    digitalWrite(vermelho2, LOW);
    numerodecarros++; 
  }
  //leitura da chave 3
   if (digitalRead(A1) == 1){
  	digitalWrite(verde3, LOW);
    digitalWrite(vermelho3, HIGH);
    
  	}else{
    digitalWrite(verde3, HIGH);
    digitalWrite(vermelho3, LOW);
    numerodecarros++; 
   }
  //leitura da chave 4
   if (digitalRead(A0) == 1){
  	digitalWrite(verde4, LOW);
    digitalWrite(vermelho4, HIGH);
    
  	}else{
    digitalWrite(verde4, HIGH);
    digitalWrite(vermelho4, LOW);
    numerodecarros++; 
   }
  if (numerodecarros == 0){
    lcd.clear();
    lcd.print(" LOTADO");
  	delay(2000);
   
  }else{
  
  //informações para o lcd  
  lcd.print(numerodecarros);
  lcd.print(" Vaga(s)");
  lcd.setCursor(0, 1);
  lcd.print("livre(s)");
  delay(1000);
  lcd.home();  
  }
}
