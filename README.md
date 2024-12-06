# Project_Praktikum_Pemrogramann_Tim1
Tim 1
- FAYLA SYIFA RUSTAM_2408107010029
- ALMIRA SADIDA_2408107010004
- ANNISA RAHMA FATHIA_2408107010027
- SYIFA SALSABILA_2408107010018
- ABDAN SYAKURA BIN YASIR_2408107010014
- TEUKU AL JUMANATUL ALI_2408107010016
- NAYLA NABILA SYAHEL_2408107010005
  
Repository ini berisi dua project dengan deskripsi sebagai berikut:

1. Project Pertama: Sistem Peminjaman Alat Laboratorium
project1.c: File utama yang berisi fungsi main. Program ini merupakan inti dari project pertama.
header.h: File header yang berisi deklarasi fungsi dan struktur data. File ini dihubungkan dengan project1.c untuk mendefinisikan fungsi-fungsi yang digunakan.
fungsiproject1.c: File yang berisi 11 fungsi terkait dengan sistem peminjaman alat laboratorium. Fungsi-fungsi ini mendukung operasi utama pada program.
alat_lab.txt: File data yang berisi daftar alat-alat laboratorium. Data ini digunakan sebagai sumber informasi oleh program.

Untuk menjalankan project ini:
1. Simpan semua file terkait dalam satu folder.

2. Buka terminal, lalu ketik perintah berikut untuk kompilasi:
   make project1
   Hasilnya adalah file eksekusi bernama program1.

3. Untuk menjalankan program, masukkan akun yang sesuai. Contoh:
   ./program1 user user123    atau    ./program1 admin admin123

2. Project Kedua: Sistem Pemisahan Kosa-Kata dari Lirik Lagu
project2.c : File utama yang berisi fungsi main beserta fungsi tambahan untuk memproses lirik lagu. Program ini memisahkan kosa-kata dari lirik lagu menjadi file terpisah.
lirik.txt : File input yang berisi lirik lagu. Lirik ini akan diproses oleh program.
kosa-kata.txt : File output yang berisi hasil pemisahan kosa-kata setelah program dijalankan.

Untuk menjalankan project ini:
1. Simpan semua file terkait dalam satu folder.
2. Buka terminal, lalu ketik perintah berikut untuk kompilasi:
   make project2
   Hasilnya adalah file eksekusi bernama program2.
3. Jalankan program dengan perintah:
   ./program2
   Hasil pemrosesan akan tersimpan di file kosa-kata.txt.

Makefile
Makefile berisi perintah untuk mempermudah proses kompilasi kedua project. 
Gunakan perintah berikut:
 make project1 : Untuk kompilasi project pertama.
 make project2 : Untuk kompilasi project kedua.
