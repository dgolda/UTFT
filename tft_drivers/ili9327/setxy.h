case ILI9327:
	  LCD_Write_COM(0x2a);//Set_column_address
  	LCD_Write_DATA(0x00, x1>>8);
  	LCD_Write_DATA(0x00, x1);
  	LCD_Write_DATA(0x00, x2>>8);
  	LCD_Write_DATA(0x00, x2);
  	LCD_Write_COM(0x2b);//Set_page_address
  	LCD_Write_DATA(0x00, y1>>8);
  	LCD_Write_DATA(0x00, y1);
  	LCD_Write_DATA(0x00, y2>>8);
  	LCD_Write_DATA(0x00, y2);
  	LCD_Write_COM(0x2c); //Write_memory_start
	break;
