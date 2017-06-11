#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // ensure user has passed in key as command-line argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    // set up key length and cursor variables
    char* key = argv[1];
    int key_length = strlen(key);
    int key_cursor = 0;
    
    // check that key consists entirely of alphabetic characters
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key can only contain alphabetic characters\n");
            return 1;
        }
    }
    
    // prompt for plaintext
    printf("plaintext: ");
    char* p = get_string();
    int p_length = strlen(p);
    char c[p_length];
    int k, l;
    char base;
    
    printf("ciphertext: ");
    
    // iterate through plaintext characters
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // if character is alphabetic, shift it by the current key character
        if (isalpha(p[i]))
        {
            // derive a zero-based index for the current key character
            k = (tolower(key[key_cursor]) - 'a');
            
            // determine the base character (upper or lower 'a') and zero-based index for current plaintext character
            if (islower(p[i]))
            {
                base = 'a';
                l = p[i] - base;
            } else
            {
                base = 'A';
                l = p[i] - base;
            }
            
            
            int offset = (k + l) % 26;
            
            c[i] =  base + offset;
            key_cursor++;
            if (key_cursor >= key_length) { key_cursor = 0; }
            
            
        } else
        {
            // pass through non-alphabetic characters unchanged
            c[i] = p[i];
        }
        //print out i'th enciphered character
        printf("%c", c[i]);
    }
    
    printf("\n");
    return 0;
    
}
    
    
    
        
        
        
