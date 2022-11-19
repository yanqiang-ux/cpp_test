#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>


void print_backtrace() {
    void *buffer[3];
    char **symbols;

    int num = backtrace(buffer, 3);
    printf("backtrace() returned %d addresses\n", num);

    symbols = backtrace_symbols(buffer, num);
    if (symbols == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < num; j++)
        printf("%s\n", symbols[j]);

    free(symbols);
}


void myfunc3() {
    print_backtrace();
}

void myfunc2() {
    myfunc3();
}

void myfunc1() {
    myfunc2();
}

int main() {
    myfunc1();
}

