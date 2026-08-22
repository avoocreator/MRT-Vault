# Light Emitting Diode
_Light Emitting Diode (LED)_ komponen elektronika kecil yang bisa memancarkan cahaya saat dialiri arus listrik.
LED sering dipakai sebagai indikator sebuah sensor. Pada adsarnya LED tidak hanya digunakan sebagai lampu, tetapi juga sebagai dioda.
### Diode
Dioda adalah komponen elektronika semikonduktor yang berfungsi sebagai "katup satu arah" bagi arus listrik.
Kalau diibaratkan seperti pipa air, dioda itu seperti klep satu arah: air (arus listrik) bisa mengalir ke satu arah dengan lancar, tapi kalau air mencoba mengalir ke arah sebaliknya, klepnya akan menutup rapat sehingga air tidak bisa lewat.

---

LED sering digunakan sebagai indikator (_output_) atau tes _blink_. Pada LED terdapat 2 pin, yakni pin panjang dan pendek. Pin panjang menandakan positif (+) dan pin pendek menandakan negatif (-). Di dalam LED juga terdapat sebuah besi kecil, yang bisa digunakan untuk mengidentifikasi positif dan negatif. Perhatikan gambar dibawah ini :

<img width="700" height="375" alt="image" src="https://github.com/user-attachments/assets/98d4bba4-8141-4a65-9f44-5b36524df7b5" />

### LED pada Arduino
Pada arduino, LED disambungkan ke pin digital (1 - 13) dan diinsialisasikan sebagai OUTPUT pada void setup. Untuk menyalakan LED kita menggunakan _syntax_ ```cpp digitalWrite``` dengan HIGH (1) untuk menyalakan dan LOW (0) untuk mematikan. Perhatikan kode dibawah ini ::
```cpp
void setup () {
  pinMode(1, OUTPUT); //menginisialisi LED yang digunakan
}

void loop () {
  digitalWrite(1, HIGH); //HIGH = LED menyala, bisa juga ditulis 1
  delay(500); //jeda antar syntax
  digitalWrite(1, LOW); //LOW = LED mati, bisa juga ditulis 0
  delay(500);
}
```

---

### Memvariasikan LED pada Arduino
Jika kita ingin menggunakan lebih dari 1 LED dan ingin memvariasikan hidup atau matinya, kita bisa mengcopy _syntax_ dengan memainkan delay. Tapi yang perlu di perhatikan, penulisan setiap bagian harus terdiri dari banyaknya LED dengan tetap memperhatikan delay antar bagian. Kita juga bisa menggunakan variabel sebagai permisalan untuk pin. Perhatikan kode berikut
```cpp
// Variabelkan pin sesuai kebutuhan (jangan lupa memakai integer)
int led_1 = 1;
int led_2 = 2;
int led_3 = 3;
void setup () {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
}

void loop () {
  // Syntax diulang sebanyak LED yang akan divariasikan
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  delay(500);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, LOW);
  delay(500);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(500);
}
```

---

### Penggunaan For dan Array pada Syntax
Jika kita menggunakana banyak LED, kode yang kita ahsilkan pasti akan panjang. Kita bisa memanfaatkan _syntax_ ```cpp for``` dan _array_ untuk memperpendek kode kita. Perhatikaan kode dibawah ini :
```cpp
int leds[] = {2, 3, 4}; //nilai dalam kurung kurva diisi dengan pin LED apa saja yang kita pakai

void setup() {
  for (int i = 0;i < 3; i++) { //perulangan (_loop_) untuk mengulang perintah di dalamnya sebanyak 3 kali
    pinMode(leds[i], OUTPUT); //untuk mengatur mode pin menggunakan variabel "i" secara berurutan
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) { //menggunakan variabel baru bernama j (dari 0 sampai 2) untuk menelusuri semua pin LED satu per satu.
      digitalWrite(leds[j], LOW);
    }
    digitalWrite(leds[i], HIGH);
    delay(500);
  }
}
```


