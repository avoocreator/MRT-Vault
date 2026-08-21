**💡 Light Dependent Resistor (LDR) Indicator — Arduino Uno**  
Proyek ini menggunakan sensor cahaya **LDR (Light Dependent Resistor / photoresistor)** yang dihubungkan ke Arduino Uno untuk mendeteksi tingkat intensitas cahaya di sekitarnya, lalu menyalakan LED sebagai indikator visual.  
Ada **2 versi** proyek:  
| | | |  
|-|-|-|  
| **Versi** | **Jumlah LED** | **Fungsi** |   
| **Single Indicator** | 1 LED | Menyala/mati berdasarkan 1 ambang batas cahaya |   
| **Multi Indicator** | 3 LED (Merah, Kuning, Hijau) | Menyala bergantian berdasarkan 3 tingkat intensitas cahaya (seperti "traffic light" kondisi cahaya) |   
   
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAANUlEQVR4nO3OMQ2AABAAsSPBCUbfEnJYmFDBhAU2QtIq6DIzW7UHAMBfnGt1V8fXEwAAXrseCNsF7y+NXC0AAAAASUVORK5CYII=)  
**📋 Daftar Isi**  
- [Cara Kerja LDR](#anchor-1 "#anchor-1")  
- [Komponen yang Dibutuhkan](#anchor-2 "#anchor-2")  
- [1. Single Indicator](#anchor-3 "#anchor-3")  
  - [Skema Rangkaian](#anchor-4 "#anchor-4")  
  - [Penjelasan Kode](#anchor-5 "#anchor-5")  
- [2. Multi Indicator](#anchor-6 "#anchor-6")  
  - [Skema Rangkaian](#anchor-7 "#anchor-7")  
  - [Penjelasan Kode](#anchor-8 "#anchor-8")  
- [Kalibrasi Nilai Batas](#anchor-9 "#anchor-9")  
- [Troubleshooting](#anchor-10 "#anchor-10")  
- [Struktur Repository](#anchor-11 "#anchor-11")  
- [Lisensi](#anchor-12 "#anchor-12")  
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAANElEQVR4nO3OQQmAUBBAwSd8bOHVnBvBkAaxgjcRZhLMNjNHdQUAwF/cq9qr8+sJAACvrQctgQNH4A++9QAAAABJRU5ErkJggg==)  
**🔦 Cara Kerja LDR**  
LDR adalah resistor yang nilai resistansinya berubah tergantung intensitas cahaya yang mengenainya:  
- **Terang** → resistansi LDR  **kecil**  
- **Gelap** → resistansi LDR  **besar**  
LDR dipasang dalam rangkaian **pembagi tegangan (voltage divider)** bersama sebuah resistor tetap, lalu titik tengahnya dihubungkan ke pin analog Arduino (A0). Perubahan resistansi ini menyebabkan tegangan yang terbaca oleh Arduino ikut berubah, sehingga Arduino bisa membaca nilai cahaya melalui analogRead() dalam rentang  **0 – 1023**.  
Semakin **gelap** ruangan → semakin  **besar** nilai yang terbaca (tergantung arah pemasangan pembagi tegangan pada rangkaian ini, nilai besar = gelap, nilai kecil = terang).  
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAANklEQVR4nO3OQQmAABRAsSfYxZo/jVEMYQLPJrCCNxG2BFtmZquOAAD4i3Ot7mr/egIAwGvXA4rLBc059ysnAAAAAElFTkSuQmCC)  
**🧰 Komponen yang Dibutuhkan**  
- 1x Arduino Uno  
- 1x LDR (Photoresistor)  
- 1x Resistor 10kΩ (untuk pembagi tegangan LDR)  
- 1x Resistor 220Ω – 330Ω per LED (pembatas arus)  
- Kabel jumper  
- Breadboard  
- LED:  
  - **Single Indicator**: 1x LED (bebas warna)  
  - **Multi Indicator**: 3x LED (Merah, Kuning, Hijau)  
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAANUlEQVR4nO3OMQ2AABAAsSNBCUrfD6LYGNDAgAU2QtIq6DIzW7UHAMBfHGt1V+fXEwAAXrseHDAF/orRG+cAAAAASUVORK5CYII=)  
**1️⃣ Single Indicator**  
**Skema Rangkaian (Single Indicator)**  
Rangkaian ini terdiri dari:  
- **LDR** dipasang sebagai pembagi tegangan, terhubung ke pin  **A0** (analog input), 5V, dan GND.  
- **1 buah LED** terhubung melalui resistor ke pin digital  **13**.  
**Wiring:**  
| | |  
|-|-|  
| **Komponen** | **Pin Arduino** |   
| LDR (kaki 1, ke resistor pembagi) | 5V |   
| LDR (titik tengah pembagi tegangan) | A0 |   
| LDR (kaki 2) | GND |   
| LED (anoda, melalui resistor) | Pin 13 |   
| LED (katoda) | GND |   
   
*📷 Lihat gambar rangkaian * *Single Indicator* * pada folder repo ini — LDR ada di bagian bawah (dekat pin * *Power/Analog In* *), dan LED berada di bagian atas dekat pin * *13* *.*  
**Penjelasan Kode (Single Indicator)**  
File: LightDepentResistor_Single_Indicator.ino  
int photo_resistor = A0;  
 int batas = 500;  
 int nilai_sensor;  
 int LED = 13;  
   
- photo_resistor → menyimpan pin tempat LDR terhubung, yaitu pin analog A0.  
- batas → nilai ambang (*threshold*) yang menentukan kapan LED harus menyala. Nilainya 500 (dari rentang 0–1023).  
- nilai_sensor → variabel untuk menampung hasil pembacaan sensor tiap loop.  
- LED → pin digital 13 tempat LED terhubung.  
void setup() {  
   pinMode(LED, OUTPUT);  
   Serial.begin(9600);  
 }  
   
- pinMode(LED, OUTPUT) → mengatur pin 13 sebagai output, karena akan digunakan untuk menyalakan/mematikan LED.  
- Serial.begin(9600) → mengaktifkan komunikasi serial dengan kecepatan 9600 baud, supaya nilai sensor bisa dilihat di **Serial Monitor**.  
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
   
- analogRead(photo_resistor) → membaca nilai tegangan pada pin A0 (hasil dari pembagi tegangan LDR), lalu disimpan ke nilai_sensor.  
- Serial.print / Serial.println → menampilkan nilai sensor ke Serial Monitor, berguna untuk memantau dan mengkalibrasi nilai batas.  
- **Logika kondisi:**  
  - Jika nilai_sensor > batas (kondisi lebih terang dari batas) → LED **dimatikan** (0/LOW).  
  - Jika nilai_sensor <= batas (kondisi lebih gelap) → LED **dinyalakan** (1/HIGH).  
- delay(500) → jeda 500 ms sebelum pembacaan berikutnya, supaya pembacaan tidak terlalu cepat berubah-ubah (flicker).  
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAANklEQVR4nO3OQQmAABRAsSfYxZo/jVEMYQLPJrCCNxG2BFtmZquOAAD4i3Ot7mr/egIAwGvXA4rLBc059ysnAAAAAElFTkSuQmCC)  
**2️⃣ Multi Indicator**  
**Skema Rangkaian (Multi Indicator)**  
Rangkaian ini menggunakan breadboard dengan:  
- **LDR** dipasang sebagai pembagi tegangan menuju pin  **A0**.  
- **3 buah LED** (Merah, Kuning, Hijau), masing-masing melalui resistor pembatas arus, terhubung ke pin digital  **1**,  **2**, dan  **3**.  
**Wiring:**  
| | |  
|-|-|  
| **Komponen** | **Pin Arduino** |   
| LDR (pembagi tegangan) | 5V, A0, GND |   
| LED Merah (melalui resistor) | Pin 1 |   
| LED Kuning (melalui resistor) | Pin 2 |   
| LED Hijau (melalui resistor) | Pin 3 |   
| Semua katoda LED | GND (rail bawah breadboard) |   
   
**Penjelasan Kode (Multi Indicator)**  
File: LightDepentResistor_Multi_Indicator.ino  
int photo_resistor = A0;  
 int batas_1 = 500;  
 int batas_2 = 150;  
 int nilai_sensor;  
 int LED_merah = 1;  
 int LED_kuning = 2;  
 int LED_hijau = 3;  
   
- photo_resistor → pin analog A0 tempat LDR terhubung.  
- batas_1 dan batas_2 → dua ambang batas yang membagi kondisi cahaya menjadi **3 zona**:  
  - nilai_sensor > batas_1 → zona paling gelap → LED **Merah**  
  - batas_2 <= nilai_sensor <= batas_1 → zona sedang → LED **Kuning**  
  - nilai_sensor < batas_2 → zona paling terang → LED **Hijau**  
- nilai_sensor → variabel penampung hasil pembacaan sensor.  
- LED_merah, LED_kuning, LED_hijau → masing-masing menyimpan nomor pin digital tempat LED terhubung (pin 1, 2, 3).  
void setup() {  
   pinMode(LED_merah, OUTPUT);  
   pinMode(LED_kuning, OUTPUT);  
   pinMode(LED_hijau, OUTPUT);  
   Serial.begin(9600);  
 }  
   
- Mengatur ketiga pin LED sebagai OUTPUT.  
- Mengaktifkan komunikasi Serial pada 9600 baud untuk memantau nilai sensor.  
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
   
- analogRead(photo_resistor) → membaca nilai cahaya dari LDR (0–1023) dan menyimpannya ke nilai_sensor.  
- Nilai sensor ditampilkan di Serial Monitor untuk membantu kalibrasi.  
- **Logika kondisi (if-else berjenjang):**  
  1. **nilai_sensor > batas_1** ** (paling gelap)** → LED Merah  **ON**, Kuning  **OFF**, Hijau  **OFF**.  
  2. **batas_2 <= nilai_sensor <= batas_1** ** (cahaya sedang)** → LED Merah  **OFF**, Kuning  **ON**, Hijau  **OFF**.  
  3. **nilai_sensor < batas_2** ** (paling terang)** — kondisi else terakhir → LED Merah  **OFF**, Kuning  **OFF**, Hijau  **ON**.  
- delay(500) → jeda 500 ms antar pembacaan agar transisi LED tidak terlalu cepat/flicker.  
**Ringkasan logika (visual):**  
Gelap  ─────────────────────────────►  Terang  
 nilai_sensor:  1023 ... batas_1(500) ... batas_2(150) ... 0  
                  🔴 MERAH      🟡 KUNING        🟢 HIJAU  
   
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAANklEQVR4nO3OQQmAABRAsSfYxZo/jkUsYQLPJrCCNxG2BFtmZquOAAD4i3Ot7mr/egIAwGvXA4rDBc72meO5AAAAAElFTkSuQmCC)  
**🎚️ Kalibrasi Nilai Batas**  
Nilai batas / batas_1 / batas_2 **sangat tergantung kondisi pencahayaan ruangan** dan jenis LDR yang dipakai. Cara mengkalibrasi:  
1. Upload sketch ke Arduino, lalu buka **Serial Monitor** (Tools > Serial Monitor, baud rate 9600).  
2. Amati nilai Data sensor yang muncul saat kondisi **terang** dan saat ditutup tangan ( **gelap**).  
3. Catat rentang nilai yang muncul, misalnya:  
  - Terang: ~100–200  
  - Redup: ~300–450  
  - Gelap: ~600–900  
4. Sesuaikan nilai batas (single) atau batas_1 & batas_2 (multi) di kode agar sesuai dengan rentang tersebut.  
![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAnEAAAACCAYAAAA3pIp+AAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAAM0lEQVR4nO3OMQ0AIAwAwdIgBKl1gjacsGCAiZDcTT9+q6oRETMAAPjF6ify6QYAADdyA9Y0AypN+bdfAAAAAElFTkSuQmCC)  
   
   
