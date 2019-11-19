#include "countf.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0 && strcmp(argv[1], "-l") != 0) {
        printf("First argument need to be equal to '-c', '-w' or '-l'");
        return EXIT_FAILURE;
    }
    FILE *f = fopen(argv[2], "r");
    if (f == NULL) {
        printf("Unable to access specified file");
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "-c") == 0) {
        printf("%d characters", countChars(f));
    }
    else if (strcmp(argv[1], "-w") == 0) {
        printf("%d words", countWords(f));
    }
    else {
        printf("%d lines", countLines(f));
    }
    fclose(f);
    return EXIT_SUCCESS;
}