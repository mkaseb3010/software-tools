#include<stdio.h>

int main(void) {
    char message[80];
    int i, shift, ch;
    printf("Enter message to be encrypted: ");
    gets(message);
    printf("Enter shift amount (1-25): ");

    while (1) { 
        if (scanf("%d", &shift) && shift >= 1 && shift <= 25) { 
            break;
        }else { 
            printf("You must input a shift key value between 1 - 25 (Inclusive). Please try again!\nYour Number: ");
        }
    }
    
    for(i = 0; i < 80; i++){
        ch = (message[i] + shift);
        if(message[i] >= 'a' && message[i]  <= 'z'){
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(message[i]  >= 'A' && message[i]  <= 'Z'){
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    
    printf("Encrypted message: %s", message);
    return 0;
}
