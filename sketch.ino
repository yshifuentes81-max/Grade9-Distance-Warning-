#define TRIGPIN 3
#define ECHOPIN 2
#define LEDPIN 8

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  long duration = pulseIn(ECHOPIN, HIGH, 30000);

  if (duration == 0) {
    digitalWrite(LEDPIN, LOW);
    Serial.println("No echo detected");
    delay(500);
    return;
  }

  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // TASK 1: Change the warning distance to 30 cm
  if (distance < 20) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  delay(500);
}
