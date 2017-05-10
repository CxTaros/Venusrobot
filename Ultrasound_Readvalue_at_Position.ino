#include <Servo.h>
Servo USservo;
  int USservoPin = 11; 
const int pingPin = 9;
  
int ultrasound_value(){
   long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = duration / 58 ;
  return(cm);
  }

  void ultrasound_position(int x){
    USservo.attach(USservoPin);  
    USservo.write(x); //Angle 0-180 from R-L
    
    }
  
void setup() {
      Serial.begin(9600);
      ultrasound_position(180);
      delay(2000);
      Serial.println(ultrasound_value());
    }

void loop() { // put your main code here, to run repeatedly:
//  int i, b;
//  int a[5];
//  for (i=0; i<5; i++){ 
//     a[i] = ultrasound_value();
//    }
//    b = (a[0] + a[1] + a[2] + a[3] + a[4])/5;
//Serial.println(b); 
