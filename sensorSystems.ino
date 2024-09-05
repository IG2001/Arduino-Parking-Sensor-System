//Inderpreet Gill 

//Pins and Variables are declared/defined here
int gLed = 5;
int yLed = 6;
int rLed = 7;

int rLed2 = 22;
int yLed2 = 24;
int gLed2 = 26;

int btn = 2;
int btn2 = 1;

int piezo = 8;
int piezo2 = 4;

int echoPin = 13;
int trigPin = 12;

int echoPin2 = 23;
int trigPin2 = 25;

int counter = 0;
int counter2 = 0;

long duration;
double distance;

long duration2;
double distance2;

void setup() 
{
  //Pin functions are defined here
  pinMode(rLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(gLed, OUTPUT);

  pinMode(rLed2, OUTPUT);
  pinMode(yLed2, OUTPUT);
  pinMode(gLed2, OUTPUT);

  pinMode(btn, INPUT);
  pinMode(btn2, INPUT);

  pinMode(piezo, OUTPUT);
  pinMode(piezo2, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //First System
  if(digitalRead(btn) == LOW) //If the button is pressed, then the counter variable increases by 1 for every 200ms it remains pressed
  {
    counter ++;
    delay(200);
  }
  if(counter % 2) //If the counter is an odd number, then the system will turn off
  {
    digitalWrite(gLed, LOW);
    digitalWrite(yLed, LOW);
    digitalWrite(rLed, LOW);
    analogWrite(piezo, 0);
  }
  else //If the counter is an even number, then the system will turn on
  {
    //This sends out a wave that the sensor reads when it bounces back from an object
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); //This defines duration as how long it look to read the bounce-back of the emitted wave
    distance = (duration / 2) / 29.1; //This formula uses duration to find the how far the object is from the system in cm

    if(distance > 20) //If an object is farther than 20 cm, the first green LED will be on
    {
      digitalWrite(rLed, LOW);
      digitalWrite(yLed, LOW);
      digitalWrite(gLed, HIGH);
      analogWrite(piezo, 0);
    }
    else if(distance > 10 && distance <= 20) //If an object is between 10 cm and 20 cm, the first yellow LED will be on
    {
      digitalWrite(rLed, LOW);
      digitalWrite(yLed, HIGH);
      digitalWrite(gLed, LOW);
      analogWrite(piezo, 0);
    }
    else if(distance <= 10) //If an object is 10 cm or closer, then the first piezo and red LED will be on
    {
      digitalWrite(rLed, HIGH);
      digitalWrite(yLed, LOW);
      digitalWrite(gLed, LOW);
      analogWrite(piezo, 128);
    }
    delay(100); //100ms delay to refresh the ultrasonic sensor
  }

  //Second System
  if(digitalRead(btn2) == LOW) //For every 200ms the second button remains pressed, counter2 will increase by 1
  {
    counter2 ++;
    delay(200);
  }
  if(counter2 % 2) //If counter 2 is an odd number, then the system will be off
  {
    digitalWrite(rLed2, LOW);
    digitalWrite(yLed2, LOW);
    digitalWrite(gLed2, LOW);
    analogWrite(piezo2, 0);
  }
  else //If counter 2 is an even number, then the system will be on
  {
    //This sends out a wave that the sensor reads when it bounces back from an object
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH); //This defines duration as how long it look to read the bounce-back of the emitted wave
    distance2 = (duration2 / 2) / 29.1; //This formula uses duration to find the how far the object is from the system in cm

    if(distance2 > 20) //If an object is farther than 20 cm, the first green LED will be on
    {
      digitalWrite(rLed2, LOW);
      digitalWrite(yLed2, LOW);
      digitalWrite(gLed2, HIGH);
      analogWrite(piezo2, 0);
    }
    else if(distance2 > 10 && distance2 <=20) //If an object is between 10 cm and 20 cm, the first yellow LED will be on
    {
      digitalWrite(rLed2, LOW);
      digitalWrite(yLed2, HIGH);
      digitalWrite(gLed2, LOW);
      analogWrite(piezo2, 0);
    }
    else if(distance2 <= 10) //If an object is 10 cm or closer, then the first piezo and red LED will be on
    {
      digitalWrite(rLed2, HIGH);
      digitalWrite(yLed2, LOW);
      digitalWrite(gLed2, LOW);
      analogWrite(piezo2, 128);
    }
    delay(100); //100ms delay to refresh the ultrasonic sensor
  }
  

}
