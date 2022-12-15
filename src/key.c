#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int create_key(char* filename_input, char* filename_output) {
    FILE *file_input, *file_output;
    int x, c;
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789&~#'`\"{}()[]-_+=|@$£€¤*µ%!§:/\\;.,?";
    size_t characters_length = strlen(characters);
    srand(time(NULL));
    
    file_input = fopen(filename_input, "r");
    if(file_input == NULL) {
        fprintf(stderr, "ERREUR : Impossible d'ouvrir le fichier d'entrée%s\n", filename_input);
        return EXIT_FAILURE;
    }

    
    file_output = fopen(filename_output, "w");
    if (file_output == NULL) {
        fclose(file_input);
        fprintf(stderr, "ERREUR : Impossible d'ouvrir le fichier de sortie %s\n", filename_output);
        return EXIT_FAILURE;
    }

    while (fgetc(file_input) != EOF) {
        x = rand() % characters_length;
        fputc(characters[x], file_output);
    }

    fclose(file_input);
    fclose(file_output);

    return EXIT_SUCCESS;
}