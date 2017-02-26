#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <task.h>

enum {
    STACK = 32768
};

#define MAX_ARGS 100
int args_values[MAX_ARGS];

Channel *c;

void
delaytask(void *v) {
    taskdelay(*(int*) v);
    printf("awake after %d ms\n", *(int*) v);
    chansendul(c, 0);
}

void
taskmain(int argc, char **argv) {
    int i, n;

    c = chancreate(sizeof (unsigned long), 0);

    n = 0;
    for (i = 1; i < argc; i++) {
        n++;
        printf("x");
        args_values[i] = atoi(argv[i]);
        taskcreate(delaytask, (void*) &args_values[i], STACK);
        if (i < MAX_ARGS)
            break;
    }

    /* wait for n tasks to finish */
    for (i = 0; i < n; i++) {
        printf("y");
        chanrecvul(c);
    }
    taskexitall(0);
}
