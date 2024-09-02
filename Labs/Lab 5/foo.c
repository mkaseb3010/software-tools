#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv) {
    //Declare any variables you need

    int i, sum, terminate;
    char counter[80];

    // Write the code to loop over the command line arguments.
    // (Remember to skip the executable name.)

    for(i = 1; i < argc; i++) { // call fork
        int f = fork();
        if(f < 0) { // System call error // Handle the error
            printf("System Error");
            exit(0);
        }else if (f == 0) { // Child processes // Child does work here
            char *counter = argv[i];
            int len = strlen(counter);
            exit(len);
        }
    } // Parent process.
    // Return values from the child processes

    for(i = 1; i < argc; i++) {
        wait(&terminate);
        sum += WEXITSTATUS(terminate);
    }

    printf("The length of all the args %d\n", sum);
    return 0;
}