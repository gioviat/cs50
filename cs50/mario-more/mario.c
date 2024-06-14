#include <cs50.h>
#include <stdio.h>

int get_height(void);
void build_pyramid(int);

int main(void)
{
    int height = get_height();
    build_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

void build_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        int blocks = i + 1;
        int spaces = height - blocks;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
