#include "stm32f103xb.h"

// Define Morse code for letters and numbers
char letters[26][5] = {
    ".-  ", // A
    "-...", // B
    "-.-.", // C
    "-.. ", // D
    ".   ", // E
    "..-.", // F
    "--. ", // G
    "....", // H
    "..  ", // I
    ".---", // J
    "-.- ", // K
    ".-..", // L
    "--  ", // M
    "-.  ", // N
    "--- ", // O
    ".--.", // P
    "--.-", // Q
    ".-. ", // R
    "... ", // S
    "-   ", // T
    "..- ", // U
    "...-", // V
    ".-- ", // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z 
};

char numbers[10][5] = {
    "-----",    // 0
    ".----",    // 1
    "..---",    // 2
    "...--",    // 3
    "....-",    // 4
    ".....",    // 5
    "-....",    // 6
    "--...",    // 7
    "---..",    // 8
    "----.",    // 9
};

void led(_Bool on){
    if(on){
        GPIOC->BRR=(1<<13); //Liga o Led
    }else{
        GPIOC->BSRR=(1<<13); //Apaga o LED
    }
}

void delay(int time){
    const int 
    for( int i = time * 1000000; i > 0; i-- );
}

void playChar(char c) {
    int i=0;
    
    if( c == ' ' ){
        delay(2);
    }else{

        char *morsechar;
        int dif = c-'A';
        if( dif >= 0 ){
            morsechar = &letters[0][0];
        }else{
            morsechar = &numbers[0][0];
			dif += 17;
        }

        int fimdecaractere = 0;

        while ( i < 5 && !fimdecaractere) {
            led(1);
            if (morsechar[dif*5 + i] == '.'){
                    delay(1);   // dot
            }else if(morsechar[dif*5 + i] == '-'){
                    delay(3); // dash 
            }else{
                fimdecaractere = 1;
            }

            led(0);
            delay(1); // pause between elements
            i++;
        }
    }
    delay(1); // extra pause between characters
}
		
void playStr(char msg[]) {
    int i=0;

    while(msg[i]) 
        playChar(msg[i++]);
}

void init(void) {

    RCC->APB2ENR |= (1<<4);
    
    GPIOC->CRH&=~(0x0F<<20);
    GPIOC->CRH|=(1<<21);	

    while (1) {
      playStr("CODIGO DE VELASKO");
        delay(4); // extra pause between loops
  }
}
