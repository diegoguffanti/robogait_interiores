
int16_t raw_a[3], raw_w[3], raw_ang[3], raw_h[3], raw_q[4];
float a[3], w[3], theta_imu[3], h[3], q[4];
unsigned char rx_buf[11];

void parse_data(unsigned char byte)
{
	static unsigned char data_buffer[64];
	static unsigned char index = 0;

	data_buffer[index++] = byte;
	if (data_buffer[0] != 0x55)
	{ //Lectura erronea
		index = 0;
		return;
	}

	if (index < 11) { return; }
	else
	{
		switch (data_buffer[1])
		{
		case 0x50:	break; //Time
		case 0x51:	memcpy(raw_a, data_buffer + 2, 6); break; //Acelerometro
		case 0x52:	memcpy(raw_w, data_buffer + 2, 6); break; //Giroscopio
		case 0x53:	memcpy(raw_ang, data_buffer + 2, 6); break; //Angulos inclinacion
		case 0x54:	memcpy(raw_h, data_buffer + 2, 6); break; //Magnetometro
		case 0x55:	break; //Status
		case 0x56:	break; //Presion y altitud (no disponible en este modelo)
		case 0x57:	break; //GPS (no disponible en este modelo)
		case 0x58:	break; //GPSV (no disponible en este modelo)
		case 0x59:	memcpy(raw_q, data_buffer + 2, 8); break; //Cuaternio orientacion
		}
		index = 0;
	}
}

void calculate()
{
	for (int i = 0; i < 3; i++) a[i] = (float)raw_a[i] / 32768 * 16; //Aceleracion lineal en g
	for (int i = 0; i < 3; i++) w[i] = (float)raw_w[i] / 32768 * 2000; //Velocidad angular en �/s
	for (int i = 0; i < 3; i++) theta_imu[i] = (float)raw_ang[i] / 32768 * 180; //Angulo inclinacion en �
	for (int i = 0; i < 3; i++) h[i] = (float)raw_h[i]; //Magnetometro en uT
	for (int i = 0; i < 4; i++) q[i] = (float)raw_q[i] / 32768; //Cuaternio de orientacion
}



