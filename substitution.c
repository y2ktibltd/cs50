#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    int i, j, l;
    char c, k;
    char key[26];
    char alpha[26] = "abcdefghijklmnopqrstuvwxyz";
    for (i = 0, l = strlen(argv[1]); i < l; i++)
    {
        c = argv[1][i];
        if (isupper(c))
        {
            //printf("uppercase key: %c\n",c);
            key[i] = c + 32;
        }
        else if (islower(c))
        {
            key[i] = c;
        }
        else if (!isalpha(c))
        {
            printf("Must use alphabet in key only!\n");
            return 1;
        }
    }
    for (i = 0, l = strlen(argv[1]); i < l; i++)
    {
        c = argv[1][i];
        for (j = 0, l = strlen(argv[1]); j < l; j++)
        {
            k = argv[1][j];
            if (c == k && i != j)
            {
                printf("Duplicates found in key!\n");
                return 1;
            }
        }

    }
    char plain[50];
    printf("plaintext : ");
    fgets(plain, 50, stdin);
    //printf("\n");
    //printf("%s\n",plain);
    int len = strlen(plain);
    //printf("length of phrase: %d\n",len);
    char cipher[len];
    int p = 0;
    strcpy(cipher, plain);
    for (i = 0; i < len; i++)
    {
        if (cipher[i] > 64 && cipher[i] < 91)
        {
            //printf("Uppercase %c:%d found at pos:%d!\t", cipher[i], cipher[i],i);
            while ((cipher[i]) + 32 != alpha[p])
            {
                p++;
            }
            //printf("%c becomes %c at position:%d\n",(cipher[i])+32,key[p],i);
            cipher[i] = (key[p]) - 32;
            p = 0;
        }
        else if (cipher[i] > 96 && cipher[i] < 123)
        {
            //printf("Lowercase %c:%d found at pos:%d!\t", cipher[i], cipher[i],i);
            while (cipher[i] != alpha[p])
            {
                p++;
            }
            //printf("%c becomes %c at position:%d\n",cipher[i],key[p],i);
            cipher[i] = key[p];
            p = 0;
        }
    }
    printf("ciphertext: ");
    printf("%s \n", cipher);
    //printf("alpha: %s\n", alpha);
    //printf("key  : %s\n", key);
    return 0;
}
