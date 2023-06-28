int LEDpin = 13;
int obstaclePin = 10;
int hasObstacle = LOW;  // LOW MEANS NO OBSTACLE

void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  hasObstacle = digitalRead(obstaclePin);

  if (hasObstacle == HIGH) {
    Serial.println("Path is clear!!");
    digitalWrite(LEDpin, HIGH);
  }
  else {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LEDpin, LOW);
  }
  delay(200);
}
