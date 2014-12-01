#include "main.h"


void clrLCD()  //Clears display and returns cursor to the home position (address 0).
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

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
    __delay_ms(20);

    EN=0;
    __delay_ms(1);

}


void returnH()  //Returns cursor to the home position (address 0) without changing memory.
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

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
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

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


void cursorDisp(int SC, int RL)
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    D0=0; //*
    D1=0; //*
    D2=RL; //Shift direction (R/L)
    D3=SC; //Sets display-shift or cursor-move (S/C)
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


void writeLCD(char lettre)
{

//INITIALISATION
    RS=0; //Selection du registre d'instructions
    RW=0; //Write sur le LCD
    EN=0;
    __delay_ms(1);

//INSTRUCTIONS
    RS=1; //Selection du registre data

    PORTC = lettre;

    EN=1;
    __delay_ms(1);

    EN=0;
    __delay_ms(1);

}


int lengthMess(char *phrase)
{

    int taille=0;

    while(*phrase)
    {
        taille++;
        *phrase++;
    }

    return taille;

}



void writeStringLCD(char *phrase)
{

    int i=0;
    int taille=0;

    taille = lengthMess(phrase);

    while(*phrase)
    {
        writeLCD(*phrase++);
    }

    if(taille>16 && taille<=40)
    {
        __delay_ms(100);__delay_ms(100);
        
        for(i=1;i<=(taille-16);i++)
        {
            cursorDisp(1,0);
            __delay_ms(100);
        }

        __delay_ms(100);__delay_ms(100);
    }
    
}


