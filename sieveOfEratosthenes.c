#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    bool* arr = (bool*) malloc((x + 1) * sizeof(bool));
    memset(arr, false, (x + 1) * sizeof(bool));

    for (int i = 2; i * i <= x; i++) {
        if (!arr[i]) {
            for (int j = i * i; j <= x; j += i) {
                arr[j] = true;
            }
        }
    }

    for (int i = 2; i <= x; i++) {
        if (!arr[i]) {
            printf("%d ", i);
        }
    }


    return EXIT_SUCCESS;
}
