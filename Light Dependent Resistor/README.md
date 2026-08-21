# LIGHT DEPENDENT RESISTOR (LDR)
Secara sederhana, LDR adalah komponen elektronika jenis resistor (penghambat arus listrik) yang nilai hambatan (resistansi) nya dapat berubah-ubah tergantung pada intensitas cahaya yang mengenainya.

---

Pada simulasi ini, kita akan menggunakan LDR Module, yakni sebuah module sensor elektronika yang berfungsi untuk mendeteksi intensitas cahaya di lingkungan sekitar. Pada inventaris MRT, LDR Module yang tersedia memiliki 4 pin, yakni :
| Nama Pin | Jenis Pin | Deskripsi / Fungsi |
| :---: | :---: | :--- |
| **VCC** | Power (Input) | Sumber tegangan positif (biasanya dihubungkan ke 5V atau 3.3V pada mikrokontroler) |
| **GND** | Ground | Hubungkan ke ground (kutub negatif / 0V) sistem |
| **A0** | Analog Output | Mengeluarkan data tegangan analog yang nilainya berubah proporsional terhadap intensitas cahaya |
| **D0** | Digital Output | Mengeluarkan sinyal digital (HIGH/LOW) berdasarkan batas (*threshold*) yang diatur pada potensiometer |

---

### Pembacaan Sensor
Module sensor seperti LDR menggunakan pin Input, yakni sebuah pin yang berfungsi menghasilkan data yang nantinya akan dimasukkan ke dalam Arduino (_input_). Untuk pinnya sendiri menggunakan Analog Pin yakni A0. Kemudian kita menggunakan analogRead untuk membaca data yang terinput. KIta juga bisa menampilkan data sensor pada serial monitor menggunakan Serial.begin. Perhatikan kode dibawah :
```cpp
void setup {
  pinMode(A0, INPUT); //opsional, untuk A0 biasanya tidak perlu ditulis di setup
  Serial.begin(9600);
}
void loop {
  int value = analogRead(A0); //kita bisa ngevariabelkan data sensor menggunakan integer
  Serial.print("Nilai data: ");
  Serial.println(value); //Serial.println digunakan untuk mencetak keluaran yang akan sebaris keluaran sebelumnya
  delay(500); //Jangan lupa beri delay untuk mengatur kecepatan data dijalankan kembali ke smeula
}
```

---

### Output sebagai LED
Sebuah sensor jika diberi aksi akan menghasilkan sebuah data. Data tersebut tidak hanya bisa ditampilkan di serial monitor, melainkan bisa diimplementasikan ke sebuah **indikator** seperti LED. Untuk menggunakan LED sebagai output, kita perlu mengetahui konsep pin analog terlebih dahulu.

#### Pin Analog
Pin analog (sering juga disebut pin ADC atau _Analog-to-Digital Converter_) adalah jenis pin pada mikrokontroler (seperti Arduino) yang berfungsi untuk membaca sinyal tegangan kontinu yang nilainya bervariasi, bukan hanya sekadar kondisi biner tegas (HIGH atau LOW / nyala atau mati). Bisa kita visualkan dalam tabel sebagai berikut :
| Fitur | Pin Digital (D0-Dn) | Pin Analog (A0-An) |
| :--- | :--- | :--- |
| **Sifat Sinyal** | Diskrit (Terputus-putus) | Kontinu (Mengalir) |
| **Nilai yang Dibaca** | Biner (0 atau 1) | Rentang nilai (Contoh: 0 - 1023) |
| **Kondisi** | `HIGH` (ON/5V) atau `LOW` (OFF/0V) | Nilai variabel sesuai level tegangan |
| **Contoh Sensor** | Push button, PIR Motion, D0 LDR | LDR (AO), Potensiometer, Sensor Suhu |
| **Fungsi Utama** | Deteksi saklar atau pemicu sederhana | Pembacaan data variabel yang presisi |

#### Indikator LED sebagai visualisasi data
Untuk menggunakan LED sebagai bentuk visualisasi (output) dari data LDR, pertama kita perlu menginisialisasi nilai ambang batas sebagai kondisi HIGH atau LOW. Selanjutnya kita bisa menggunakan fungsi if dan else untuk menentukan kapan LED akan menyala. Perhatikan kode berikut :
```cpp
int ambang_batas = 500;
void setup {
  pinMode(1, OUTPUT);
  Serial.begin(9600);










