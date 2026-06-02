// Online C++ compiler to run C++ program online
#include <iostream>
#include <mutex>
#include <semaphore>
+#include <thread>
using namespace std;

#define BUFFER_SIZE 1024

class producerConsumer {
    int BUFFER[BUFFER_SIZE];
    size_t bufferSize;
    counting_semaphore<BUFFER_SIZE> E(BUFFER_SIZE);
    counting_semaphore<BUFFER_SIZE> F(0);
    mutex mtx;
    int out = 0;
    int itemc;
    int in = 0;
    int itemp;
    int (*produce)();
    void (*consume)(int);

    void producer() {
        while (true) {
            itemp = this->produce();
            E.acquire();
            mtx.lock();
            BUFFER[in] = itemp;
            in++;
            in = in%BUFFER_SIZE;
            mtx.unlock();
            F.release();
        }
    }

    void consumer() {
        while (true) {
            F.acquire();
            mtx.lock();
            itemc = BUFFER[out];
            out--;
            out = out%BUFFER_SIZE;
            mtx.unlock();
            E.release();
            this->consume(itemc);
        }
    }
    
    public:
    producerConsumer( int (*produce)(), void (*consume)(int )) {
        this->produce = produce;
        this->consume = consume;
    }
    
    void start() {
        thread prod(producer);
        thread con(consumer);
        prod.join();
        con.join();
    }
};


int main() {
    return 0;
}