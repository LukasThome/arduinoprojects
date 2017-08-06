
int led1 = 0;
int led2 = 1;
int chave1 = A3; 			//DeepSwitch declared

void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(chave1, INPUT);		

}

void loop() {  
digitalRead(A3);
  		
  if (digitalRead(A3) == 0){ 			//DeepSwitch off ...
	digitalWrite(led2, LOW);	
    	digitalWrite(led1, HIGH);	
  	
  	}else{					//DeepSwitch on ...
    	      digitalWrite(led1, LOW);	
    	      digitalWrite(led2, HIGH);	
  		
  	}
}
