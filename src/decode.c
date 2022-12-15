#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int decode(char *filename_input, char *filename_key, char *filename_output) {
    FILE *file_input, *file_key, *file_output;
    int c, k1, calcul;

    file_input = fopen(filename_input, "r");
    if(file_input == NULL) {
        fprintf(stderr, "ERREUR : Impossible d'ouvrir le fichier d'entrée%s\n", filename_input);
        return EXIT_FAILURE;
    }
    
    file_key = fopen(filename_key, "r");
    if(file_key == NULL) {
        fclose(file_input);
        fprintf(stderr, "ERREUR : Impossible d'ouvrir le fichier contenant la clé%s\n", filename_key);
        return EXIT_FAILURE;
    }

    file_output = fopen(filename_output, "w");
    if(file_output == NULL) {
        fclose(file_input);
        fclose(file_key);
        fprintf(stderr, "ERREUR : Impossible d'ouvrir le fichier de sortue%s\n", filename_output);
        return EXIT_FAILURE;
    }

    while ((c = fgetc(file_input)) != EOF) {
        k1 = fgetc(file_key);
        calcul = c-k1 >= 0?c-k1:256-(c-k1);
        fputc(calcul, file_output);
    }

    fclose(file_input);
    fclose(file_key);
    fclose(file_output);

    return EXIT_SUCCESS;
}