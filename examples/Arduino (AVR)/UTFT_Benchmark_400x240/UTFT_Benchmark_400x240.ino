// UTFT_Demo_400x240 (C)2014 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of how to use most of the functions
// of the library with a supported display modules.
//
// This demo was made for modules with a screen resolution 
// of 400x240 pixels.
//
// This program requires the UTFT library.
//

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Arduino Uno / 2009:
// -------------------
// Standard Arduino Uno/2009 shield            : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno TFT shield        : <display model>,A5,A4,A3,A2
//
// Arduino Mega:
// -------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Mega      : <display model>,38,39,40,41
//
// Remember to change the model parameter to suit your display module!
//UTFT myGLCD(ITDB32WD,38,39,40,41);
UTFT myGLCD(ILI9327_8,38,39,40,41); //3.5" TFTLCD for arduino 2560 from mcufriend.com
//UTFT myGLCD(ILI9327_8,A2,A1,A3,A4); //3.5" TFTLCD for arduino 2560 from mcufriend.com on UNO

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
  int buf[398];
  int x, x2;
  int y, y2;
  int r;
  unsigned long start;
  unsigned long time;

  start = millis();
  for (int i=1; i<10; i++)
  {
    myGLCD.show_color_bar();
  }
  time = millis() - start;
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("Color bars", CENTER, 1);
  myGLCD.printNumI(time, CENTER, 16);
  delay(3000);

  myGLCD.clrScr();
  start = millis();
  for (int i=1; i<10; i++)
  {
    myGLCD.clrScr();
  }
  time = millis() - start;
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("clrSrc", CENTER, 1);
  myGLCD.printNumI(time, CENTER, 16);
  delay(3000);

  myGLCD.clrScr();

//// Draw some filled rectangles
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some filled rectangles", CENTER, 1);
//  for (int i=1; i<6; i++)
//  {
//    switch (i)
//    {
//      case 1:
//        myGLCD.setColor(255,0,255);
//        break;
//      case 2:
//        myGLCD.setColor(255,0,0);
//        break;
//      case 3:
//        myGLCD.setColor(0,255,0);
//        break;
//      case 4:
//        myGLCD.setColor(0,0,255);
//        break;
//      case 5:
//        myGLCD.setColor(255,255,0);
//        break;
//    }
//    myGLCD.fillRect(110+(i*20), 30+(i*20), 170+(i*20), 90+(i*20));
//  }
//
//  delay(2000);
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//
//// Draw some filled, rounded rectangles
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some filled, rounded rectangles", CENTER, 1);
//  for (int i=1; i<6; i++)
//  {
//    switch (i)
//    {
//      case 1:
//        myGLCD.setColor(255,0,255);
//        break;
//      case 2:
//        myGLCD.setColor(255,0,0);
//        break;
//      case 3:
//        myGLCD.setColor(0,255,0);
//        break;
//      case 4:
//        myGLCD.setColor(0,0,255);
//        break;
//      case 5:
//        myGLCD.setColor(255,255,0);
//        break;
//    }
//    myGLCD.fillRoundRect(230-(i*20), 30+(i*20), 290-(i*20), 90+(i*20));
//  }
//
//  delay(2000);
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//
//// Draw some filled circles
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some filled circles", CENTER, 1);
//  for (int i=1; i<6; i++)
//  {
//    switch (i)
//    {
//      case 1:
//        myGLCD.setColor(255,0,255);
//        break;
//      case 2:
//        myGLCD.setColor(255,0,0);
//        break;
//      case 3:
//        myGLCD.setColor(0,255,0);
//        break;
//      case 4:
//        myGLCD.setColor(0,0,255);
//        break;
//      case 5:
//        myGLCD.setColor(255,255,0);
//        break;
//    }
//    myGLCD.fillCircle(110+(i*30),60+(i*20), 30);
//  }
//
//  delay(2000);
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//
//// Draw some lines in a pattern
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some lines in a pattern", CENTER, 1);
//  myGLCD.setColor (255,0,0);
//  for (int i=15; i<224; i+=5)
//  {
//    myGLCD.drawLine(1, i, (i*1.77)-10, 224);
//  }
//  myGLCD.setColor (255,0,0);
//  for (int i=224; i>15; i-=5)
//  {
//    myGLCD.drawLine(398, i, (i*1.77)-11, 15);
//  }
//  myGLCD.setColor (0,255,255);
//  for (int i=224; i>15; i-=5)
//  {
//    myGLCD.drawLine(1, i, 411-(i*1.77), 15);
//  }
//  myGLCD.setColor (0,255,255);
//  for (int i=15; i<224; i+=5)
//  {
//    myGLCD.drawLine(398, i, 410-(i*1.77), 224);
//  }
//
//  delay(2000);
//
////  myGLCD.setColor(0,0,0);
//  myGLCD.fillRect(1,15,398,224);
//
//// Draw some random circles
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some random circles", CENTER, 1);
//  for (int i=0; i<100; i++)
//  {
//    myGLCD.setColor(random(255), random(255), random(255));
//    x=32+random(336);
//    y=45+random(146);
//    r=random(30);
//    myGLCD.drawCircle(x, y, r);
//  }
//
//  delay(2000);
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//
//// Draw some random rectangles
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some random rectangles", CENTER, 1);
//  for (int i=0; i<100; i++)
//  {
//    myGLCD.setColor(random(255), random(255), random(255));
//    x=2+random(396);
//    y=16+random(207);
//    x2=2+random(396);
//    y2=16+random(207);
//    myGLCD.drawRect(x, y, x2, y2);
//  }
//
//  delay(2000);
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//
//// Draw some random rounded rectangles
//myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw some random rounded rectangles", CENTER, 1);
//  for (int i=0; i<100; i++)
//  {
//    myGLCD.setColor(random(255), random(255), random(255));
//    x=2+random(396);
//    y=16+random(207);
//    x2=2+random(396);
//    y2=16+random(207);
//    myGLCD.drawRoundRect(x, y, x2, y2);
//  }
//  delay(2000);
//  myGLCD.clrScr();
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw random lines", CENTER, 1);
//
//  for (int i=0; i<100; i++)
//  {
//    myGLCD.setColor(random(255), random(255), random(255));
//    x=2+random(396);
//    y=16+random(209);
//    x2=2+random(396);
//    y2=16+random(209);
//    myGLCD.drawLine(x, y, x2, y2);
//  }
//
//  delay(2000);
// myGLCD.clrScr();
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("Draw random pixels", CENTER, 1);
//
////  myGLCD.setColor(0,0,0);
////  myGLCD.fillRect(1,15,398,224);
//
//  for (int i=0; i<10000; i++)
//  {
//    myGLCD.setColor(random(255), random(255), random(255));
//    myGLCD.drawPixel(2+random(396), 16+random(209));
//  }
//
// delay(2000);
//myGLCD.clrScr();
// // myGLCD.fillScr(0, 0, 255);
////  myGLCD.setColor(255, 0, 0);
////  myGLCD.fillRoundRect(120, 70, 279, 169);
//
//  myGLCD.setColor(255, 255, 255);
//  myGLCD.setBackColor(255, 0, 0);
//  myGLCD.print("That's it!", CENTER, 93);
//  myGLCD.print("Restarting in a", CENTER, 119);
//  myGLCD.print("few seconds...", CENTER, 132);
//
//  myGLCD.setColor(0, 255, 0);
//  myGLCD.setBackColor(0, 0, 255);
//  myGLCD.print("Runtime: (msecs)", CENTER, 210);
//  myGLCD.printNumI(millis(), CENTER, 225);
//
//  delay (5000);
}
