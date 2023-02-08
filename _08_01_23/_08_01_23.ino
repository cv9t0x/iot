#define pin_1 5
#define pin_2 6
#define pin_3 3
#define pin_4 9
#define pin_5 10
#define pin_6 11


void turnOnLedMatrix(uint8_t val_1, uint8_t val_2, uint8_t val_3, uint8_t val_4, uint8_t val_5, uint8_t val_6) {
  digitalWrite(pin_1, val_1);
  digitalWrite(pin_2, val_2);
  digitalWrite(pin_3, val_3);
  digitalWrite(pin_4, val_4);
  digitalWrite(pin_5, val_5);
  digitalWrite(pin_6, val_6);
}

void setup() {
  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, OUTPUT);
  pinMode(pin_5, OUTPUT);
  pinMode(pin_6, OUTPUT);
}

void loop() {
  // 1
  turnOnLedMatrix(1, 0,	0, 1, 1, 1);
  delay(250);

  // 2
  turnOnLedMatrix(1, 0, 1, 0, 1, 1);
  delay(250);

  // 3
  turnOnLedMatrix(0, 1, 0, 1, 1, 1);
  delay(250);

  // 4
  turnOnLedMatrix(0, 1, 1, 0, 1, 1);
  delay(250);

  // 5
  turnOnLedMatrix(1, 0, 1, 1, 0, 1);
  delay(250);
  
  // 6
  turnOnLedMatrix(1, 0, 1, 1, 1, 0);
  delay(250);

  // 7
  turnOnLedMatrix(0, 1, 1, 1, 0, 1);
  delay(250);

  // 8
  turnOnLedMatrix(0, 1, 1, 1, 1, 0);
  delay(250);

  // 1, 2
  turnOnLedMatrix(1, 0, 0, 0, 1, 1);
  delay(250);

  // 1, 3
  turnOnLedMatrix(1, 1, 0, 1, 1, 1);
  delay(250);

  // 1, 4
  int time = millis();
  while (millis() < time + 250) {
    turnOnLedMatrix(1, 0,	0, 1, 1, 1);
    delay(1);
    turnOnLedMatrix(0, 1, 1, 0, 1, 1);
    delay(1);
  }

  // 1, 5
  turnOnLedMatrix(1, 0, 0, 1, 0, 1);
  delay(250);

  // 1, 6
  turnOnLedMatrix(1, 0, 0, 1, 1, 0);
  delay(250);

  // // 1, 7
  // turnOnLedMatrix(1, 0,	0, 1, 1, 1);
  // delay(10);
  // turnOnLedMatrix(0, 1, 1, 1, 0, 1);
  // delay(10);
}
