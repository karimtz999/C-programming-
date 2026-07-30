#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        if (i == 2) {
            printf("Skipping iteration when i is 2\n");
            continue;
        }
        printf("Hello, World!\n");
    }
    return 0;
}