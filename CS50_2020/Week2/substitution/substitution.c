#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


string get_encrypted();
char check_key();


int main(int argc, string argv[])
{

    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    } 

    string stdalpha = "abcdefghijklmnopqrstuvwxyz";
    string keyalpha = argv[1];

    if (strlen(keyalpha) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(check_key(stdalpha, keyalpha) == 'f')
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    string plaintext = "HeLoo, BOI nono.";

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");

    get_encrypted(stdalpha, keyalpha, plaintext);
}


string get_encrypted(char in_alpha[], char in_key[], char in_phrase[])
{
    for (int i = 0; in_phrase[i] != '\0'; i++)
    {
        if(isalpha(in_phrase[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if(tolower(in_phrase[i]) == tolower(in_alpha[j]))
                {
                    if(islower(in_phrase[i]))
                    {
                        printf("%c", tolower(in_key[j]));
                    }
                    else
                    {
                        printf("%c", toupper(in_key[j]));
                    }
                }         
            }
        }
        else
        {
            printf("%c", in_phrase[i]);
        }
    }

    printf("\n");

    return in_phrase;
}

char check_key(string in_key, string in_alpha)
{
    for(int i = 0; i < 26; i++)
    {
        char temp = 'f';
        for(int j = 0; j < 26; j++)
        {
            if(in_alpha[i] == in_key[j])
            {
                temp = 't';
            }
        }
        if(temp == 'f')
        {
            return 'f';
        }
    }    

    return 't';
}