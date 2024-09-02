#include<stdio.h>

int main(void) {
    int rows;
    int i, j, k;
    int spacesBef = 0;
    int spacesAft = 1;
    printf("Enter the number of rows in the triangle: ");

    while (1) { 
        if (scanf("%d", &rows) == 1 && rows >= 1 && rows <= 20) { 
            break;
        }else { 
            printf("You must input a number between 1 - 20 (Inclusive). Please try again!\nYour Number: ");
        }
    }
    
    for(int i = 1; i < rows; i++) {
        spacesBef = rows - i + 1;
        for(int j = 1; j < spacesBef; j++) {
            printf(" ");
        }
        if (i == 1) {
            printf("*\n");
        }else {
            printf("*");
            for(int k = 0; k < spacesAft; k++) {
                printf(" ");
            }
            spacesAft += 2;
            printf("*\n");
        }
    }

    int lastRow = 2 * rows - 1;
    for(int i = 0; i < lastRow; i++) {
        printf("*");
    }
    printf("\n");
}
