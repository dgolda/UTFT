Unofficial version of UTFT library
==================================
Note: I've added alias ILI9327_8 for display type NIC35WS

This UTFT library original written by Henning Karlsen (see: http://www.henningkarlsen.com/electronics/library.php?id=51)
is modified by Damian Golda (based on NIC work) to support 3.5" TFTLCD for Arduino MEGA (2560) from mcufriend.com
(ILI9327 8 bit with customized timings etc).

THIS library was tested ONLY on:
1) Arduino MEGA clone and '3.5" TFTLCD for arduino 2560 from mcufriend.com' using:
UTFT myGLCD(ILI9327_8,38,39,40,41); //3.5" TFTLCD for arduino 2560 from mcufriend.com on MEGA

2) Arduino UNO clone and '3.5" TFTLCD for arduino 2560 from mcufriend.com' (this display is for MEGA board!) using
UTFT myGLCD(ILI9327_8,A2,A1,A3,A4); //3.5" TFTLCD for arduino 2560 from mcufriend.com on UNO

THIS library was NOT TESTED on Arduino UNO nor other displays, but if it works, please send me a note about your configuration and used arguments

This version IS NOT SUPPORTED by Henning Karlsen.
If you have problems - create issue on GitHub.

## Instalation
1. If you have installed original UTFT from Henning Karlsen, then first remove (or rename) UTFT frolder from Arduino Library folder
2. "Download":https://github.com/dgolda/UTFT/archive/master.zip the Master branch from gitHub.
3. Unzip and modify the Folder name to "UTFT" (Remove the '-master')
4. Paste the modified folder on your Library folder (On your `Libraries` folder inside Sketchbooks or Arduino software).

To test your display - open in Arduino IDE: Examples, UTFT, Arduino (AVR), UTFT_Demo_400x240.ino

Or make your own sketch using `ILI9327_8` driver:

    UTFT myGLCD(ILI9327_8,38,39,40,41); //3.5" TFTLCD for arduino 2560 from mcufriend.com

## History

* version 1.0 of original library from Henning Karlsen was modified by unknown author(s) to support 3.5" TFTLCD for arduino 2560 from mcufriend.com
* merge changes from version 1.3, all customized code was put in conditional directives
* merge changes from version 2.1
* merge changes from version 2.41
* merge changes from version 2.76
* merge changes from version 2.77
* merge changes from version 2.78
