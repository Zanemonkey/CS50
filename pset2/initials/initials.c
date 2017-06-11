#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string name = get_string();
    int spaceflag = 1;
    char initials[strlen(name)];
    int cursor = 0;

    for (int i = 0; i < strlen(name); i++)
    {
        
        switch (name[i])
        {
            case 32:
                spaceflag = 1;
                break;
            default:
                if (spaceflag == 1)
                {
                    if (name[i] >= 97 && name[i] <= 122)
                    {
                        initials[cursor] = toupper(name[i]);
                        cursor++;
                    } else if (name[i] >= 65 && name[i] <= 90)
                    {
                        initials[cursor] = name[i];
                        cursor++;
                    }
                    spaceflag = 0;
                }
        }
        
        
    }
    
    for (int i = 0; i < cursor; i++)
    {
        printf("%c", initials[i]);
    }
    
    printf("\n");
    
    return 0;
}