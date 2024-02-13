 //PRIME NUMBER  
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    bool prime = isPrime(x);

    if (prime) {
        printf("%d is prime\n", x);
    } else {
        printf("%d is not prime\n", x);
    }

    return EXIT_SUCCESS;
}
