
int led1 = 0;
int led2 = 1;
int chave1 = A3;


void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(chave1, INPUT);

}


void loop() {  
  digitalRead(A3);
  		
  if (digitalRead(A3) == 0){ 				//Se a chave estiver desligada ...
	digitalWrite(led2, LOW);	
    	digitalWrite(led1, HIGH);	
  		}else{					//Se estiver ligada ...
    			digitalWrite(led1, LOW);	
    			digitalWrite(led2, HIGH);	
  		}
}
