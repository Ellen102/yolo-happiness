#include "Jeffrey.h"
#define ENABLE1 10  // Enable Pin  motor 1
#define CONTROL1_1 8  // Control pin 1  motor 1
#define CONTROL1_2 9  // Control pin 2  motor 1

#define ENABLE2 11  // Enable Pin  motor 2
#define CONTROL2_1 12  // Control pin 1  motor 2
#define CONTROL2_2 13  // Control pin 2  motor 2

#define TRIGER 7 // Triger Pin distance sensor
#define ECHO 6 // Echo Pin distance sensor

#define OPTIMALE_SNELHEID 250

int huidige_snelheid = 0;

/*
20/02/2016
@author: Ellen Vanhove & maarten & sietse
*/
void setup()
{
	//init serial
	//Serial.begin(9600);

	//init motors
	pinMode(ENABLE1, OUTPUT);
	pinMode(ENABLE2, OUTPUT);

	pinMode(CONTROL1_1, OUTPUT);
	pinMode(CONTROL1_2, OUTPUT);
	pinMode(CONTROL2_1, OUTPUT);
	pinMode(CONTROL2_2, OUTPUT);

	//init afstandsensor
	pinMode(TRIGER, OUTPUT);
	pinMode(ECHO, INPUT);

	//steeds hetzelfde random gedrag
	randomSeed(42);
	// random getal van 10 tot 19
	//randNumber = random(10, 20);
	//delay(1000); //wacht 1 second

}

void loop()
{
	long afstand = get_afstand();
	if ( afstand > 20 ) {
		vooruit();
		set_snelheid(OPTIMALE_SNELHEID);
	}
	else {
		stop();
	}
	
	

}

void stop() {
	analogWrite(ENABLE1, 0);
	analogWrite(ENABLE2, 0);
	huidige_snelheid = 0;
}

void vooruit() {
	digitalWrite(CONTROL1_1, HIGH);
	digitalWrite(CONTROL1_2, LOW);

	digitalWrite(CONTROL2_1, HIGH);
	digitalWrite(CONTROL2_2, LOW);
}

void achteruit() {
	//todo
}

void links() {
	//todo
}

void rechts() {
	//todo
}

// snelheid ligt tussen 0 (stop) en 255
void set_snelheid(int snelheid) {
	analogWrite(ENABLE1, snelheid);
	analogWrite(ENABLE2, snelheid);
	huidige_snelheid = snelheid;
}

void set_snelheid_linker_wiel(int snelheid) {
	//todo
}
void set_snelheid_rechter_wiel(int snelheid) {
	//todo
}

// return de afstand gemeten door de sensor in cm
long get_afstand() {
	long duration, distance;
	digitalWrite(TRIGER, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIGER, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIGER, LOW);
	duration = pulseIn(ECHO, HIGH);
	distance = (duration / 2) / 29.1;
	return distance;
}