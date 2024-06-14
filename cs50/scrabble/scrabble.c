#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_points(string);

int main(void)
{
    string string1 = get_string("Player 1: ");
    string string2 = get_string("Player 2: ");
    int player1 = count_points(string1);
    int player2 = count_points(string2);
    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2 > player1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int count_points(string word)
{
    int count = 0;
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char letter = toupper(word[i]);
        if (isupper(letter))
        {
            count += points[letter - 'A'];
        }
    }
    return count;
}
