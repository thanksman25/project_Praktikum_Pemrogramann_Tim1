#include <stdio.h>

void login() {
    char akun; 
    printf("Silakan masuk dengan akun (u untuk user, a untuk admin): ");
    scanf(" %c", &akun);
    if (akun == 'u') {
        printf("Selmat datang user, berikut list alat lab yang tersedia\n");

    } else if (akun == 'a') {
        printf("Anda masuk sebagai admin.\n");
    } else {
        printf("Akun tidak dikenal. Silakan coba lagi.\n");
    }
}
