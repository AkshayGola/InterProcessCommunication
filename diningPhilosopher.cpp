#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <thread>

void think () {
    cout << "thinking \n";
}

void eat() {
    cout << "eating \n";
}


void thread1 () {
    think();
    mtx.lock();
    semaphore.acquire();
    semaphore.acquire();
    mtx.unlock();
    eat();
    mtx.lock();
    semaphore.realease();
    semaphore.realease();
    mtx.unlock();
} 

void thread2 () {
    think();
    mtx.lock();
    semaphore.acquire();
    semaphore.acquire();
    mtx.unlock();
    eat();
    mtx.lock();
    semaphore.realease();
    semaphore.realease();
    mtx.unlock();
}

int main () {
    counting_semaphore<2> semaphore{2};
    mutex mtx;

    thread T1(thread1);
    thread T2(thread2);

    T1.join();
    T2.join();
}