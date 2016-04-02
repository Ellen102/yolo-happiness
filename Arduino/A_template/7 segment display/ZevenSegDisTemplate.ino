
//todo vul de juiste waarden in die overeenkomen met de pin
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DOT 9

/*7 segmenten display*/
void setup()
{

  /* configureer de pinnen*/
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(DOT, OUTPUT);
}

void loop()
{

  /* add main program code here */
	alles_aan();
	delay(3 * 1000);//wacht 3 seconden
	uit();
	delay(3 * 1000);//wacht 3 seconden

}
void nul() {
	//todo
}

void een() {
	//todo
}

void twee() {
	//todo
}

void drie() {
	//todo
}

void vier() {
	//todo
}

void vijf() {
	//todo
}

void zes() {
	//todo
}

void zeven() {
	//todo
}

void acht() {
	//todo
}

void negen() {
	//Todo
}

void alles_aan() {
	digitalWrite(A, 1);
	digitalWrite(B, 1);
	digitalWrite(C, 1);
	digitalWrite(D, 1);
	digitalWrite(E, 1);
	digitalWrite(F, 1);
	digitalWrite(G, 1);
	digitalWrite(DOT, 1);
}
//zet all segmenten uit
void uit() {
	digitalWrite(A, 0);
	digitalWrite(B, 0);
	digitalWrite(C, 0);
	digitalWrite(D, 0);
	digitalWrite(E, 0);
	digitalWrite(F, 0);
	digitalWrite(G, 0);
	digitalWrite(DOT, 0);
}
