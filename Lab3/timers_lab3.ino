const byte LED_COUNT = 4;
const byte LED_PINS[LED_COUNT] = {2, 3, 5, 6};

const unsigned long PERIOD_MS = 20;

volatile byte duty[LED_COUNT] = {15, 35, 60, 85};

unsigned long t0 = 0;
byte phase = 0;
unsigned long nextStepMs;

unsigned long lastTraceMs = 0;
const unsigned long TRACE_EVERY_MS = 200;

void setup() {
  for (byte i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }

  Serial.begin(9600);
  while (!Serial) {}

  t0 = millis();
  nextStepMs = t0;

  Serial.println("Lab3 Timers (software PWM) started.");
  Serial.println("Pins: D2 D3 D5 D6");
  Serial.println("Trace: Serial Monitor (no logic analyzer in Tinkercad).");
}

void loop() {
  unsigned long now = millis();

  unsigned long stepMs = PERIOD_MS / 100;
  if (stepMs == 0) stepMs = 1;

  if ((long)(now - nextStepMs) >= 0) {
    for (byte i = 0; i < LED_COUNT; i++) {
      if (phase < duty[i]) digitalWrite(LED_PINS[i], HIGH);
      else digitalWrite(LED_PINS[i], LOW);
    }

    phase++;
    if (phase >= 100) phase = 0;

    nextStepMs += stepMs;
  }

  if (now - lastTraceMs >= TRACE_EVERY_MS) {
    lastTraceMs = now;

    Serial.print("t=");
    Serial.print(now);
    Serial.print("ms | duty: ");

    for (byte i = 0; i < LED_COUNT; i++) {
      Serial.print((int)duty[i]);
      Serial.print("%");
      if (i != LED_COUNT - 1) Serial.print(", ");
    }

    Serial.print(" | phase=");
    Serial.println((int)phase);
  }
}