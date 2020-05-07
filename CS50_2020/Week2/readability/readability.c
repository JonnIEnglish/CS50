#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>


int count_letters();
int count_sentences();
int count_words();
double calc_readability();


int main(void)
{

    //string phrase = get_string("Text: ");
    string phrase = "";
    double letters = count_letters(phrase);
    //printf("Number of letters: %f\n\n", letters);
    double sentances = count_sentences(phrase);
    //printf("Number of Sentances: %f\n", sentances);
    double words = count_words(phrase);
    //printf("Number of words: %f\n", words);
    double col_index = (calc_readability(letters, words, sentances));
    
    if (col_index >= 16)
    {       
        printf("Grade 16+\n");
    }
    else if (col_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", col_index);
    }
    
}


int count_letters(string in_phrase)
{
    int counter = 0;

    for (size_t i = 0; in_phrase[i] != '\0'; i++)
    {
        if (isalpha(in_phrase[i]))
        {
            counter++;
            //printf("%c", in_phrase[i]);
        }
        
    }

    //printf("\n");

    return counter;   
    
}

int count_sentences(string in_phrase)
{
    int counter = 0;

    for (size_t i = 0; in_phrase[i] != '\0'; i++)
    {
        if (in_phrase[i] == '.' || in_phrase[i] == '?' || in_phrase[i] == '!')
        {
            counter++;
            //printf("%c", in_phrase[i]);
        }
        
    }

    //printf("\n");

    return counter;

}

int count_words(string in_phrase)
{
    int counter = 0;

    for (size_t i = 0; in_phrase[i] != '\0'; i++)
    {
        if (in_phrase[i] == ' ')
        {
            counter++;
            //printf("%c", in_phrase[i]);
        }
        
    }

    //printf("\n");

    return counter + 1;

}


double calc_readability(double letters, double words, double sentences)
{
    //printf("L: %f\n", letters);
    //printf("W: %f\n", words);
    //printf("S: %f\n", sentences);

    double l = letters / words * 100.0;
    //printf("l: %f\n", l);
    double s = sentences / words * 100.0;
    //printf("s: %f\n", s);
    double index = (0.0588 * l) - (0.296 * s) - 15.8;
    //printf("index: %f\n", index);

    return index;
}








