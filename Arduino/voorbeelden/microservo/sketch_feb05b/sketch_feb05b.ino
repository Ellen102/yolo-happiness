#define SERVOPIN 5
#define MIN 13
#define MAX 25

void setup() {
  pinMode(SERVOPIN, OUTPUT);
}

void loop() {
  

       analogWrite(SERVOPIN, 126);  
         delay(20000);


}
