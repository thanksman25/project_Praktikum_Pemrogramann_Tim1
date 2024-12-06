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
