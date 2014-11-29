/*
* File: newmain.c
* Author: Tristan
*
* Created on 24 novembre 2014, 00:04
*/
#include "main.h"




 //ANCON0 = 0b00000000; //AIN4 is used as analog input
//ADCON1 = 0b00000111; //AIN8,9, and 10 are used as analog input
//ADCON2 = 0xBC; //20 TAD, Fosc/4
//ADON = 0; //enable ADC


void interrupt low_priority high_isr(void) { // interruption de l'UART
if (RC2IF /*&& PIE3bits.TX2IE*/) {

}
RC2IF = 0; // On met le flag a 0
}




void main()

{

    initComms();

    GIE = 1;
    PEIE = 1;
    INTCON =0b11100000;
    OSCCON = 0x30; //4MHz
    ANCON0 = 0b00000000; //AIN4 is used as analog input
    ADON = 0; //enable ADC

    
    TRISA=0b00000000;
    TRISB=0b10000000;
    TRISC=0b00000000;

    char msg[80] = "Tristan a une petite";

    initLCD();

    placeCursor(1,1);
    writeStringLCD("pas moi ");
    placeCursor(2,1);
    writeStringLCD(msg);

    while(1)
    {

    }

}

