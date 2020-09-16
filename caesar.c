#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {
        //to convert the user input to an integer
        int k = atoi(argv[1]);

        //ask for the user input
        string s = get_string("plaintext: ");

        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            //check the index and see if it's lowercase alphabet betwwen a and z
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                //used caesar's algorithm provided with sligh tweak on formula
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a');
            }
            //check the index and see if it's uppercase alphabet betwwen a and z
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                //used caesar's algorithm provided with sligh tweak on formula
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A');
            }

            else

            {
                printf("%c", s[i]);
            }
        }

        printf("\n");

        return 0;
    }

    else

    {
        //exit program printing below if line9 doesnt satisfy
        printf("Usage: ./ caesar key \n");

        return 1;
    }
}