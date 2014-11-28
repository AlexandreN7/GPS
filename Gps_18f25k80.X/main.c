/*
* File: newmain.c
* Author: Tristan
*
* Created on 24 novembre 2014, 00:04
*/
#include "main.h"


#define _XTAL_FREQ 4000000 //à checker dans les paramètres oscill.

// Configuration register
// CONFIG1L
#pragma config RETEN = OFF // VREG Sleep Enable bit (Ultra low-power regulator is Disabled (Controlled by REGSLP bit))
#pragma config INTOSCSEL = HIGH // LF-INTOSC Low-power Enable bit (LF-INTOSC in High-power mode during Sleep)
#pragma config SOSCSEL = DIG // SOSC Power Selection and mode Configuration bits (Digital (SCLKI) mode)
#pragma config XINST = OFF // Extended Instruction Set (Disabled)
// CONFIG1H
#pragma config FOSC = INTIO2 // Oscillator (Internal RC oscillator)
#pragma config PLLCFG = ON // PLL x4 Enable bit (Disabled)
#pragma config FCMEN = OFF // Fail-Safe Clock Monitor (Disabled)
#pragma config IESO = ON // Internal External Oscillator Switch Over Mode (Disabled)
// CONFIG2L
#pragma config PWRTEN = OFF // Power Up Timer (Disabled)
#pragma config BOREN = SBORDIS // Brown Out Detect (Enabled in hardware, SBOREN disabled)
#pragma config BORV = 3 // Brown-out Reset Voltage bits (1.8V)
#pragma config BORPWR = ZPBORMV // BORMV Power level (ZPBORMV instead of BORMV is selected)
// CONFIG2H
#pragma config WDTEN = OFF // Watchdog Timer (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config WDTPS = 1048576 // Watchdog Postscaler (1:1048576)
// CONFIG3H
#pragma config CANMX = PORTB // ECAN Mux bit (ECAN TX and RX pins are located on RB2 and RB3, respectively)
#pragma config MSSPMSK = MSK7 // MSSP address masking (7 Bit address masking mode)
#pragma config MCLRE = OFF // Master Clear Enable (MCLR Disabled, RG5 Enabled)
// CONFIG4L
#pragma config STVREN = ON // Stack Overflow Reset (Enabled)
#pragma config BBSIZ = BB2K // Boot Block Size (2K word Boot Block size)
// CONFIG5L
#pragma config CP0 = OFF // Code Protect 00800-01FFF (Disabled)
#pragma config CP1 = OFF // Code Protect 02000-03FFF (Disabled)
#pragma config CP2 = OFF // Code Protect 04000-05FFF (Disabled)
#pragma config CP3 = OFF // Code Protect 06000-07FFF (Disabled)
// CONFIG5H
#pragma config CPB = OFF // Code Protect Boot (Disabled)
#pragma config CPD = OFF // Data EE Read Protect (Disabled)
// CONFIG6L
#pragma config WRT0 = OFF // Table Write Protect 00800-03FFF (Disabled)
#pragma config WRT1 = OFF // Table Write Protect 04000-07FFF (Disabled)
#pragma config WRT2 = OFF // Table Write Protect 08000-0BFFF (Disabled)
#pragma config WRT3 = OFF // Table Write Protect 0C000-0FFFF (Disabled)
// CONFIG6H
#pragma config WRTC = OFF // Config. Write Protect (Disabled)
#pragma config WRTB = OFF // Table Write Protect Boot (Disabled)
#pragma config WRTD = OFF // Data EE Write Protect (Disabled)
// CONFIG7L
#pragma config EBTR0 = OFF // Table Read Protect 00800-03FFF (Disabled)
#pragma config EBTR1 = OFF // Table Read Protect 04000-07FFF (Disabled)
#pragma config EBTR2 = OFF // Table Read Protect 08000-0BFFF (Disabled)
#pragma config EBTR3 = OFF // Table Read Protect 0C000-0FFFF (Disabled)
// CONFIG7H
#pragma config EBTRB = OFF // Table Read Protect Boot (Disabled)


#define D0 PORTCbits.RC0 //data0
#define D1 PORTCbits.RC1 //data1
#define D2 PORTCbits.RC2 //data2
#define D3 PORTCbits.RC3 //data3
#define D4 PORTCbits.RC4 //data4
#define D5 PORTCbits.RC5 //data5
#define D6 PORTCbits.RC6 //data6
#define D7 PORTCbits.RC7 //data7

#define RS PORTBbits.RB5 // RS = 1 : donnees RS = 0 : instructions
#define RW PORTAbits.RA1 // RW = 1 : lire donnees sur l'ecran RW = 0 : ecrire donnees sur l'ecran
#define EN PORTBbits.RB3 // EN = 1 : enable l'ecriture/lecture

 //ANCON0 = 0b00000000; //AIN4 is used as analog input
//ADCON1 = 0b00000111; //AIN8,9, and 10 are used as analog input
//ADCON2 = 0xBC; //20 TAD, Fosc/4
//ADON = 0; //enable ADC



void clrLCD()  //Clears display and returns cursor to the home position (address 0).
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(10);

//INSTRUCTIONS
    D0=1; //***
    D1=0;
    D2=0;
    D3=0;
    D4=0;
    D5=0;
    D6=0;
    D7=0;

    EN=1;
    __delay_ms(10);

    EN=0;
    __delay_ms(10);

}


void returnH()  //Returns cursor to the home position (address 0) without changing memory.
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(10);

//INSTRUCTIONS
    D0=0;
    D1=1; //***
    D2=0;
    D3=0;
    D4=0;
    D5=0;
    D6=0;
    D7=0;

    EN=1;
    __delay_ms(10);

    EN=0;
    __delay_ms(10);

}


void entryModeSet()
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    D0=0; //If S = 1 the display will be shifted to the left (if I/D = 1) or right (if I/D = 0) on subsequent DD RAM write operations.
    D1=1; //Specifies whether to increment (D1 = 1) or decrement (D1 = 0) the address counter after subsequent DD RAM operations.
    D2=1; //***
    D3=0;
    D4=0;
    D5=0;
    D6=0;
    D7=0;

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


void dispONOFF()
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    D0=0; //Sets blinking of cursor position character.
    D1=1; //Sets cursor On(1)/Off(0).
    D2=1; //Sets On(1)/Off(0) all display.
    D3=1; //***
    D4=0;
    D5=0;
    D6=0;
    D7=0;

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


void cursorDisp()
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    D0=0; //*
    D1=0; //*
    D2=0; //Shift direction (R/L)
    D3=1; //Sets display-shift or cursor-move (S/C)
    D4=1; //***
    D5=0;
    D6=0;
    D7=0;

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


void setLCD() //Sets interface data length (DL), number of display lines (N) and character font (F).
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    D0=0; //*
    D1=0; //*
    D2=0; // 0: 5x8matrice --- 1: 5x11matrice
    D3=1; // 1: 2 lignes --- 0: 1 ligne
    D4=1; // 1: 8bits --- 0: 4bits
    D5=1; //***
    D6=0;
    D7=0;

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


void placeCursor(int ligne, int colonne)
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    if(ligne==1)
    {
        PORTC = 0x80 + 0x00 + (colonne-1);
    }
    else if(ligne==2)
    {
        PORTC = 0x80 + 0x40 + (colonne-1);
    }
    else
    {

    }

    __delay_ms(1);

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


void initLCD()
{

    clrLCD();
    setLCD();
    dispONOFF();
    entryModeSet();
    clrLCD();
    __delay_ms(1);

}


void writeLCD(char letter)
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    RS=1; //Selection du registre data

    PORTC = letter;

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


void writeStringLCD(char *phrase)
{

    while(*phrase)
    {
        writeLCD(*phrase++);
    }

}

int main(int argc, char** argv)

{

    TRISA=0b00000000;
    TRISB=0b00000000;
    TRISC=0b00000000;

    char msg[80] = "Joyeux Noel ! Boules et Guirlandes !";

    initLCD();

    writeStringLCD(msg);
    placeCursor(2,5);
    writeStringLCD("Caca de Pere Noel !");

    while(1)
    {
        cursorDisp();
        __delay_ms(100);__delay_ms(100);__delay_ms(100);__delay_ms(100);__delay_ms(100);
        __delay_ms(100);
    }

}

