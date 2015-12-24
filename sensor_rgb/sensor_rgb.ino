#define trigPin 13
#define echoPin 12

#define greenPin 10
#define yellowPin 7
#define redPin 8


void turnOnGreen() {
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
}

void turnOnYellow() {
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, LOW);
}

void turnOnRed() {
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 50 || distance <= 0){
    Serial.println("Out of range");
    turnOnGreen();
  }
  else {
    if(distance < 12){
      turnOnRed();
    }else {
      turnOnYellow();
    }
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
