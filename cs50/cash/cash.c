#include <cs50.h>
#include <stdio.h>

int get_change(void);
int min_coins(int);

int main(void)
{
    int change = get_change();
    int coins = min_coins(change);
    printf("%i\n", coins);
}

int get_change(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    } while (change < 0);

    return change;
}

int min_coins(int change)
{
    const int quarters = 25;
    const int dimes = 10;
    const int nickels = 5;
    const int pennies = 1;

    int coins = 0;

    while (change > 0)
    {
        if (change >= quarters)
        {
            change -= quarters;
            coins++;
        } else if (change >= dimes)
        {
            change -= dimes;
            coins++;
        }
        else if (change >= nickels)
        {
            change -= nickels;
            coins++;
        } else
        {
            change -= pennies;
            coins++;
        }
    }

    return coins;
}
