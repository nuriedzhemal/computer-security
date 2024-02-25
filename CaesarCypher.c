//Cesar Cypher
#include <stdlib.h>

#include <stdio.h>

void encrypt(char str[], int key)
{
    for (int i =0; str[i] !='\n' && str[i] != '\0'; i++){

        char current = str[i];

        if('A'<= current && current <='Z')

        str[i] = 'A'+ (current - 'A' + key)%26;

    }

}

int main()
{

   char str[100];
  
 int key;
   
 printf("Enter text: ");
   
 scanf("%s", &str);
   
 printf("Enter key value: ");
  
  scanf("%d", &key);
    
    
encrypt(str, key);
   
 printf("Encrypted text: %s\n", str);

    
    return EXIT_SUCCESS;

}
