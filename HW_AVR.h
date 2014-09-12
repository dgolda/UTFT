// *** Hardwarespecific functions ***
void UTFT::LCD_Writ_Bus(char VH,char VL, byte mode)
{   
	switch (mode)
	{
	case 1:
		if (display_serial_mode==SERIAL_4PIN)
		{
		if (VH==1)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		}
		else
		{
		if (VH==1)
			sbi(P_RS, B_RS);
		else
			cbi(P_RS, B_RS);
		}

		if (VL & 0x80)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x40)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x20)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x10)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x08)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x04)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x02)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		if (VL & 0x01)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
		pulse_low(P_SCL, B_SCL);
		break;
	case 8:
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		PORTA = VH;
		pulse_low(P_WR, B_WR);
		PORTA = VL;
		pulse_low(P_WR, B_WR);
#else
		PORTD = VH;
		pulse_low(P_WR, B_WR);
		PORTD = VL;
		pulse_low(P_WR, B_WR);
#endif
		break;
	case 16:
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		PORTA = VH;
		PORTC = VL;
#else
		PORTD = VH;
		cport(PORTC, 0xFC);
		sport(PORTC, (VL>>6) & 0x03);
		PORTB =  VL & 0x3F;
#endif
		pulse_low(P_WR, B_WR);
		break;
	}
}

void UTFT::_set_direction_registers(byte mode)
{
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	DDRA = 0xFF;
	if (mode==16)
		DDRC = 0xFF;
#else
	DDRD = 0xFF;
	if (mode==16)
	{
		DDRB |= 0x3F;
		DDRC |= 0x03;
	}
#endif

}
