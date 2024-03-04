#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAXN = 1000;

char* caesar_cipher(char* str, int key) {
    int length = strlen(str);
    char* cipher = (char*)malloc(sizeof(char) * (length + 1));

    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            char base = (str[i] >= 'A' && str[i] <= 'Z') ? 'A' : 'a';
            cipher[i] = ((str[i] - base + key) % 26) + base;
        } else if (str[i] == ' ') {
            // Preserve spaces
            cipher[i] = ' ';
        } else {
            // Encrypt special symbols directly
            cipher[i] = str[i] + key;
        }
        i++;
    }
    cipher[i] = '\0';

    return cipher;
}

char* caesar_decrypt(char* cypher, int key) {
    int length = strlen(cypher);
    char* str = (char*)malloc(sizeof(char) * (length + 1));

    int i = 0;
    while (cypher[i] != '\0') {
        if ((cypher[i] >= 'A' && cypher[i] <= 'Z') || (cypher[i] >= 'a' && cypher[i] <= 'z')) {
            char base = (cypher[i] >= 'A' && cypher[i] <= 'Z') ? 'A' : 'a';
            str[i] = ((cypher[i] - base - key + 26) % 26) + base;
        } else if (cypher[i] == ' ') {
            // Preserve spaces
            str[i] = ' ';
        } else {
            // Decrypt special symbols directly
            str[i] = cypher[i] - key;
        }
        i++;
    }
    str[i] = '\0';

    return str;
}

int read_cypher(char* filename, char* cypher) {
    FILE* file;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return EXIT_FAILURE;
    }

    if (fgets(cypher, MAXN, file) == NULL) {
        printf("Error reading from file.\n");
        return EXIT_FAILURE;
    }

    fclose(file);

    return EXIT_SUCCESS;
}

int main() {
    char str[MAXN];

    printf("Enter text to encrypt: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    char* cipher = caesar_cipher(str, key);

    printf("\nEncrypted Text:\n%s\n", cipher);

    char* result = caesar_decrypt(cipher, key);
    printf("\nDecrypted Text:\n%s\n", result);

    char filename[MAXN];
    printf("\nEnter filename: ");
    scanf("%s", filename);

    char file_cypher[MAXN];

    if (read_cypher(filename, file_cypher) == EXIT_SUCCESS) {
        int key;
        printf("Enter key:");
        scanf("%d", &key);

        char* result1 = caesar_cipher(file_cypher, key);

        printf("\nEncrypted text:\n%s\n", result1);

        char* result2 = caesar_decrypt(result1, key);
        printf("\nDecrypted text:\n%s\n", result2);

        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

