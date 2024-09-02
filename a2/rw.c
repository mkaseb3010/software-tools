#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int bool;
#define true 1;
#define false 0;

char tenbyten[10][10];
char nextChar = 'B';
int i = 0;
int j = 0;

    void nextIndex(int direction) {
        switch(direction) {
            case 0:
                i -= 1;
                break;
            case 1:
                j += 1;
                break;
            case 2:
                i += 1;
                break;
            case 3:
                j -= 1;
                break;
        }
    }

    int hasSpace(int direction) {
        int a = i;
        int b = j;
        switch (direction) {
            case 0:
                a -= 1;
                break;
            case 1:
                b += 1;
                break;
            case 2:
                a += 1;
                break;
            case 3:
                b -= 1;
                break;
        }

        if(tenbyten[a][b] == '.') {
            return 0;
        }else {
            return 1;
        }
    }

    bool outOfBounds(int direction) {
        int a = i;
        int b = j;
        int aRange = false;
        int bRange = false;
        
        switch (direction) {
            case 0:
                a -= 1;
                break;
            case 1:
                b += 1;
                break;
            case 2:
                a += 1;
                break;
            case 3:
                b -= 1;
                break;
        }

        if(a >= 0 && a <= 9) {
            aRange = true;
        }else {
            aRange = false;
        }
        
        if(b >= 0 && b <= 9) {
            bRange = true;
        }else {
            bRange = false;
        }
        return aRange && bRange;
    }

    bool changeLocation(int direction) {
        return outOfBounds(direction) && !hasSpace(direction);
    }

    bool notBlocked() {
        return !(changeLocation(0) || changeLocation(1) || changeLocation(2) || changeLocation(3));
    }

    void move() {
        int direction = rand() % 4;
        if(changeLocation(direction)) {
            nextIndex(direction);
            tenbyten[i][j] = nextChar;
            nextChar++;
        }
        if(!notBlocked() && nextChar <= 'Z') {
            move();
        }
    }

int main(void) {
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tenbyten[i][j] = '.';
        }
    }
    tenbyten[0][0] = 'A';

    move();

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%c", tenbyten[i][j]);
        }
        printf("\n");
    }
    return 0;
}