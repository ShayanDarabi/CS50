#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get an integer between 0 and 8 from the user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);
    
    // The main loop for printing the pyramid
    for (int row = 1; row <= height; row++)
    {
        for (int col = 1; col <= height - row; col++)
        {
            printf(" ");
        }
        // number of hashes that should be printed in each row
        int number_of_hash = 0;

        while (number_of_hash < row)
        {
            printf("#");
            number_of_hash++;
        }
        printf("\n");
    }
}