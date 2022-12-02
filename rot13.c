#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    if(argc <=1){

        return -1;
    }

    char *current_char = argv[1];

    while (*current_char != '\0')
    {
        if(isalpha(*current_char))
        // if ((*current_char >= 97 && *current_char <= 122) || (*current_char >= 65 && *current_char <= 90))
        {
            if (*current_char > 109 || (*current_char > 77 && *current_char < 91))
            {
                // putchar(*current_char - 13);
                printf("%c", *current_char - 13);
            }
            else
            {
                // putchar(*current_char + 13);
                printf("%c", *current_char + 13);

            }
        }
        else
        {
            // putchar(*current_char);
            printf("%c", *current_char);

        }
        current_char++;
    }

    printf("\n");
    return 0;
}