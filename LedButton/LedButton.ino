#define led_pin 8
#define btn_pin A3

int curr, prev;
bool turn_on = false;
bool next = false;
int brightness = 255;
int delay_ms = 300;

void setup(){
  pinMode(led_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  Serial.begin(9600);
}

void loop(){
  curr = digitalRead(btn_pin);

  if (curr != prev){
    delay(10);

    curr = digitalRead(btn_pin);
    long time_ms = millis();

    while (digitalRead(btn_pin)){
      if (millis() - time_ms >= delay_ms && turn_on){
        while (digitalRead(btn_pin)){
          if (next){
            brightness = min(brightness + 1, 255);
          }
          else{
            brightness = max(brightness - 1, 20);
          }

          analogWrite(led_pin, brightness);
          delay(10);
        }

        next = !next;
      }

      delay(10);
    }
    
    if (millis() - time_ms < delay_ms){
      if (curr){
          turn_on = !turn_on;
      }
      if (turn_on){
        analogWrite(led_pin, brightness);
      }      
      else{
        analogWrite(led_pin, 0);
      }
    }
  }
  
  prev = curr;
}
