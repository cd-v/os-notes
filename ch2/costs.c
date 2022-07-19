#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void func_call() {
    int x = 10;
}

float time_call(int type_bit) {
    float avg_time = 0;
    int x;

    for (size_t i=0; i<10000; i++) {
        float start = (float) clock() / CLOCKS_PER_SEC;
        if (type_bit) func_call();
        else x = getpid();
        float finish = (float) clock() / CLOCKS_PER_SEC;
        float time = finish - start;
        avg_time += time;
    }

    return (avg_time / 10000.0f);
}

int main() {
    // Procedure call
    float time1 = time_call(1);
    printf("Procedure call time - avg. (ms): %.9f\n", time1);

    // System call
    float time2 = time_call(0);
    printf("System call time - avg. (ms): %.9f\n", time2);
}
