/* 
 * File:   lcd.h
 * Author: robot
 *
 * Created on 28 novembre 2014, 18:36
 */

#ifndef LCD_H
#define	LCD_H

void clrLCD();
void returnH();
void entryModeSet();
void dispONOFF();
void cursorDisp();
void setLCD();
void placeCursor(int, int);
void initLCD();
void writeLCD(char);
void writeStringLCD(char*);

#endif	/* LCD_H */

