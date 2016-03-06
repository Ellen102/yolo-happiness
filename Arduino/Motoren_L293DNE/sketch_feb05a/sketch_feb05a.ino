#define ENABLE1 10  // Enable Pin  motor 1
#define CONTROL1_1 8  // Control pin 1  motor 1
#define CONTROL1_2 9  // Control pin 2  motor 1

#define ENABLE2 11  // Enable Pin  motor 2
#define CONTROL2_1 12  // Control pin 1  motor 2
#define CONTROL2_2 13  // Control pin 2  motor 2
 
int speed = 255;
void setup() {
 
    pinMode(ENABLE1, OUTPUT);
    pinMode(ENABLE2, OUTPUT);
 
    pinMode(CONTROL1_1, OUTPUT);
    pinMode(CONTROL1_2, OUTPUT);
    pinMode(CONTROL2_1, OUTPUT);
    pinMode(CONTROL2_2, OUTPUT);
}
 
void loop() {
 
    analogWrite(ENABLE1, speed);  
    analogWrite(ENABLE2, speed);  
 
    digitalWrite(CONTROL1_1, LOW);
    digitalWrite(CONTROL1_2, HIGH);
    
    digitalWrite(CONTROL2_1, LOW);
    digitalWrite(CONTROL2_2, HIGH);
    
    delay(4000);
 
}
