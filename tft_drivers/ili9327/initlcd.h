case ILI9327:
	LCD_Write_COM(0xE9);
	LCD_Write_DATA(0x00, 0x20);
	LCD_Write_COM(0x11); //Exit Sleep
	delay(100);
	LCD_Write_COM(0xD1);//VCOM Control
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x71);
	LCD_Write_DATA(0x00, 0x19);

	LCD_Write_COM(0xD0);//Power_Setting
	LCD_Write_DATA(0x00, 0x07);
	LCD_Write_DATA(0x00, 0x01);
	LCD_Write_DATA(0x00, 0x08);

	LCD_Write_COM(0x36);//set_address_mode
	LCD_Write_DATA(0x00, 0x48);//Page Address Order:Top to Bottom,Column Address Order:Right to Left,Page/Column Order:Normal Mode,Line Address Order:LCD Refresh Top to Bottom
                              		//RGB/BGR Order:Pixels sent in BGR order, Display Data Latch Data Order:Not supported, Horizontal Flip:Normal display, Vertical Flip: Normal display

	LCD_Write_COM(0x3A);//set_pixel_format
	LCD_Write_DATA(0x00, 0x05);//DBI:16bit/pixel (65,536 colors)

	LCD_Write_COM(0xC1);//Display_Timing_Setting for Normal/Partial Mode
	LCD_Write_DATA(0x00, 0x10);
	LCD_Write_DATA(0x00, 0x10);
	LCD_Write_DATA(0x00, 0x02);
	LCD_Write_DATA(0x00, 0x02);

	LCD_Write_COM(0xC0); //Panel Driving Setting / Set Default Gamma
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x35);
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x01);
	LCD_Write_DATA(0x00, 0x02);

	LCD_Write_COM(0xC5);  //Frame Rate Control / Set frame rate
	LCD_Write_DATA(0x00, 0x04);//72Hz

	LCD_Write_COM(0xD2); //Power_Setting for Normal Mode / power setting
	LCD_Write_DATA(0x00, 0x01);//Gamma Driver Amplifier:1.00, Source Driver Amplifier: 1.00
	LCD_Write_DATA(0x00, 0x44);

	LCD_Write_COM(0xC8); //Gamma Setting / Set Gamma
	LCD_Write_DATA(0x00, 0x04);
	LCD_Write_DATA(0x00, 0x67);
	LCD_Write_DATA(0x00, 0x35);
	LCD_Write_DATA(0x00, 0x04);
	LCD_Write_DATA(0x00, 0x08);
	LCD_Write_DATA(0x00, 0x06);
	LCD_Write_DATA(0x00, 0x24);
	LCD_Write_DATA(0x00, 0x01);
	LCD_Write_DATA(0x00, 0x37);
	LCD_Write_DATA(0x00, 0x40);
	LCD_Write_DATA(0x00, 0x03);
	LCD_Write_DATA(0x00, 0x10);
	LCD_Write_DATA(0x00, 0x08);
	LCD_Write_DATA(0x00, 0x80);
	LCD_Write_DATA(0x00, 0x00);

	LCD_Write_COM(0x2A); //set_column_address
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0xeF);

	LCD_Write_COM(0x2B); //set_page_address
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x00);
	LCD_Write_DATA(0x00, 0x01);
	LCD_Write_DATA(0x00, 0x8F);

	LCD_Write_COM(0x29); //set_display_on / display on

	LCD_Write_COM(0x2C); //write_memory_start / display on
	break;
