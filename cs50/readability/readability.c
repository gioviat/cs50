#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_words(string);
int count_letters(string);
int count_sentences(string);

int main(void)
{
    string text = get_string("Text: ");
    int words = count_words(text);
    printf("Words: %i\n", words);
    int letters = count_letters(text);
    int sentences = count_sentences(text);
    float l = (float) letters / (float) words * 100.0;
    float s = (float) sentences / (float) words * 100.0;
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char c = text[i];
        if (c == ' ')
        {
            count++;
        }
    }
    count++;

    return count;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            count++;
        }
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?')
        {
            count++;
        }
    }

    return count;
}
