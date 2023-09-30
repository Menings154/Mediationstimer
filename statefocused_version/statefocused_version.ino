#define Pgreen 23
#define Pred 22
#define Pbuzzer 19
#define Pbutton 18

int TimerMin = 1;
int state = 0;
int ende;
int remaining;
bool continue_flag = false;
int stoppingtime = 0;
bool pressed = false;

// first the functions which take care that the system is in the correct physical state corresponmding to the programming state.
int to_state0() {
  digitalWrite(Pgreen, LOW);
  digitalWrite(Pred, LOW);
  digitalWrite(Pbuzzer, LOW);
  return 0;
}
int to_state1() { // wie mache ich das mit timer?
  digitalWrite(Pgreen, HIGH);
  digitalWrite(Pred, LOW);
  digitalWrite(Pbuzzer, LOW);
  if (!continue_flag) {
    ende = millis() + TimerMin * 60 * 1000;
  }
  else {
    ende += millis() - stoppingtime;
  }
  return 1;
}
int to_state2() { // wie mache ich das mit timer?
  digitalWrite(Pgreen, LOW);
  digitalWrite(Pred, HIGH);
  digitalWrite(Pbuzzer, LOW);
  stoppingtime = millis();
  continue_flag = true;
  return 2;
}
int to_state3() { // wie mache ich das mit timer?
  digitalWrite(Pgreen, HIGH);
  digitalWrite(Pred, HIGH);
  digitalWrite(Pbuzzer, HIGH);
  return 3;
}

void setup() {
  pinMode(Pgreen, OUTPUT);
  pinMode(Pred, OUTPUT);
  pinMode(Pbuzzer, OUTPUT);
  pinMode(Pbutton, INPUT_PULLUP);
  state = to_state0();
}

void loop() {
  pressed = digitalRead(Pbutton);
  if (state == 0 and digitalRead(Pbutton) == LOW and !pressed) {
    state = to_state1();
  }
  else if (state == 1 and digitalRead(Pbutton) == LOW and !pressed) {
    state = to_state2();
  }
  else if (state == 2 and digitalRead(Pbutton) == LOW and !pressed) {
    state = to_state1();
  }
  else if (state == 3 and digitalRead(Pbutton) == LOW) {
    state = to_state0();
  }

  if (state == 1) {
    remaining = ende - millis();
  }
  if (state == 1 and remaining <= 0) {
    state = to_state3();
  }
}
