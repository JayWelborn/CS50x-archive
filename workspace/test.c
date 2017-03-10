#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("incorrect usage\n");
        return 1;
    }
    
    char* test = argv[1];
    char* copytest = malloc(sizeof(test));
    
    for (int i = 0; i < strlen(test); i++)
    {
        copytest[i] = test[i];
        printf("%c = %c\n", test[i], copytest[i]);
    }
    
    free(copytest);
    return 0;
}