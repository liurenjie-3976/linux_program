#include <stdlib.h>
#include <stdio.h>

extern char **environ;
int main() {
    char **var;
    for (var = environ; *var != NULL; ++var) {
        printf("%s\n", *var);
    }
    exit(0);
}