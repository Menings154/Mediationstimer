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

// first the functions which take care that the system is in the correct physical state corresponmding to the programming state.
int to_state0(){
  digitalWrite(Pgreen, LOW);
  digitalWrite(Pred, LOW);
  digitalWrite(Pbuzzer, LOW);
  return 0;
}
int to_state1(){ // wie mache ich das mit timer?
  digitalWrite(Pgreen, HIGH);
  digitalWrite(Pred, LOW);
  digitalWrite(Pbuzzer, LOW);
  return 1;
}
int to_state2(){ // wie mache ich das mit timer?
  digitalWrite(Pgreen, LOW);
  digitalWrite(Pred, HIGH);
  digitalWrite(Pbuzzer, LOW);
  return 2;
}
int to_state3(){ // wie mache ich das mit timer?
  digitalWrite(Pgreen, HIGH);
  digitalWrite(Pred, HIGH);
  digitalWrite(Pbuzzer, HIGH);
  return 3;
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(Pgreen, OUTPUT);
  pinMode(Pred, OUTPUT);
  pinMode(Pbuzzer, OUTPUT);
  pinMode(Pbutton, INPUT_PULLUP);
  state = to_state0();
}

void loop() {


}
