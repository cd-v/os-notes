#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void func_call() {
    int x = 10;
}

int main() {
    float time1 = 0.0f, time2 = 0.0f;

    // Procedure call
    for (size_t i=0; i<10000; i++) {
        float start = (float)clock() / CLOCKS_PER_SEC;
        func_call();
        float finish = (float)clock() / CLOCKS_PER_SEC;
        float time = finish - start;
        time1 = time1 + time;
    }

    time1 = time1 / 10000.0f;
    printf("Procedure call time - avg. (ms): %.9f\n", time1);

    // System call
    for (size_t i=0; i<10000; i ++) {
        float start = (float)clock() / CLOCKS_PER_SEC;
        int x = getpid();
        float finish = (float)clock() / CLOCKS_PER_SEC;
        float time = finish - start;
        time2 = time2 + time;
    }

    time2 = time2 / 10000.0f;
    printf("System call time - avg. (ms): %.9f\n", time2);
}
