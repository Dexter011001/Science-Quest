const int Ir_Sensor_1 = 2;
const int Ir_Sensor_2 = 3;
int SensorOneValue;
int InvertedSensorOneValue;
int InvertedSensorTwoValue;
int SensorTwoValue;
int Total;

void setup() {
  Serial.begin(9600);
  pinMode(Ir_Sensor_1, INPUT);
  pinMode(Ir_Sensor_2,INPUT);
  
}

void loop() {
   SensorOneValue = !digitalRead(Ir_Sensor_1);
   SensorTwoValue = !digitalRead(Ir_Sensor_2);
   
   Total = SensorOneValue + SensorTwoValue;
  
  Serial.println("Total number of cars: ");Serial.println(Total);

  delay(100);
  

}
