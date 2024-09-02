#include<stdio.h>
int stringCounter(char phoneNum[]) {
    int count;
    for(count = 0; phoneNum[count] != '\0'; count++);
return count;
}

int main(){
    char phoneNum[100];
    int index;   
    int i = 0;
    scanf("%s %d", phoneNum, &index);
    while(scanf("[\n]%c", &phoneNum) != EOF) {
        int length = stringCounter(phoneNum);
        if (index == 0 && length <= 10){ 
            printf("%s\n", phoneNum);
        } else if (index >= 1 && index <= 9 && length <= 10){
            printf("%c\n", phoneNum[index]);
        } else if(length > 10 || index > 9) {
            printf("%c\n", phoneNum[length - 1]);
        }else {
            return 0;
        }
        scanf("%s %d", phoneNum, &index);
    }
    return 0;
}
