**LIGHT DEPENDENT RESISTOR (LDR)**
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

**Pembacaan Sensor**
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



