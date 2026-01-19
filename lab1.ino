const int leds[] = {2, 3, 4, 5};
const int N = 4;

void setup() {
  for (int i = 0; i < N; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      digitalWrite(leds[j], LOW);
    }

    digitalWrite(leds[i], HIGH);

    Serial.print("Time ");
    Serial.print(millis());
    Serial.print(" ms: LED ");
    Serial.print(i + 1);
    Serial.println(" ON");

    delay(250);
  }
}
