#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

long get_number(void);
int count_digits(long);
long reduce_number(long, int);
bool check_card(long);
bool check_amex(long);
bool check_visa(long);
bool check_mastercard(long);

int main(void)
{
    long number = get_number();
    bool flag = false, amex = false, visa = false, mastercard = false;
    flag = check_card(number);
    amex = check_amex(number);
    visa = check_visa(number);
    mastercard = check_mastercard(number);
    if (flag && amex)
    {
        printf("AMEX\n");
    }
    else if (flag && visa)
    {
        printf("VISA\n");
    }
    else if (flag && mastercard)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    return number;
}

int count_digits(long number)
{
    int digits = 0;
    while (number != 0)
    {
        number /= 10;
        digits++;
    }
    return digits;
}

long reduce_number(long number, int digits)
{
    for (int i = 0; i < digits; i++)
    {
        number /= 10;
    }

    return number;
}

bool check_card(long number)
{
    int sum1 = 0, sum2 = 0;
    bool flag = false;
    int check;
    while (number > 0)
    {
        sum1 += number % 10;
        number /= 10;
        check = (number % 10) * 2;
        if (check >= 10)
        {
            sum2 += (check % 10) + check / 10;
        }
        else
        {
            sum2 += check;
        }
        number /= 10;
    }
    if ((sum1 + sum2) % 10 == 0)
    {
        flag = true;
    }
    return flag;
}

bool check_amex(long number)
{
    int digits = count_digits(number);
    bool flag = false;
    if (digits == 15)
    {
        long start = reduce_number(number, digits - 2);
        if (start == 34 || start == 37)
        {
            flag = true;
        }
    }
    return flag;
}

bool check_visa(long number)
{
    int digits = count_digits(number);
    bool flag = false;
    if (digits == 13 || digits == 16)
    {
        long start = reduce_number(number, digits - 1);
        if (start == 4)
        {
            flag = true;
        }
    }
    return flag;
}

bool check_mastercard(long number)
{
    int digits = count_digits(number);
    bool flag = false;
    if (digits == 16)
    {
        long start = reduce_number(number, digits - 2);
        if (start >= 51 && start <= 55)
        {
            flag = true;
        }
    }
    return flag;
}
