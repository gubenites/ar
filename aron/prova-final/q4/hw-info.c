#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

typedef struct {
    int initialized, data;
} hw_info;

hw_info *hw_init() {
    hw_info *hi = malloc(sizeof(hw_info));
    hi->initialized = 1;
    hi->data = rand() % 50;
    printf("Hardware initialized: %d\n", hi->data);
    return hi;
}

void hw_shutdown(hw_info *hi) {
    free(hi);
}

int hw_get_steps(hw_info *hi) {
    assert(hi->initialized == 1);

    int s = rand() % 50;
    if (s == hi->data) {
        int *mem = NULL;
        *mem = s;
    }
    usleep(100000);
    return s;
}

int main() {
    srand(time(NULL));

    while (1) {
        hw_info *hi = hw_init();
        pid_t child = fork();
        if (child == 0) {
            while (1) {
                printf("Steps: %d\n", hw_get_steps(hi));
            }
        }
        printf("[ERROR] Reintializing hardware\n");
        int st;
        wait(&st);
        hw_shutdown(hi);
    }
}