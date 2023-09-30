#define Pgreen 23
#define Pred 22
#define Pbuzzer 19
#define Pbutton 18

int TimerMin = 10;
int state = 0;
int oldstate = 0;
bool pressed = false;
bool timing = false;
int ende;


void setup() {
  pinMode(Pgreen, OUTPUT);
  pinMode(Pred, OUTPUT);
  pinMode(Pbuzzer, OUTPUT);
  pinMode(Pbutton, INPUT_PULLUP);

  digitalWrite(Pbuzzer, LOW);

  Serial.begin(9600);
  delay(1000);
}

void loop() {
  if (!pressed)
  {
    if (digitalRead(Pbutton) == LOW)
    {
      oldstate = state;
      pressed = true;
      state += 1;
      state = state % 3;
      Serial.println(state);
    }
    
    if (state == 1)
    {
      digitalWrite(Pgreen, HIGH);
      digitalWrite(Pred, LOW);
      if (oldstate != state)
      {
        ende = millis() + TimerMin*60*1000;
        timing = true;
      }
      if (millis()>=ende and timing==true);
      {
        state = 4;
      }
    }
    if (state == 2)
    {
      digitalWrite(Pred, HIGH);
      digitalWrite(Pgreen, LOW);
    }
    if (state == 0)
    {
      digitalWrite(Pred, LOW);
      digitalWrite(Pgreen, LOW);
    }
  }

  if (pressed)
  {
    if (digitalRead(Pbutton) == HIGH)
    {
      pressed = false;
    }
  }

  if (state == 4)
  {
    digitalWrite(Pbuzzer, HIGH);
    if (digitalRead(Pbutton) == LOW)
    {
      timing = false;
      digitalWrite(Pbuzzer, LOW);
      state = 1;
    }
  }
}
