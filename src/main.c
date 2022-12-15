#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/encode.h"
#include "../inc/decode.h"
#include "../inc/key.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "ERREUR : Aucun argument passé en paramètre.\nUsage :\n    Encodage :\n\t%s -c [fichier d'entrée] [fichier clé] [fichier de sorite]\n    Décodage :\n\t%s -d [fichier d'entrée] [fichier clé] [fichier de sorite]\n    Création d'une clé :\n\t%s -k [fichier d'entrée] [fichier de sorite]\n", argv[0], argv[0], argv[0]);
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "-c") == 0) {
        if (argc < 5) {
            fprintf(stderr, "ERREUR : Arguments manquants.\nUsage : %s -c [fichier d'entrée] [fichier clé] [fichier de sorite]\n", argv[0]);
            return EXIT_FAILURE;
        }

        return encode(argv[2], argv[3], argv[4]);

    } else if (strcmp(argv[1], "-d") == 0) {
        if (argc < 5) {
            fprintf(stderr, "ERREUR : Arguments manquants.\nUsage : %s -d [fichier d'entrée] [fichier clé] [fichier de sorite]\n");
            return EXIT_FAILURE;
        }

        return decode(argv[2], argv[3], argv[4]);

    } else if (strcmp(argv[1], "-k") == 0) {
        if (argc < 4) {
            fprintf(stderr, "ERREUR : Arguments manquants.\nUsage : %s -k [fichier d'entrée] [fichier de sortie]\n");
            return EXIT_FAILURE;
        }

        return create_key(argv[2], argv[3]);

    } else {
        fprintf(stderr, "ERREUR : L'argument \"%s\" n'est pas reconnu.\nUsage :\n    Encodage :\n\t%s -c [fichier d'entrée] [fichier clé] [fichier de sorite]\n    Décodage :\n\t%s -d [fichier d'entrée] [fichier clé] [fichier de sorite]\n    Création d'une clé :\n\t%s -k [fichier d'entrée] [fichier de sorite]\n", argv[1], argv[0], argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}