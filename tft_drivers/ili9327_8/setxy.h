case ILI9327_8:
	LCD_Write_COM(0x2a);//Set_column_address
  	LCD_Write_DATA(x1>>8);
  	LCD_Write_DATA(x1);
  	LCD_Write_DATA(x2>>8);
  	LCD_Write_DATA(x2);
  	LCD_Write_COM(0x2b);//Set_page_address
  	LCD_Write_DATA(y1>>8);
  	LCD_Write_DATA(y1);
  	LCD_Write_DATA(y2>>8);
  	LCD_Write_DATA(y2);
  	LCD_Write_COM(0x2c); //Write_memory_start
	break;
