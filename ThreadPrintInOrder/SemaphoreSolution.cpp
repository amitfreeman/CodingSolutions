#include <semaphore.h>

class Foo {
    sem_t firstSem;
    sem_t secondSem;
    
public:
    Foo() {
        sem_init(&firstSem, 0, 0);
        sem_init(&secondSem, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstSem);  //publish that first is finished
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstSem);  //wait for firstSem
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondSem);  //publish that second is finished
    }

    void third(function<void()> printThird) {
        sem_wait(&secondSem);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};