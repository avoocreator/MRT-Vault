int leds[] = {2, 3, 4}; //isi array sesuai pin yang digunakan

void setup() {
  for (int i = 0;i < 3; i++) { //ganti "3" menjadi jumlah led (jumlah - 1)
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      digitalWrite(leds[j], LOW);
    }
    digitalWrite(leds[i], HIGH);
    delay(500);
  }
}
