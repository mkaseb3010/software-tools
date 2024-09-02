#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encryptFile(FILE *filenamepointer, FILE *filenamedestinationpointer, int shift);

int *shiftCharacter(int *character, int shift);

void encryptFile(FILE *sourceFilePointer, FILE *destinationFilePointer, int shiftAmount) {
    int ch;
    while ((ch = getc(sourceFilePointer)) != EOF) {
        if (isalpha(ch)) {
            int shiftedCharacter = *shiftCharacter(&ch, shiftAmount);
            putc(shiftedCharacter, destinationFilePointer);
        } else {
            putc(ch, destinationFilePointer);
        }
    }
}

int *shiftCharacter(int *character, int shiftAmount) {
    int ch = (*character + shiftAmount);
    if (*character >= 'a' && *character <= 'z') { 
        if (ch > 'z') { 
            ch = ch - 'z' + 'a' - 1;
        }
    } 
    else if (*character >= 'A' && *character <= 'Z') { 
        if (ch > 'Z') { 
            ch = ch - 'Z' + 'A' - 1;
        }
    }
    *character = ch;
    return character;
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    char *filenamedestination = malloc(sizeof(filename) + 5);
    strcpy(filenamedestination, filename);
    strcat(filenamedestination, ".enc");
    const char *ext = strrchr(filename, '.');
    if(filename == "%s.txt.enc", filename) {
        ext = ".txt";
    }
    FILE *filenamepointer;
    FILE *filenamedestinationpointer;
    filenamepointer = fopen(filename, "rb");
    filenamedestinationpointer = fopen(filenamedestination, "wb");
    int shift = atoi(argv[2]);

    if (shift < 1 || shift > 25) {
        printf("You must input a shift key value between 1 - 25 (Inclusive). \n");
        return 1; 
    }

    if (filenamepointer == NULL) {
        printf("The file %s does not exist", filename);
        return 2; 
    }

    encryptFile(filenamepointer, filenamedestinationpointer, shift);
    fclose(filenamepointer);
    fclose(filenamedestinationpointer);
    free(filenamedestination);
    return 0; 
}

