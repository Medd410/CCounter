#include "countf.h"

int countChars(FILE *f) {
    int i = 0;
    while (fgetc(f) != EOF) {
        i++;
    }
    return i;
}

int countWords(FILE *f) {
    int c, a = 0, i = 0;
    while (1) {
        c = fgetc(f);
        if (isalnum(c)) {
            a = 1;
            continue;
        }
        if ((isspace(c) || c == 10 || c == EOF) && a) {
            i++;
            a = 0;
        }
        if (c == EOF) break;
    }
    return i;
}

int countLines(FILE *f) {
    int c, i = 1;
    while ((c = fgetc(f)) != EOF) {
        if (c == 10) i++;
    }
    return i;
}