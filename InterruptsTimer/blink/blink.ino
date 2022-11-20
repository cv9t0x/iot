#define led_pin 8

bool curr, prev;

void setup(){
  Serial.begin(9600);
  cli();
  TCCR2A = 0;
  TCCR2B = 0;
  TCCR2B |= (1 << CS10);
  TCCR2B |= (1 << CS12);
  TIMSK2 = (1 << TOIE1);
  pinMode(led_pin, OUTPUT);
  sei();
}

ISR(TIMER2_OVF_vect){
  curr = !curr;
}

void loop(){
  digitalWrite(led_pin, curr);
  if (curr != prev){
    Serial.println(millis());
    prev = curr;
  }
}
