#define led_pin_1 8
#define led_pin_2 9
#define led_pin_3 10

bool blink_1, blink_2, blink_3;
bool turn_on_led_pin_2, turn_on_led_pin_3;

void setup(){
  Serial.begin(9600);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 62500;
  TCCR1B = TCCR1B | (1 << WGM12);
  TCCR1B = TCCR1B | (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  pinMode(led_pin_1, OUTPUT);
  pinMode(led_pin_2, OUTPUT);
  pinMode(led_pin_3, OUTPUT);
  sei();
}

ISR(TIMER1_COMPA_vect){
  blink_1 = !blink_1;
  blink_2 = turn_on_led_pin_2 ? !blink_2 : false;
  blink_3 = turn_on_led_pin_3 ? !blink_3 : false;
}

void loop(){
  digitalWrite(led_pin_1, blink_1);
  digitalWrite(led_pin_2, blink_2);
  digitalWrite(led_pin_3, blink_3);
  if (Serial.available() >= 1){
    int data = Serial.read();
    if (data == '2'){
      turn_on_led_pin_2 = !turn_on_led_pin_2;
    }
    if (data == '3'){
      turn_on_led_pin_3 = !turn_on_led_pin_3;
    }
  }
}
