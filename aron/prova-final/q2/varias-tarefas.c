#include <stdio.h>
#include <pthread.h>
#include <semaphore.h> 

typedef struct {
    sem_t *semaphore1;
    sem_t *semaphore2;
    sem_t *semaphore3;
    int id;
} thread_barrier_args;

void *tarefaA(void *_args) {
    thread_barrier_args *args = (thread_barrier_args *) _args;

    printf("Tarefa A: Esta parte depende da primeira parte de D\n");

    sem_post(args->semaphore1);
    sem_post(args->semaphore2);

    return NULL;
}

void *tarefaB(void *_args) {
    thread_barrier_args *args = (thread_barrier_args *) _args;

    sem_wait(args->semaphore3);
    printf("Tarefa B: Eu só posso aparecer depois que D terminar\n");
    return NULL;

}

void *tarefaC(void *_args) {
    thread_barrier_args *args = (thread_barrier_args *) _args;

    printf("Tarefa C: Esta parte é independente\n");

    sem_wait(args->semaphore2);

    printf("Tarefa C: Esta parte depende da primeira parte de A\n");
    return NULL;

}

void *tarefaD(void *_args) {
    thread_barrier_args *args = (thread_barrier_args *) _args;

    printf("Tarefa D: Esta parte é independente\n");

    sem_wait(args->semaphore1);

    printf("Tarefa D: Eu só posso aparecer depois do fim de A.\n");

    sem_post(args->semaphore3);
    return NULL;

}

int main() {
    pthread_t ids[4];
    thread_barrier_args args[4];

    sem_t semaphore1;
    sem_t semaphore2;
    sem_t semaphore3;

    sem_init(&semaphore1, 0, 0);
    sem_init(&semaphore2, 0, 0);
    sem_init(&semaphore3, 0, 0);

    args[0].id = 0;
    args[0].semaphore1 = &semaphore1;
    args[0].semaphore2 = &semaphore2;
    args[0].semaphore3 = &semaphore3;

    pthread_create(&ids[0], NULL, tarefaD, &args[0]);

    args[1].id = 1;
    args[1].semaphore1 = &semaphore1;
    args[1].semaphore2 = &semaphore2;
    args[1].semaphore3 = &semaphore3;
    pthread_create(&ids[1], NULL, tarefaC, &args[1]);

    args[2].id = 2;
    args[2].semaphore1 = &semaphore1;
    args[2].semaphore2 = &semaphore2;
    args[2].semaphore3 = &semaphore3;
    pthread_create(&ids[2], NULL, tarefaA, &args[2]);

    args[3].id = 3;
    args[3].semaphore1 = &semaphore1;
    args[3].semaphore2 = &semaphore2;
    args[3].semaphore3 = &semaphore3;
    pthread_create(&ids[3], NULL, tarefaB, &args[3]);

    for (int i = 0; i < 4; i++) {
        pthread_join(ids[i], NULL);
    }
    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);
    sem_destroy(&semaphore3);

    return 0;
}
