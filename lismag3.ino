
#include <Servo.h>
#define trigPin 7
#define echoPin 6
Servo servo;
Servo servo2;
int sound = 250;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(8);
servo2.attach(9);
}
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 5) {
Serial.println("the distance is less than 5");
servo.write(0);
servo2.write(120);
delay(400);
servo.write(120);
servo2.write(0);
delay(400);
}
else{
servo.write(120);
servo2.write(0);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(200);
}
