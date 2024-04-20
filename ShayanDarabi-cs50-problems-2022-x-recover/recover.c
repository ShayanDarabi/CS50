#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int file_number = -1;
char recovered[1000];

int main(int argc, char *argv[])
{
    if (argc == 1 | argc > 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = NULL;
    BYTE buffer[512];
    while (fread(buffer, sizeof(buffer), 1, f))
    {
        // detect new input header
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) &&
            (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {

            // close previous output stream
            if (output != NULL)
                fclose(output);

            // open new output stream
            file_number++;
            sprintf(recovered, "%03d.jpg", file_number);
            output = fopen(recovered, "w");
            if (output == NULL)
            {
                printf("Could not create file %03d/n", file_number);
                return 1;
            }
        }
        // write data to output stream
        // this writes both the header and data for a given output file
        if (output != NULL)
            fwrite(buffer, sizeof(buffer), 1, output);
    }

    // close the last output stream
    if (output != NULL)
        fclose(output);

    fclose(f);

    return 0;
}