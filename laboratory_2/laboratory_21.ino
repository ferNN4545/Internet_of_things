const int green = 13;
const int yellow = 12;
const int red = 11;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);

  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);

  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);

  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);

  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);

  
}
