#include <stdio.h>
#include <ctype.h>

void caseChars(char input[]) {
    int ch;
    while((ch = getchar()) != '\n') {
        if(isalpha(ch)) {
            ch = tolower(ch);
            ch = ch - 97;
            input[ch]++;
        }
    }
}

int checkStrings(char firstWord[], char secondWord[]) {
    for(int i = 0; i < 80; i++) {
        if(firstWord[i] != secondWord[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char firstWord[80] = {0};
    char secondWord[80] = {0};

    printf("Enter first word: ");
    caseChars(firstWord);
    printf("Enter second word: ");
    caseChars(secondWord);

    if(checkStrings(firstWord, secondWord)) {
        printf("The words are anagrams.");
    }else {
        printf("The words are not anagrams.");
    }
    return 0;
}