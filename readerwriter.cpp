#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mtx;
int rc = 0;

void reader () {
    sem_wait(&rsem);
    if (++rc == 1) {
        pthread_mutex_lock(&mtx);
    }
    sem_post(&rsem);

    pthread_mutex_lock(&mtx);
    // read_to_DB
    pthread_mutex_unlock(&mtx);

    sem_wait(&rsem);
    if (--rc == 0) {
        pthread_mutex_unlock(&mtx);
    }
    sem_post(&rsem);
}

void writer () {
    pthread_mutex_lock(&mtx);
    // write_to_DB
    pthread_mutex_unlock(&mtx);
}

int main () {
    pthread_t tid[4];

    pthread_create_t(&tid[0], NULL, writer, NULL);

    pthread_mutex_init(&mtx, NULL);

    for (int i = 1; i < 4; i++) {
        pthread_create_t(&tid[i], NULL, reader, NULL);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }
}