const byte leds[4] = {2, 3, 4, 5};

byte mode = 0;  // 0..3
unsigned long tMode = 0;
unsigned long tStep = 0;

byte stepIndex = 0;
bool state = false;

void setup() {
  for (byte i = 0; i < 4; i++) pinMode(leds[i], OUTPUT);
  allOff();
}

void loop() {
  unsigned long now = millis();

  if (now - tMode >= 3000) {
    tMode = now;
    mode = (mode + 1) % 4;
    stepIndex = 0;
    state = false;
    allOff();
  }

  if (now - tStep >= 300) {
    tStep = now;

    switch (mode) {
      case 0: runningLight(); break;
      case 1: allBlink(); break;
      case 2: pairsBlink(); break;
      case 3: checkerBlink(); break;
    }
  }
}

void allOff() {
  for (byte i = 0; i < 4; i++) digitalWrite(leds[i], LOW);
}

void runningLight() {
  allOff();
  digitalWrite(leds[stepIndex], HIGH);
  stepIndex = (stepIndex + 1) % 4;
}

void allBlink() {
  state = !state;
  for (byte i = 0; i < 4; i++) digitalWrite(leds[i], state);
}

void pairsBlink() {
  state = !state;
  digitalWrite(leds[0], state);
  digitalWrite(leds[2], state);
  digitalWrite(leds[1], !state);
  digitalWrite(leds[3], !state);
}

void checkerBlink() {
  state = !state;
  digitalWrite(leds[0], state);
  digitalWrite(leds[3], state);
  digitalWrite(leds[1], !state);
  digitalWrite(leds[2], !state);
}
