#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_KATA 1000
#define MAX_BARIS 256

int main() {
    char baris[MAX_BARIS], kata[MAX_KATA][MAX_BARIS];
    int jumlah_kata = 0;
    int judul = 1;
    int unik = 1;

    //membuka file input dan output
    FILE *input = fopen("lirik.txt", "r");
    FILE *output = fopen("kosa-kata.word", "w");
    if (!input || !output) {
        printf("Error: Tidak dapat membuka file.\n");
        return 1;
    }
    //membaca baris dari file input
    while (fgets(baris, sizeof(baris), input)) {
        if (judul) { 
            //menulis baris pertama ke file output
            fprintf(output, "%s", baris);
            judul = 0;
            continue;
        }
        //memisahkan kata-kata dalam baris
        char *lirik = strtok(baris, " \n");
        while (lirik) {
            // Bersihkan kata
            char bersih[MAX_BARIS] = "";
            int j = 0;
            for (int i = 0; lirik[i]; i++) {
                if (isalnum(lirik[i]) || lirik[i] == '\'' || lirik[i] == '-') {
                    bersih[j++] = tolower(lirik[i]);
                }
            }
            bersih[j] = '\0';

            // Cek keunikan
            for (int i = 0; i < jumlah_kata; i++) {
                if (strcmp(kata[i], bersih) == 0) {
                    unik = 0;
                    break;
                }
            }
            //jika kata unik, ditambahkan ke daftar kata
            if (unik && strlen(bersih) > 0) {
                strcpy(kata[jumlah_kata++], bersih);
            }

            lirik = strtok(NULL, " \n");
        }
    }

    // Tulis ke file output
    for (int i = 0; i < jumlah_kata; i++) {
        fprintf(output, "%s=\n", kata[i]);
    }
    //menutup file input dan output
    fclose(input);
    fclose(output);
    return 0;
}
