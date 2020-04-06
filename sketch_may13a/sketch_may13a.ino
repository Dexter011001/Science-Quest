/*
 * 14/05/19                                                                                                                                                                                          
 * Parking Sensor Code for Arduino
 * Author: Ramful Devesh and Harsh Coolal
 * 
 */

#include <Servo.h>
Servo myservo;

//Sensor variables
const int IR_Sensor_1 = 2;
const int IR_Sensor_2 = 3;
const int IR_Sensor_3 = 4;
const int IR_Sensor_4 = 1;

//One-bit display Variables
const int E = 13;
const int D = 12;
const int C = 11;
const int DP = 10;
const int B = 9;
const int A = 8;
const int F = 7;
const int G = 6;

//Variables used
int SensorOneValue;
int SensorTwoValue;
int SensorThreeValue;
int Total;
int key_1;
int angle;
int SensorValue;

void setup() {
  //Setting up pins for display
   pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
    
  // put your setup code here, to run once:
   Serial.begin(9600);
   //setting up pins for sensor
   
   pinMode(IR_Sensor_1,INPUT);
   pinMode(IR_Sensor_2,INPUT);
   pinMode(IR_Sensor_3,INPUT);
   pinMode(IR_Sensor_4,INPUT);

   //Setting up servo
   myservo.attach(5);
   myservo.write(angle);
   
}

void zero(){
  //Displaying '0'
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  
  }

void one()
{
  //Displaying '1'
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void two(){
  //Displaying '2'
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  }
void three(){
  
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  
  }


//Code that runs in loop
void loop() {
  //Code for controlling Servo
  
  if(digitalRead(IR_Sensor_1)==LOW){
    myservo.write(90);
    delay(5000);
  }
   else if(digitalRead(IR_Sensor_1) == HIGH){
    myservo.write(-90);
    delay(1000);
   }

   //Reading Sensor values from parking
   SensorOneValue = digitalRead(IR_Sensor_2);
   SensorTwoValue = digitalRead(IR_Sensor_3);
   SensorThreeValue = digitalRead(IR_Sensor_4);

   //Checking number of parking available and displaying them
   Total = SensorOneValue + SensorTwoValue + SensorThreeValue;
   if(Total==0){
      zero();    
    }else if(Total==1){
        one();
      }else if(Total==2){
          two();
        }else if(Total==3){
          three();
          }

  Serial.println("Total parking available: ");Serial.println(Total);
  delay(100);
 }


 
