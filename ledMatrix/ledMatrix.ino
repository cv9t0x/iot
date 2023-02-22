#define pin_1 5
#define pin_2 6
#define pin_3 3
#define pin_4 9
#define pin_5 10
#define pin_6 11

const int delay_ms = 250;
const int size = 6;

uint8_t leds_clear[size] = {1, 1, 0, 0, 0, 0};

int pins[size] = {pin_1, pin_2, pin_3, pin_4, pin_5, pin_6};

void turn_on_led_matrix(uint8_t vals[size], bool with_delay = true) {
  for (int i = 0; i < size; i += 1) {
    digitalWrite(pins[i], vals[i]);
  }

  if (with_delay) {
    delay(delay_ms);    
  }
}

void turn_on_led_matrix_switch(uint8_t vals_1[size], uint8_t vals_2[size]) {
  long time = millis();
  while (millis() < time + delay_ms) {
    turn_on_led_matrix(vals_1, false);
    turn_on_led_matrix(leds_clear, false);
    delay(5);
    turn_on_led_matrix(vals_2, false);
    turn_on_led_matrix(leds_clear, false);
    delay(5);
  }
}

uint8_t* get_leds(uint8_t val_1, uint8_t val_2, uint8_t val_3, uint8_t val_4, uint8_t val_5, uint8_t val_6) {
  uint8_t leds[size] = {val_1, val_2, val_3, val_4, val_5, val_6};
  return leds;
}

void setup() {
  for (int i = 0; i < size; i += 1) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // 1
  turn_on_led_matrix(get_leds(0, 1, 1, 0, 0, 0));

  // 2
  turn_on_led_matrix(get_leds(1, 0, 1, 0, 0, 0));

  // 3
  turn_on_led_matrix(get_leds(0, 1, 0, 1, 0, 0));

  // 4
  turn_on_led_matrix(get_leds(1, 0, 0, 1, 0, 0));

  // 5
  turn_on_led_matrix(get_leds(0, 1, 0, 0, 1, 0));

  // 6
  turn_on_led_matrix(get_leds(1, 0, 0, 0, 1, 0));

  // 7
  turn_on_led_matrix(get_leds(0, 1, 0, 0, 0, 1));

  // 8
  turn_on_led_matrix(get_leds(1, 0, 0, 0, 0, 1));

  // 1, 2
  turn_on_led_matrix(get_leds(0, 0, 1, 0, 0, 0));

  // 1, 3
  turn_on_led_matrix(get_leds(0, 1, 1, 1, 0, 0));

  // 1, 4
  turn_on_led_matrix_switch(get_leds(0, 1, 1, 0, 0, 0), get_leds(1, 0, 0, 1, 0, 0));

  // 1, 5
  turn_on_led_matrix(get_leds(0, 1, 1, 0, 1, 0));

  // 1, 6
  turn_on_led_matrix_switch(get_leds(0, 1, 1, 0, 0, 0), get_leds(1, 0, 0, 0, 1, 0));

  // 1, 7
  turn_on_led_matrix(get_leds(0, 1, 1, 0, 0, 1));

  // 1, 8
  turn_on_led_matrix_switch(get_leds(0, 1, 1, 0, 0, 0), get_leds(1, 0, 0, 0, 0, 1));

  // 1, 2, 4, 6, 8
  turn_on_led_matrix_switch(get_leds(0, 1, 1, 0, 0, 0), get_leds(1, 0, 1, 1, 1, 1));

  // 5, 6
  turn_on_led_matrix(get_leds(0, 0, 0, 0, 1, 0));

  // 7, 8
  turn_on_led_matrix(get_leds(0, 0, 0, 0, 0, 1));
}