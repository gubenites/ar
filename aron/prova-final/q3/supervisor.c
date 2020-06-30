#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    while (1) {
        char prog[] = "ls";
        // a lista de argumentos sempre começa com o nome do
        // programa e termina com NULL
        char *args[] = {"ls", "-l", "-a", NULL}; 

        execvp(prog, args);
        printf("Fim do exec!\n");
    }
}