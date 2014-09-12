/*
  UTFT.h - Arduino/chipKit library support for Color TFT LCD Boards
  Copyright (C)2010-2012 Henning Karlsen. All right reserved
  
  This library is the continuation of my ITDB02_Graph, ITDB02_Graph16
  and RGB_GLCD libraries for Arduino and chipKit. As the number of 
  supported display modules and controllers started to increase I felt 
  it was time to make a single, universal library as it will be much 
  easier to maintain in the future.

  Basic functionality of this library was origianlly based on the 
  demo-code provided by ITead studio (for the ITDB02 modules) and 
  NKC Electronics (for the RGB GLCD module/shield).

  This library supports a number of 8bit, 16bit and serial graphic 
  displays, and will work with both Arduino and chipKit boards. For a 
  full list of tested display modules and controllers, see the 
  document UTFT_Supported_display_modules_&_controllers.pdf.

  When using 8bit and 16bit display modules there are some 
  requirements you must adhere to. These requirements can be found 
  in the document UTFT_Requirements.pdf.
  There are no special requirements when using serial displays.

  You can always find the latest version of the library at 
  http://electronics.henningkarlsen.com/

  If you make any modifications or improvements to the code, I would 
  appreciate that you share the code with me so that I might include 
  it in the next release. I can be contacted through 
  http://electronics.henningkarlsen.com/contact.php.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef UTFT_h
#define UTFT_h

#define LEFT 0
#define RIGHT 9999
#define CENTER 9998

#define PORTRAIT 0
#define LANDSCAPE 1

#define HX8347A			0
#define ILI9327			1
#define SSD1289			2
#define ILI9325C		3
#define ILI9325D_8		4
#define ILI9325D_16		5
#define HX8340B_8		6
#define HX8340B_S		7
#define HX8352A			8
#define ST7735			9
#define PCF8833			10
#define S1D19122		11
#define SSD1963_480		12
#define SSD1963_800		13
#define S6D1121_8		14
#define S6D1121_16		15

#define ITDB32			0	// HX8347-A (16bit)
#define ITDB32WC		1	// ILI9327  (16bit)
#define TFT01_32W		1	// ILI9327	(16bit)
#define ITDB32S			2	// SSD1289  (16bit)
#define TFT01_32		2	// SSD1289  (16bit)
#define ITDB24			3	// ILI9325C (8bit)
#define ITDB24D			4	// ILI9325D (8bit)
#define ITDB24DWOT		4	// ILI9325D (8bit)
#define ITDB28			4	// ILI9325D (8bit)
#define TFT01_24_8		4	// ILI9325D (8bit)
#define TFT01_24_16		5	// ILI9325D (16bit)
#define ITDB22			6	// HX8340-B (8bit)
#define ITDB22SP		7	// HX8340-B (Serial)
#define ITDB32WD		8	// HX8352-A (16bit)
#define TFT01_32WD		8	// HX8352A	(16bit)
#define ITDB18SP		9	// ST7735   (Serial)
#define LPH9135			10	// PCF8833	(Serial)
#define ITDB25H			11	// S1D19122	(16bit)
#define ITDB43			12	// SSD1963	(16bit) 480x272
#define ITDB50			13	// SSD1963	(16bit) 800x480
#define ITDB24E_8		14	// S6D1121	(8bit)
#define ITDB24E_16		15	// S6D1121	(16bit)

#define SERIAL_4PIN		4
#define SERIAL_5PIN		5

#if defined(__AVR__)
	#if defined(ARDUINO) && ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
	#include "HW_AVR_defines.h"
#else
	#include "WProgram.h"
	#include "HW_PIC32_defines.h"
#endif

struct _current_font
{
	uint8_t* font;
	uint8_t x_size;
	uint8_t y_size;
	uint8_t offset;
	uint8_t numchars;
};

class UTFT
{
	public:
		UTFT();
		UTFT(byte model, int RS, int WR,int CS, int RST, int SER=0);
		void InitLCD(byte orientation=LANDSCAPE);
		void clrScr();
		void drawPixel(int x, int y);
		void drawLine(int x1, int y1, int x2, int y2);
		void fillScr(byte r, byte g, byte b);
		void drawRect(int x1, int y1, int x2, int y2);
		void drawRoundRect(int x1, int y1, int x2, int y2);
		void fillRect(int x1, int y1, int x2, int y2);
		void fillRoundRect(int x1, int y1, int x2, int y2);
		void drawCircle(int x, int y, int radius);
		void fillCircle(int x, int y, int radius);
		void setColor(byte r, byte g, byte b);
		void setBackColor(byte r, byte g, byte b);
		void print(char *st, int x, int y, int deg=0);
		void print(String st, int x, int y, int deg=0);
		void printNumI(long num, int x, int y, int length=0, char filler=' ');
		void printNumF(double num, byte dec, int x, int y, char divider='.', int length=0, char filler=' ');
		void setFont(uint8_t* font);
		void drawBitmap(int x, int y, int sx, int sy, bitmapdatatype data, int scale=1);
		void drawBitmap(int x, int y, int sx, int sy, bitmapdatatype data, int deg, int rox, int roy);
		void lcdOff();
		void lcdOn();
		void setContrast(char c);
		int  getDisplayXSize();
		int	 getDisplayYSize();

	protected:
		byte fcolorr,fcolorg,fcolorb;
		byte bcolorr,bcolorg,bcolorb;
		byte orient;
		long disp_x_size, disp_y_size;
		byte display_model, display_transfer_mode, display_serial_mode;
		regtype *P_RS, *P_WR, *P_CS, *P_RST, *P_SDA, *P_SCL;
		regsize B_RS, B_WR, B_CS, B_RST, B_SDA, B_SCL;
		_current_font	cfont;

		void LCD_Writ_Bus(char VH,char VL, byte mode);
		void LCD_Write_COM(char VL);
		void LCD_Write_DATA(char VH,char VL);
		void LCD_Write_DATA(char VL);
		void LCD_Write_COM_DATA(char com1,int dat1);
		void setPixel(byte r,byte g,byte b);
		void drawHLine(int x, int y, int l);
		void drawVLine(int x, int y, int l);
		void printChar(byte c, int x, int y);
		void setXY(word x1, word y1, word x2, word y2);
		void clrXY();
		void rotateChar(byte c, int x, int y, int pos, int deg);
		void _set_direction_registers(byte mode);
};

#endif