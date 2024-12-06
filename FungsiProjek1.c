include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALAT 100
#define MAX_USER 2

// Struktur data alat
typedef struct {
    unsigned int id;
    char nama[100];
    char merek[100];
    char model[100];
    unsigned int tahun_produksi;
    unsigned int jumlah_unit;
    unsigned int jumlah_tersedia;
} AlatLab;

// Struktur untuk menyimpan akun
typedef struct {
    char username[50];
    char password[50];
    int role; // 0: User, 1: Admin
} Akun;

// Daftar alat dan akun
AlatLab alatLabs[MAX_ALAT];
Akun akun[MAX_USER];

// Fungsi untuk login
int login(char *username, char *password) {
    for (int i = 0; i < MAX_USER; i++) {
        if (strcmp(username, akun[i].username) == 0 && strcmp(password, akun[i].password) == 0) {
            return akun[i].role; // 0: User, 1: Admin
        }
    }
    return -1; // Gagal login
}

// Fungsi untuk membaca data alat dari file
void readDataAlat() {
    FILE *file = fopen("alat_lab.txt", "r");
    if (file == NULL) {
        printf("File tidak ditemukan! Menggunakan data default.\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%u %s %s %s %u %u %u\n", &alatLabs[i].id, alatLabs[i].nama, alatLabs[i].merek, alatLabs[i].model, 
                   &alatLabs[i].tahun_produksi, &alatLabs[i].jumlah_unit, &alatLabs[i].jumlah_tersedia) != EOF) {
        i++;
    }
    fclose(file);
}

// Fungsi untuk menulis data alat ke file
void writeDataAlat() {
    FILE *file = fopen("alat_lab.txt", "w");
    if (file == NULL) {
        printf("Error saat menyimpan data!\n");
        return;
    }
    for (int i = 0; i < MAX_ALAT && alatLabs[i].id != 0; i++) {
        fprintf(file, "%u %s %s %s %u %u %u\n", alatLabs[i].id, alatLabs[i].nama, alatLabs[i].merek, alatLabs[i].model, 
                alatLabs[i].tahun_produksi, alatLabs[i].jumlah_unit, alatLabs[i].jumlah_tersedia);
    }
    fclose(file);
}

// Fungsi untuk menampilkan alat lab
void showAlatLab() {
    printf("\nDaftar Alat Lab yang Tersedia:\n");
    for (int i = 0; alatLabs[i].id != 0; i++) {
        if (alatLabs[i].jumlah_tersedia > 0) {
            printf("%u. %s (%s) - %s (%u tersedia)\n", alatLabs[i].id, alatLabs[i].nama, alatLabs[i].merek, alatLabs[i].model, alatLabs[i].jumlah_tersedia);
        }
    }
}

// Fungsi untuk meminjam alat lab
void pinjamAlatLab() {
    unsigned int id;
    printf("Masukkan ID alat yang ingin dipinjam: ");
    scanf("%u", &id);
    for (int i = 0; alatLabs[i].id != 0; i++) {
        if (alatLabs[i].id == id && alatLabs[i].jumlah_tersedia > 0) {
            alatLabs[i].jumlah_tersedia--;
            printf("Anda berhasil meminjam alat: %s\n", alatLabs[i].nama);
            writeDataAlat();
            return;
        }
    }
    printf("Alat tidak ditemukan atau tidak tersedia.\n");
}

// Fungsi untuk mengembalikan alat lab
void kembalikanAlatLab() {
    unsigned int id;
    printf("Masukkan ID alat yang ingin dikembalikan: ");
    scanf("%u", &id);
    for (int i = 0; alatLabs[i].id != 0; i++) {
        if (alatLabs[i].id == id) {
            alatLabs[i].jumlah_tersedia++;
            printf("Anda berhasil mengembalikan alat: %s\n", alatLabs[i].nama);
            writeDataAlat();
            return;
        }
    }
    printf("Alat tidak ditemukan.\n");
}

// Fungsi untuk admin menambah alat
void tambahAlatLab() {
    AlatLab newAlat;
    printf("Masukkan ID alat: ");
    scanf("%u", &newAlat.id);

    for (int i = 0; i < MAX_ALAT; i++) {
        if (alatLabs[i].id == newAlat.id) {
            printf("ID alat sudah digunakan. Masukkan ID lain.\n");
            return;
        }
    }

    printf("Masukkan nama alat: ");
    scanf("%s", newAlat.nama);
    printf("Masukkan merek alat: ");
    scanf("%s", newAlat.merek);
    printf("Masukkan model alat: ");
    scanf("%s", newAlat.model);
    printf("Masukkan tahun produksi: ");
    scanf("%u", &newAlat.tahun_produksi);
    printf("Masukkan jumlah unit: ");
    scanf("%u", &newAlat.jumlah_unit);
    newAlat.jumlah_tersedia = newAlat.jumlah_unit;

    for (int i = 0; i < MAX_ALAT; i++) {
        if (alatLabs[i].id == 0) { // Cari elemen kosong
            alatLabs[i] = newAlat;
            break;
        }
    }

    writeDataAlat();
}

// Fungsi untuk admin menghapus alat
void hapusAlatLab() {
    unsigned int id;
    printf("Masukkan ID alat yang ingin dihapus: ");
    
    // Periksa apakah scanf berhasil
    if (scanf("%u", &id) != 1) {
        printf("Input tidak valid.\n");
        return;
    }

    // Mengasumsikan alatLabs adalah array dengan ukuran yang diketahui
    int found = 0; // Flag untuk memeriksa apakah item ditemukan
    for (int i = 0; i < MAX_ALAT; i++) { // Ganti MAX_ALAT_LABS dengan ukuran sebenarnya dari array
        if (alatLabs[i].id == id) {
            found = 1; // Set flag ditemukan
            // Geser elemen setelah yang dihapus ke kiri
            for (int j = i; j < MAX_ALAT - 1; j++) {
                alatLabs[j] = alatLabs[j + 1];
            }
            alatLabs[MAX_ALAT - 1].id = 0; // Mengatur elemen terakhir menjadi 0 (atau nilai default lainnya)
            printf("\nAlat dengan ID %u berhasil dihapus.\n", id);
            writeDataAlat(); // Pastikan fungsi ini menangani data yang diperbarui dengan benar
            break; // Keluar dari loop setelah penghapusan
        }
    }
    
    if (!found) {
        printf("Alat tidak ditemukan.\n");
    }
}
