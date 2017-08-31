int redLED = 11;
int blueLED = 0;
int yellowLED = 3;
int greenLED = 6;
int redBtn = 1;
int blueBtn = 2;
int yellowBtn = 5;
int greenBtn = 10;
int buzzer = 12;
//int resetBtn = RESET;


//Definindo TONS

int redTone = 310;
int blueTone = 209;
int yellowTone = 252;
int greenTone = 415;
int errorTone = 42;

//Criando vetor para os tons

int tons[4] = {redTone, blueTone, greenTone, yellowTone};



void setup() {
  
pinMode(redLED, OUTPUT);
pinMode(blueLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);  
pinMode(redBtn, INPUT);
pinMode(blueBtn, INPUT);
pinMode(yellowBtn, INPUT);
pinMode(greenBtn, INPUT);
//pinMode(resetBtn, INPUT);       
pinMode(buzzer, OUTPUT); 
        
}

void loop() {
  

  
  
}






