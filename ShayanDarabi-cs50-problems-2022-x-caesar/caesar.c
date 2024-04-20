#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 0 || argc > 2 || argv[1] == NULL)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // converting the argv[1] to the integer
    int k = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        char encoded_char = rotate(plain_text[i], k);
        printf("%c", encoded_char);
    }
    printf("\n");
    return 0;
}

// only_digits function checks if the inputed argument is an integer or not
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

// rotate function encode every character of plain text
char rotate(char c, int n)
{
    if (isalpha(c) > 0)
    {
        if (isupper(c) > 0)
        {
            char character = c - 65;
            int index = (character + n) % 26;
            char encoded_char = index + 65;
            return encoded_char;
        }
        else
        {
            char character = c - 97;
            int index = (character + n) % 26;
            char encoded_char = index + 97;
            return encoded_char;
        }
    }
    else
    {
        return c;
    }
}