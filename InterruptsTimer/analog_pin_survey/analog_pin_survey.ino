#define sensor_pin A1

bool flag;
int time_ms;

void setup() {
  Serial.begin(9600);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 3900;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  pinMode(sensor_pin, INPUT);
  sei();
}

ISR(time_msR1_COMPA_vect) {
  flag = true;
}

void loop() {
  if (flag) {
    int data = analogRead(A0);
    Serial.println(millis() - time_ms);
    time_ms = millis();
    flag = false;
  }
}
