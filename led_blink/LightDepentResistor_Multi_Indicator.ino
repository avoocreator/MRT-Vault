int photo_resistor = A0;
int batas_1 = 500;
int batas_2 = 150;
int nilai_sensor;
int LED_merah = 1;
int LED_kuning = 2;
int LED_hijau = 3;
void setup() {
  // put your setup code here, to run once:
pinMode(LED_merah, OUTPUT);
pinMode(LED_kuning, OUTPUT);
pinMode(LED_hijau, OUTPUT);
Serial.begin(9600);
}

void loop() {
nilai_sensor = analogRead(photo_resistor);
Serial.print("Data sensor : ");
Serial.println(nilai_sensor);

if (nilai_sensor > batas_1) {
  digitalWrite(LED_merah, 1);
  digitalWrite(LED_kuning, 0);
  digitalWrite(LED_hijau, 0);
} else if (nilai_sensor <= batas_1 && nilai_sensor >= batas_2) {
  digitalWrite(LED_merah, 0);
  digitalWrite(LED_kuning, 1);
  digitalWrite(LED_hijau, 0);
} else {
  digitalWrite(LED_merah, 0);
  digitalWrite(LED_kuning, 0);
  digitalWrite(LED_hijau, 1);
}
delay(500);
}
