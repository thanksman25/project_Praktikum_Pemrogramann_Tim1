#ifndef HEADER_H
#define HEADER_H

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
extern AlatLab alatLabs[MAX_ALAT];
extern Akun akun[MAX_USER];

// Fungsi untuk login
int login(char *username, char *password);