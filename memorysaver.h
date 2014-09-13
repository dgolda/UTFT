// UTFT Memory Saver
// -----------------
//
// Since most people have only one or possibly two different display modules a lot
// of memory has been wasted to keep support for many unneeded controller chips.
// You now have the option to remove this unneeded code from the library with
// this file.
// By disabling the controllers you don't need you can reduce the memory footprint
// of the library by several Kb.
//
// Uncomment the lines for the displaycontrollers that you don't use to save
// some flash memory by not including the init code for that particular
// controller.

//#define DISABLE_HX8347A			1	// ITDB32
//#define DISABLE_ILI9327			1	// ITDB32WC / TFT01_32W
//#define DISABLE_SSD1289			1	// ITDB32S / TFT_32 / GEEE32 / ELEE32_REVA / ELEE32_REVB	- This single define will disable both 8bit, 16bit and latched mode for this controller
//#define DISABLE_ILI9325C  		1	// ITDB24
//#define DISABLE_ILI9325D  		1	// ITDB24D / ITDB24DWOT / ITDB28 / TFT01_24_8 / TFT01_24_16	- This single define will disable both 8bit and 16bit mode for this controller
//#define DISABLE_HX8340B_8 		1	// ITDB22 8bit mode / GEEE22
//#define DISABLE_HX8340B_S 		1	// ITDB22 Serial mode
//#define DISABLE_HX8352A			1	// ITDB32WD / TFT01_32WD
//#define DISABLE_ST7735			1	// ITDB18SP
//#define DISABLE_PCF8833			1	// LPH9135
//#define DISABLE_S1D19122  		1	// ITDB25H
//#define DISABLE_SSD1963_480		1	// ITDB43
//#define DISABLE_SSD1963_800		1	// ITDB50
//#define DISABLE_S6D1121			1	// ITDB24E	- This single define will disable both 8bit and 16bit mode for this controller
//#define DISABLE_ILI9320			1	// GEEE24 / GEEE28	- This single define will disable both 8bit and 16bit mode for this controller
