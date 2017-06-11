#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <unistd.h>
#include <cs50.h>

#define SALT "50"
#define MAX_LEN 4
#define ABC_LEN 26

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }
    
    char guess[MAX_LEN];
    
    for (int i = 0; i < MAX_LEN; i++)
    {
        for (int j = 0; j < i; j++)
        {
               
        }
        
    }
    
    for (int i = 0; i < ABC_LEN; i++)
    {
        
        
        guess[0] = 'a' + i;
        if (strcmp(argv[1], crypt(&guess[0], "50")) == 0)
        {
            printf("%s\n", guess);
            return 0;
        }
        guess[0] = 'A' + i;
        if (strcmp(argv[1], crypt(&guess[0], "50")) == 0)
        {
            printf("%s\n", guess);
            return 0;
        }
    }
    return 0;
    
}
