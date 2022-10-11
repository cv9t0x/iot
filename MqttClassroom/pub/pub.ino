#define btn 4

void setup() {
  pinMode(btn, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  boolean buttonDown = digitalRead(btn);
  Serial.print(buttonDown);
  delay(100);
}
