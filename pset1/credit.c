#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
    long long number;
    int i;
    int sum_double = 0;
    int sum_other = 0;
    long long cursor;
    
    printf("Number: ");
    number = get_long_long();
    long long length = floor(log10(llabs(number))) + 1;
    int digits[length];
    
    // split credit card number into an array of individual digits
    for (i = 0, cursor = 1; i < length; i++, cursor *= 10)
    {
        digits[i] = (int) ( (number / cursor) % 10); 
    }
    
    // sum doubles of every second digit with every other digit
    int doubled;
    for (i = 1; i <= length; i += 2)
    {
        if (i < length) 
        {
            doubled = digits[i] * 2;
            if (doubled > 9)
            {
                sum_double += (1 + doubled % 10);
            } else
            {
                sum_double += doubled;
            }
        }
       
        sum_other += digits[i - 1];
    }
    
    int checksum = sum_double + sum_other;

    // check checksum and signature starting digits and output card validity and type
    if (checksum % 10 == 0) 
    {
        if (digits[length - 1] == 4)
        {
            printf("VISA\n");
        } else if (digits[length - 1] == 5 && digits[length - 2] >= 1 && digits[length - 2] <= 5 )
        {
            printf("MASTERCARD\n");
        } else if (digits[length - 1] == 3 && ( digits[length - 2] == 4 || digits[length - 2] == 7) )
        {
            printf("AMEX\n");
        } else
        {
            printf("INVALID\n");
        }
    } else 
    {
        printf("INVALID\n");
    }
    
    return 0;
}