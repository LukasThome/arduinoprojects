/*   
 * Genius usando shields Circuitar.
 * Criado para demonstração da utilização do Arduino em vídeos do canal 
 * Mundo da Elétrica no Youtube.
 *  
 * Este software tem finalidade didática e demonstrativa, e portanto 
 * aspectos relacionados a eficiência não são o objetivo. 
 * O progama é feito da maneira mais simples possível de entender e exigindo
 * apenas o conhecimento essencialmente necessário.
 *
 * Conheça o canal Mundo da Elétrica utilizando o link abaixo:
 * http://www.youtube.com/subscription_center?add_user=MundoDaEletrica
 *  
 * Autor: Alex Teixeira Benfica 
 * https://www.linkedin.com/in/alexbenfica   
 * 
 * Shield de interface (botões, leds e buzzer) e display:
 * https://www.circuitar.com.br/nanoshields/ * 
 * 
*/


// inclui os outros arquivos com códigos relativos a botoes, leds e buzzer
#include "botoes.h"
#include "leds.h"
#include "buzzer.h"

// https://www.arduino.cc/en/Reference/StringConstructor
// tem algumas funções básicas para lidar com texto
#include <String.h>

// permite a escrita em display utilizando o shield da Circuitar
#include "Nanoshield_LCD.h"

// Objeto lcd
Nanoshield_LCD lcd;


// inicializa a variavel que armazena a última tecla pressionada
int tecla = SEM_TECLA;

// número máximo de níveis que o sistema permite (limitado apenas pela memória RAM disponível)
#define maxNiveis 15
unsigned char genius[maxNiveis];
unsigned char jogador[maxNiveis];

// nivel atual do jogo a qualquer momento
int nivel = 0;

// número de teclas já pressionadas por um jogador em um determinado nível
unsigned char nTeclasJogadas = 0;

// tempo em que o som de cada tecla será tocado na vez de jogada do Genius
int tempoPlaySound = 500;

// determina de quem é a vez de jogar
#define VEZ_GENIUS 0
#define VEZ_JOGADOR 1
unsigned char vez = VEZ_GENIUS;




// Chama as funções de inicialização necessárias a cada elemento utilizado no projeto.
// Roda apenas 1 vez na inicialização.
void setup() {
    
    // Diversas inicializações de hardware e bibliotecas
    inicia_teclas();    
    inicia_leds();    
    inicia_buzzer();
    
    // Inicializa o gerador de numeros aleatorios lendo algum ruído de entradas analógicos
    randomSeed(analogRead(0));
    
    lcd.begin();
    
    // Estado inicial para os periféricos
    lcd.clear();    
}







// Exibe na tela a tecla a informação da tecla jogada e toca o som correspondente.
void mostra_jogada(unsigned char posicao){
    tone(BUZZER,map(posicao,2,5,50,255));                 
    lcd.clear();      
    switch(posicao){
        case TECLA_DIR:
            lcd.setCursor(13, 0);
            lcd.print(">>>");
            lcd.setCursor(13, 1);
            lcd.print(">>>");
        break;
        case TECLA_ESQ:
            lcd.setCursor(0, 0);
            lcd.print("<<<");
            lcd.setCursor(0, 1);
            lcd.print("<<<");                                
        break;
        case TECLA_CIMA:
            lcd.setCursor(4, 0);
            lcd.print("^^^^^^^^");
        break;
        case TECLA_BAIXO:
            lcd.setCursor(4, 1);
            lcd.print("vvvvvvvv");
        break;            
    }
}







// Função executada continuamente enquanto o Arduino está ligado.
void loop() {
    tecla = tecla_pressionada();    

    if(nivel == 0){
        // inicializa os niveis do genius
        for(int i=0;i<maxNiveis;i++){
            genius[i]=0;    
            jogador[i]=0;    
        }
        
        // contador de interações para modificar a mensagem que aparece na tela 
        // enquanto o jogo nao inicializa.
        unsigned char tMessage = 96;
        bool mute = false;
        while(tecla_pressionada() != TECLA_SEL){
            
            // permite silenciar o som incial do jogo pressional qualquer tecla direcional.
            if(tecla_pressionada() >= 2){
                mute = !mute;                
                if(mute){
                    lcd.clear();
                    lcd.print("   Silencio !");
                    noTone(BUZZER);
                }
                delay(400);                
            }
            
            if(tMessage == 96){                
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Genius: Mundo da");
                lcd.setCursor(0, 1);
                lcd.print("   Eletrica!");        
            }
            
            if(tMessage == 160){                
                lcd.clear();
                lcd.setCursor(1, 0);
                lcd.print("Pressione SEL");
                lcd.setCursor(2, 1);
                lcd.print("para iniciar!");                
                tMessage = 0;
            }
            tMessage+=4;
            
            
            if(!mute){
                // Faz o som aleatorio antes do jogo comecar
                tone(BUZZER,random(20, 255));
            }            
            // Tempo aleatorio para cada som...
            delay(random(30, 200));
            // Pisca o display de forma aleatoria, mais aceso que apagado!
            if(random(30, 200) % 4){
                lcd.backlight();         
            }
            else{
                lcd.noBacklight();
            }
            
        };  
        
        lcd.backlight();         
        tone(BUZZER,255);
        delay(1000);
        noTone(BUZZER);    
        
        genius_joga(tempoPlaySound);
    }    
    

    if(vez == VEZ_GENIUS){
        led(LED_AMARELO, ACESO);
        led(LED_VERDE,    APAGADO);
        genius_joga(tempoPlaySound);
    }
    
    if(vez == VEZ_JOGADOR){
        led(LED_VERDE,    ACESO);
        led(LED_AMARELO, APAGADO);
        if(tecla>=2){            
            if(tecla == genius[nTeclasJogadas]){            
                nTeclasJogadas++;
                

                mostra_jogada(tecla);
                
                delay(300);
                while(tecla_pressionada() == tecla){                
                    // espera até que o usuário tire o dedo da tecla para evitar ruídos de 
                    // há formas mais eficientes de lidar com este processo de "debounce", tanto por hardware quanto por software.
                    // nesse joguinho, isso é essencial para evitar um erro acidental.
                }
                noTone(BUZZER);
                lcd.clear();
                delay(200);
            }
            else{
                lcd.clear();               
                
                lcd.setCursor(0, 0);
                lcd.print(" Voce perdeu! :(");
                lcd.setCursor(0, 1);
                lcd.print(" Comece de novo!");                
                tone(BUZZER,30);                         
                delay(3000);
                noTone(BUZZER);                
                nivel = 0;
                vez = VEZ_GENIUS;
            }
            if(nTeclasJogadas == nivel){
                if(nivel == maxNiveis){
                    lcd.clear();
                    lcd.print("Voce venceu! :)");                
                    lcd.setCursor(0, 1);
                    lcd.print("   Parabens !");                
                    nivel = 0;
                    vez = VEZ_GENIUS;
                    delay(1000);
                    while(!tecla_pressionada()){
                        // aguarda pressionar alguma tecla e comeca de novo!
                    }
                }
                vez = VEZ_GENIUS;
            }
        }
        
    }
    
}



// vez do genius jogar... ele mostra os passos na tela e produz o som de cada tecla!
void genius_joga(unsigned int tempo){    
    // adiciona outra opcao na fila de sons
    genius[nivel] = random(2, 6);

    lcd.clear();        
    lcd.print("    Atencao !");        
    lcd.setCursor(5, 1);
    lcd.print("Nivel ");        
    lcd.print(String(nivel));        
    
    delay(1500);
    
    // muda de nivel
    nivel++;
    
    // toca o som e mostra as posicoes no display!
    for(int i=0;i<nivel;i++){                       
        delay(250);                
        mostra_jogada(genius[i]);
        delay(tempo);
        noTone(BUZZER);
        lcd.clear();                    
    }    
    vez = VEZ_JOGADOR;
    
    // Inicializa as jogadas do jogador...
    for(int i=0;i<maxNiveis;i++)jogador[i]=0;
    nTeclasJogadas = 0;
    
    tecla = SEM_TECLA;    
    lcd.clear();
    lcd.print("    Sua vez!");
}
