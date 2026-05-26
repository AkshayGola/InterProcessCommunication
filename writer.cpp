
#include <iostream>
#include <memory>
#include <sys/ipc.h>
#include <sys/shmget.h>

#define SHM_KEY = 1234
#define SHM_SIZE = 4096

int main {
    int shmid;

    shmid = shmget(SHM_KEY, SHM_SIZE, 0666);

    shmat(shmid, null_ptr, 0);

    char * shm_ptr = shmat(shmid, null_ptr, 0);

    const char* message = "[Writer]: Hello from writer process!";

    strncpy(shm_ptr, message, 4096 - 1);
}