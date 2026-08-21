int photo_resistor = A0;
int batas = 500;
int nilai_sensor;
int LED = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
nilai_sensor = analogRead(photo_resistor);
Serial.print("Data sensor : ");
Serial.println(nilai_sensor);

if (nilai_sensor > batas) {
  digitalWRite(LED, 0); // 0 = LOW
} else {
  digitalWrite(LED, 1); // 1 = HIGH
}
delay(500);
}
