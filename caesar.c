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
        int key = atoi(argv[1]);

        //ask for the user input
        string user_input = get_string("plaintext: ");

        for (int index_count = 0, strlength = strlen(user_input) ; index_count < strlength; index_count++)
        {
            //check the index and see if it's lowercase alphabet betwwen a and z
            if (user_input[index_count] >= 'a' && user_input[index_count] <= 'z')
            {
                //used caesar's algorithm provided with sligh tweak on formula
                printf("%c", (((user_input[index_count] - 'a') + key) % 26) + 'a');
            }
            //check the index and see if it's uppercase alphabet betwwen a and z
            else if (user_input[index_count] >= 'A' && user_input[i] <= 'Z')
            {
                //used caesar's algorithm provided with sligh tweak on formula
                printf("%c", (((user_input[index_count] - 'A') + key) % 26) + 'A');
            }

            else

            {
                printf("%c", user_input[index_count]);
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
