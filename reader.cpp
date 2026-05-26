
#include <iostream>
#include <memory>
#include <sys/ipc.h>
#include <sys/shmget.h>

#define SHM_KEY = 1234
#define SHM_SIZE = 4096

int main {
    int shmid;

    shmid = shmget(SHM_KEY, SHM_SIZE, 0666);

    shmat(shmidn null_ptr, 0);
}