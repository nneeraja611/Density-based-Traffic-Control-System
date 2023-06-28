#include <LiquidCrystal.h>
int smokeA0=A0;
int buzzer =2;
float sensorValue;
int obstaclePin = 6;
int hasObstacle = LOW;
int DELAY_GREEN = 10000;
int DELAY_YELLOW = 2000;
int DELAY_RED = 5000;
int YELLOW = 3;
int GREEN=4;
int RED= 5;
int count=0;
 const int rs = 12, en = 11, d4 = 8, d5 = 9, d6 = 10, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//void setup() {
//int smokeA0=A0;
//int buzzer =11;
//float sensorValue;
void setup() {
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(smokeA0,INPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600); // sets the serial port to 9600
  //Serial.println("Gas sensor warming up!");
  lcd.begin(16, 2);
  delay(2000); // allow the MQ-6 to warm up
  lcd.print("Let's get started!!!");
  noTone(buzzer);

}
void loop(){
  //int sensorValue = analogRead(A1);
  rain();
  smoke();
  ir();
}

void rain(){
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
   if (sensorValue<500) {
    Serial.println("wet!");
    lcd.print("Cyclists can move!!");
   }
   else{
    
    Serial.println("dry!");
      lcd.print("no rainm");
   }
//Serial.println(sensorValue);
delay(300);        // delay in between reads for stability
}

void smoke(){
  sensorValue=analogRead(smokeA0);
  Serial.println(sensorValue);
  if(sensorValue > 200)
  {
    Serial.print(" | Smoke detected!");
    lcd.print("Smoke");
       tone(buzzer,1000,200);
      
  }
  else
  {  noTone(buzzer);
    
   
    Serial.print(" | Smoke  not detected!");

   
  }
  delay(1000); // wait 2s for next reading
}
void ir(){
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == HIGH ) {
 // Serial.println("Path is clear!!")
digitalWrite(GREEN,LOW);
digitalWrite(YELLOW,LOW);
digitalWrite(RED,HIGH);
  }
  else {
     count++;
    Serial.println("Stop something is ahead!!");
      //Serial.println(count);
    if(count>3)
    {
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN, HIGH);
      delay(DELAY_GREEN);

    
      
         digitalWrite(GREEN, LOW);
         digitalWrite(RED,LOW);
          digitalWrite(YELLOW, HIGH);
         delay(DELAY_YELLOW);
          count=0;
         // loop();
//         digitalWrite(GREEN,LOW);
//digitalWrite(YELLOW,LOW);
//digitalWrite(RED,HIGH);
}
    //ir2(count);
    }
  delay(200);
}
/*void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}*/
