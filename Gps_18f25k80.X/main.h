

#ifndef MAIN_H
#define	MAIN_H


#include <xc.h>
#include <htc.h>
#include <pic18f25k80.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include "uart.h"
#include "lcd.h"

#define _XTAL_FREQ 8000000 //à checker dans les paramètres oscill.

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

#endif	/* MAIN_H */

