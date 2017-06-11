#include <stdio.h>

#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crypt key\n");
        return 1;
    }
    char *key = argv[1];
    char *salt = "50";
    char *hash = crypt(key, salt);
    printf("%s\n", hash);
    return 0;
}