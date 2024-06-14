#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check_key(string);
string encrypt(string, string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }
    string key = argv[1];
    bool flag = check_key(key);
    if (flag == 1)
    {
        printf("Key must contain 26 characters\n");

        return 1;
    }
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(key, plaintext);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool check_key(string key)
{
    bool flag = 0;
    int len = strlen(key);
    if (len != 26)
    {
        flag = 1;

        return flag;
    }
    for (int i = 0; i < len; i++)
    {
        if (!(isalpha(key[i])))
        {
            flag = 1;

            return flag;
        }
        for (int j = i + 1; j < len; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                flag = 1;

                return flag;
            }
        }
    }

    return flag;
}

string encrypt(string key, string plaintext)
{
    int len = strlen(plaintext);
    string ciphertext = plaintext;
    for (int i = 0; i < len; i++)
    {
        char c = plaintext[i];
        if (islower(c))
        {
            ciphertext[i] = (char) tolower(key[c - 97]);
        }
        else if (isupper(c))
        {
            ciphertext[i] = (char) toupper(key[c - 65]);
        }
    }

    return ciphertext;
}
