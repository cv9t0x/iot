#define led 9

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0) {
    char msg = Serial.read();
    delay(10);
    if(msg == '1') {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
}
