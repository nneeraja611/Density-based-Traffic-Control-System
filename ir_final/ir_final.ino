int obstaclePin = 10;
int obstaclePin1 =12;
int hasObstacle   // LOW MEANS NO OBSTACLE
int hasObstacle1
int DELAY_GREEN = 5000;
int DELAY_YELLOW = 3000;
int DELAY_RED = 5000;

int YELLOW = 3;
int GREEN=4;
int RED= 5;
int GREEN1=9;
int YELLOW1 = 8;
int RED1= 6;
int count;
int count1;
void setup() {
  
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);
  pinMode(obstaclePin1, INPUT);
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
}


void loop() {

if(ir1()>ir2()){
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN, HIGH);
      delay(DELAY_GREEN)
      digitalWrite(GREEN, LOW);
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW, HIGH);
      delay(DELAY_YELLOW);
      count=0;  
else{
      digitalWrite(RED1,LOW);
      digitalWrite(YELLOW1,LOW);
      digitalWrite(GREEN1, HIGH);
      delay(DELAY_GREEN);
      digitalWrite(GREEN1, LOW);
      digitalWrite(RED1,LOW);
      digitalWrite(YELLOW1, HIGH);
      delay(DELAY_YELLOW);
      count=0;
}
}
void ir1()
{
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == HIGH ) {
   // Serial.println("Path is clear!!");
  digitalWrite(GREEN,LOW);
  digitalWrite(YELLOW,LOW);
  digitalWrite(RED,HIGH);
  }
  else {
    count++;
    Serial.println("Stop something is ahead!!");
    delay(200);
    return count;
//    if(count>3)
//    {
//      digitalWrite(RED,LOW);
//      digitalWrite(YELLOW,LOW);
//      digitalWrite(GREEN, HIGH);
//      delay(DELAY_GREEN);
//
//    
//      
//          digitalWrite(GREEN, LOW);
//          digitalWrite(RED,LOW);
//          digitalWrite(YELLOW, HIGH);
//          delay(DELAY_YELLOW);
//          count=0;
//      
//    }
}
}
int ir2()
{
   hasObstacle1 = digitalRead(obstaclePin1);
   if (hasObstacle1 == HIGH ) {
   // Serial.println("Path is clear!!");
  digitalWrite(GREEN1,LOW);
  digitalWrite(YELLOW1,LOW);
  digitalWrite(RED1,HIGH);
  }
  else {
     count1++;
      //Serial.println(count1);
      Serial.println("Stop something is ahead!!");
      return count1;
//    if(count1>3)
//    {
//  
//  
//  0
//  void setup() {
//}
//  // put your setup code here, to run once:
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}
}
}
