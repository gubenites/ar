#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>

int main() {
    sleep(5); 
    kill(getpid(), 2);
}
