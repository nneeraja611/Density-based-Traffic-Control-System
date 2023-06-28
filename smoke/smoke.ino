// Copy this code to Arduino Studio
//
// ScienceGully

int smokeA0=A0;
int buzzer =11;
float sensorValue;
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(smokeA0,INPUT);
   Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Gas sensor warming up!");
  delay(2000); // allow the MQ-6 to warm up
  noTone(buzzer);
  
}

void loop() {
  sensorValue=analogRead(smokeA0);
  Serial.println(sensorValue);
  if(sensorValue > 200)
  {
    Serial.print(" | Smoke detected!");
    tone(buzzer,1000,200);
  }
  else
  {
    Serial.print(" | Smoke  not detected!");
  
    noTone(buzzer);
   
  }
  delay(1000); // wait 2s for next reading
}
