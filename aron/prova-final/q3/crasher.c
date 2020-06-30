#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        if (rand() % 10 == 5) {
            int i = 10/0;
        } else if (rand() % 10 == 0) {
            int *n = NULL;
            *n = 10;
        }
        sleep(1);
    }
    return 0;
}
