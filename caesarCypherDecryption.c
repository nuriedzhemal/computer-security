#include <stdlib.h>
#include <stdio.h>

void decrypt(char cypher[], int key)
{
    for (int i =0; cypher[i] !='\n' && cypher[i] != '\0'; i++){
        char current = cypher[i];
        if('A'<= current && current <='Z')
        cypher[i] = 'A'+ (current - 'A' - key)%26;

    }

}

int main(){

   char cypher[100];
   int key;
   
 printf("Enter text: ");
 scanf("%s", cypher);
 printf("Enter key value: ");
 scanf("%d", &key);
    
    
  decrypt(cypher, key);
 printf("Decrypted text: %s\n", cypher);

    return EXIT_SUCCESS;

}

