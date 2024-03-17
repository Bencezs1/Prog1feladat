#include <windows.h>
#include <string.h>
#include <stdio.h>

#define MAX_KULCS 100
#define BUFFER_MERET 256

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Kell a kulcs argumentumban");
        return 1;
    }

    char kulcs[MAX_KULCS];
    char buffer[BUFFER_MERET];

    int kulcs_index = 0;
    DWORD olvasott_bajtok;

    int kulcs_meret = strlen(argv[1]);
    strncpy(kulcs, argv[1], MAX_KULCS);

    char be[50], ki[50];
    printf("Bemeneti fajl neve: ");
    scanf("%s",be);
    printf("Kimeneti fajl neve (barmi lehet): ");
    scanf("%s",ki);

    FILE *input = fopen(be, "rb");
    if (input == NULL) {
        printf("Hiba a bemeneti fajl megnyitasakor\n");
        return 1;
    }

    FILE *output = fopen(ki, "wb");
    if (output == NULL) {
        printf("Hiba az output fajl letrehozasakor\n");
        fclose(input);
        return 1;
    }

    while ((olvasott_bajtok = fread(buffer, 1, BUFFER_MERET, input)) > 0) {
        for (int i = 0; i < olvasott_bajtok; ++i) {
            buffer[i] = buffer[i] ^ kulcs[kulcs_index];
            kulcs_index = (kulcs_index + 1) % kulcs_meret;
        }

        fwrite(buffer, 1, olvasott_bajtok, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}
