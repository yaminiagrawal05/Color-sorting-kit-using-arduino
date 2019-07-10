#include <Servo.h>
#define S0 9
#define S1 10
#define S2 11
#define S3 12
#define sensorOut 8
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(5);
  bottomServo.attach(7);
  Serial.begin(9600);
}

void loop() {
  bottomServo.write(90);
  topServo.write(180);
  delay(500);
  
  for(int i = 180; i > 70; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(10000);

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
  if(R>17 & R<50 & G>30 & G<55 & B>30 &B<40){    ///This value should be change according to your reding please check serial monitor to know your reading.
    bottomServo.write(30); // Red 
    }

  else if(R>25 & R<40 & G>35 & G<53 & B>25 &B<45){
    bottomServo.write(105); // Green
  }
//  if(R>15 & R<18 & G>18 & G<25 & B>15 &B<35){
//    color = 3; // Yellow
//  }

  else if(R>30 & R<45 & G>30 & G<50 & B>20 &B<40){
    bottomServo.write(140); // Blue
  }


  delay(300);
  
  for(int i = 70; i >45;i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(400);
//  
  for(int i = 45;i< 180; i++) {
    topServo.write(i);
    delay(2);
  }
}
