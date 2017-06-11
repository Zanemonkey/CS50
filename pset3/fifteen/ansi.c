#include <stdio.h>

int main (void)
{
    for (int i = 30; i < 50; i++)
    {
        if (i != 38 && i != 48)
        {
            printf("\033[%imTesting %i\n", i, i);
        }
    }
    
  
    
    return 0;
}