#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LINE 256

int main() {

    char line[MAX_LINE], words[MAX_WORDS][MAX_LINE];
    int word_count = 0;
    int is_title = 1;

    FILE *input = fopen("lirik.txt", "r");
    FILE *output = fopen("kosa-kata.word", "w");
    if (!input || !output) {
        printf("Error: Tidak dapat membuka file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), input)) {
        if (is_title) { 
            fprintf(output, "%s", line);
            is_title = 0;
            continue;
        }
