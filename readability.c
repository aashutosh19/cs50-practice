#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

    string text = get_string("Text: ");

    int characters = 0;
    int words = 1;
    int sentence = 0;

    for (int i = 0, count = strlen(text); i < count; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            characters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }

    printf("letters: %i; words: %i; sentences: %i\n", characters, words, sentence);

    //index = 0.0588 * L - 0.296 * S - 15.8

    float index = (0.0588 * (100 * (float)(characters)) / (float)(words))  - 0.296 * (100 * (float)(sentence) / (float)(words)) - 15.8;

    if (index < 16 && index >= 1)
    {
        printf("Grade %i\n", (int)(round)index);
    }
    else if (index >= 16)
    {
        printf("Grade 16 + ");
    }
    else
    {
        printf("Before Grade 1");
    }
    printf("\n");
}