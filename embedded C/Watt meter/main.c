/*
 * kinda final code for wattmeter.c
 *
 * Created: 11/27/2016 3:45:00 PM
 */
#define F_CPU 16000000UL
#define D0 eS_PORTC0
#define D1 eS_PORTC1
#define D2 eS_PORTC2
#define D3 eS_PORTC3
#define D4 eS_PORTC4         //lcd pins
#define D5 eS_PORTC5
#define D6 eS_PORTC6
#define D7 eS_PORTC7
#define RS eS_PORTD0
#define EN eS_PORTD1


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"     //lcd library file
int samples=5000;  //number of readings
int sampleV,last_sampleV;
int sampleI,last_sampleI;
float VSQ;
float ISQ;
float VIN;
float IIN;
float Vrms;
float Irms;
float last_filteredV,filteredV;
float last_filteredI,filteredI;
float realpower,POWER;

int getADC0(void){			// Process ADC0
	ADCSRA= (1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//ADEN enable ADC...ADSP '111' 128 prescale
	ADMUX= (0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0)|(1<<REFS0)|(0<<REFS1);  //set channel to read from.... set refrence to AVCC
	while (ADCSRA & (1<<ADSC));     //wait ADC conversion
	ADCSRA |= (1<<ADSC);  //set ADSC to 0 again
	return ADC;   //return the reading
}

int getADC1(void){		// Process ADC1
	ADCSRA= (1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//ADEN enable ADC...ADSP '111' 128 prescale
	ADMUX= (0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(1<<MUX0)|(1<<REFS0)|(0<<REFS1);
	while (ADCSRA & (1<<ADSC));     //wait ADC conversion
	ADCSRA |= (1<<ADSC);
	return ADC;
}

float volt(){
	for(int i=0;i<samples;i++){
		last_sampleV=sampleV;
		sampleV=getADC0();
		last_filteredV=filteredV;
		filteredV=0.996*(last_filteredV+sampleV-last_sampleV);	 //equation for a high pass filter to get rid of the dc offset
		VSQ += filteredV*filteredV;
	}
	Vrms=sqrt(VSQ/samples);
	VIN=Vrms*250/1024;		//to get the actual reading   50 from the voltage divider * 5 from the voltage refrence  / 1024 the 10 bits of adc
	VSQ=0;
	return VIN;
}
float current(){
	for(int i=0;i<samples;i++){

		last_sampleI=sampleI;
		sampleI=getADC1();
		last_filteredI=filteredI;
		filteredI=0.996*(last_filteredI+sampleI-last_sampleI);
		ISQ += filteredI*filteredI;
	}
	Irms=sqrt(ISQ/samples);
	IIN=Irms/1280;   //reading*5*2 /1024*2.5*5
	ISQ=0;
	return IIN;
}

float real_power(){
	for(int i=0;i<samples;i++){
					last_sampleV=sampleV;
					last_sampleI=sampleI;
					sampleV=getADC0();
					sampleI=getADC1();
					last_filteredV=filteredV;
					last_filteredI=filteredI;
					filteredV=0.996*(last_filteredV+sampleV-last_sampleV);
					filteredI=0.996*(last_filteredI+sampleI-last_sampleI);
					VIN=filteredV*250/1024;
					IIN=filteredI/1280;
    			realpower += VIN*IIN;
				}
	POWER=realpower/samples;
	realpower=0;
	return POWER;
}


int main(void){
	DDRA=0x00;   //ALL PORT A as input input
	DDRD = 0xFF;
  DDRC = 0xFF;
  Lcd8_Init();  //initialize the lcd
	Lcd8_Set_Cursor(1,1);
while (1){     //never ending loop
			volt();  //get rms volt
			current(); //get rms current
float	power=VIN*IIN; //get the apparent power  Irms*Vrms
							//real power = the average of the In*Vn
							//power factor = real power/apparent power
		real_power();
char bufferR[100];
char bufferP[100];
char bufferI[100];  //arrays to store the number as a string to write on the lcd
char bufferV[100];
		sprintf(bufferV,"%4.2fV",VIN);		//the function to convert the VOLTAGE from a number to a string and store it in the buffer/array
		sprintf(bufferI,"%4.2fA",IIN);		//4.2 to take only 2 decimal points  A or V or W it's written after the 2 decimal numbers
		sprintf(bufferP,"%4.2fVA",power);
		sprintf(bufferR,"%4.2fW",POWER);
			Lcd8_Set_Cursor(1,1);
			Lcd8_Write_String(bufferV); // write v
			Lcd8_Set_Cursor(1,10);
			Lcd8_Write_String(bufferI);  //write i
			Lcd8_Set_Cursor(2,1);
			Lcd8_Write_String(bufferP);
			Lcd8_Set_Cursor(2,9);
			Lcd8_Write_String(bufferR);				   //write power
		_delay_ms(300);   //useless delay
}}
