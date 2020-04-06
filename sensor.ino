#include <Servo.h>
Servo myservo;
const int IR_Sensor_1 = 11;

void setup() {
  
  // put your setup code here, to run once:
   pinMode(IR_Sensor_1,INPUT);
}

void loop() {

  if(digitalRead(IR_Sensor_1)==HIGH){
    myservo.attach(12);
    myservo.write(90);
  }else{
    delay(1000);
  }
  // put your main code here, to run repeatedly:

}
