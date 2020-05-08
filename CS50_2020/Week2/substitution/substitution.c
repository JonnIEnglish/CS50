#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


string get_encrypted();
char check_key();


int main(int argc, string argv[])
{

    //checks that user entered an encryption key
    if (argc != 2)    
    {
        printf("Usage: ./substitution key\n");
        return 1;
    } 

    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string key = argv[1];

    //checks that user entered key is 26 letters
    if (strlen(key) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //checks that user entered key conatains all letters in the alphabet
    if (check_key(alpha, key) == 'f')
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    //string plaintext = get_string("plaintext: ");
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    get_encrypted(alpha, key, plaintext);
}


//the function that encrypts the entered phrase using the entered key
string get_encrypted(char in_alpha[], char in_key[], char in_phrase[])
{
    for (int i = 0; in_phrase[i] != '\0'; i++)
    {
        if (isalpha(in_phrase[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (tolower(in_phrase[i]) == tolower(in_alpha[j]))
                {
                    if (islower(in_phrase[i]))
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


char check_key(string in_alpha, string in_key)
{
    char a;
    char k;

    for (int i = 0; i < 26; i++)
    {
        char temp = 'f';
        for (int j = 0; j < 26; j++)
        {
            a = tolower(in_alpha[i]);
            k = tolower(in_key[j]);
            if (a == k)
            {
                temp = 't';
            }
        }
        if (temp == 'f')
        {
            return 'f';
        }
    }    

    return 't';
}