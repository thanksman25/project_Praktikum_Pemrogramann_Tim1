#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include"header.h"
#define MAX_ALAT 100
 

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Gunakan format: %s <username> <password>\n", argv[0]);
        return 1;
    }

    // Data akun
    strcpy(akun[0].username, "user");
    strcpy(akun[0].password, "user123");
    akun[0].role = 0; // User

    strcpy(akun[1].username, "admin");
    strcpy(akun[1].password, "admin123");
    akun[1].role = 1; // Admin

    // Membaca data alat dari file
    readDataAlat();

    // Login
    int role = login(argv[1], argv[2]);
    if (role == -1) {
        printf("Login gagal. Username atau password salah.\n");
        return 1;
    }

    if (role == 1) {
        menuAdmin();
    } else {
        menuUser();
    }

    return 0;
}
