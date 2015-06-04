#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <softTone.h>

#define PIN 3

int scale[8] = {262, 294, 330, 349, 392, 440, 494, 525};
int scale2[23] = {659, 659, 0, 659, 0, 523, 659, 0, 784, 0, 0, 0, 392, 0, 0, 0, 523, 0,0, 392, 0,0,330};
int scale3[26] = {530,494,461,494,530,530,530,494,494,494,530,592,592,530,494,461,494,530,530,530,494,494,530,494,461,723};

int main(int argc, char *argv[])
{
	int i;
	int menu = 0;
	int menu2 = 0;
	
	wiringPiSetup();
	softToneCreate(PIN);

	int trig = 23;
	int echo = 24;
	int start_time, end_time;

	if(wiringPiSetup() == -1)
		exit(1);

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

	printf("Select the Menu \n 1. Auto play mode \n 2. Self play mode");
	scanf("%d",&menu);

	if(menu == 1)
	{
		while(1)
		{
			printf("Select music \n 1. piano \n 2. super mairo \n 3. airplane \n");
			scanf("%d",&menu2);

		if(menu2 == 1)
		{
			int j;
			for(j=0; j<8; j++)
			{
			softToneWrite(PIN, scale[j]);
			delay(200);	
			}
		}

		if(menu2 == 2)
		{
			int k;
       	        	for(k=0; k<23; ++k)
   			{
	            	softToneWrite(PIN, scale2[k]);
                	delay(200);
        		}
		}
		if(menu2 == 3)
		{
			int l;
			for(l=0; l<26; l++)
			{	
			softToneWrite(PIN, scale3[l]);
			delay(500);
			}
		}
	}
	}
	if(menu == 2)
	{
	while(1)
	{
		float distance = 0;

		digitalWrite(trig, LOW);
		delay(200);

		digitalWrite(trig, HIGH);
		delayMicroseconds(10);

		digitalWrite(trig, LOW);

		while(digitalRead(echo) == 0);
		start_time = micros();

		while(digitalRead(echo) == 1);
		end_time = micros();

		distance = (end_time - start_time) / 29. / 2. ;

		if(distance < 5.0)
		{
			softToneWrite(PIN, scale[0]);
			delay(500);
		}
		else if(distance > 5.0 && distance < 10.0)
		{
			softToneWrite(PIN, scale[1]);
			delay(500);
		}
		else if(distance > 10.0 && distance < 15.0)
		{
                        softToneWrite(PIN, scale[2]);
			delay(500);
		}
		else if(distance > 15.0 && distance < 20.0)
		{
                        softToneWrite(PIN, scale[3]);
			delay(500);
		}
		else if(distance > 20.0 && distance < 25.0)
		{
                        softToneWrite(PIN, scale[4]);
			delay(500);
		}
		else if(distance > 25.0 && distance < 30.0)
		{
                        softToneWrite(PIN, scale[5]);
			delay(500);
		}
		else if(distance > 30.0 && distance < 35.0)
		{
                        softToneWrite(PIN, scale[6]);
			delay(500);
		}
		else if(distance > 35.0 && distance < 40.0)
		{
                        softToneWrite(PIN, scale[7]);
			delay(500);
		}
		printf("distance %.2f cm\n", distance);
	}

}
	return 0;
}
