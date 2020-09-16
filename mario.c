#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do{
        height = get_int("How tall do you want the brick to be? ");
    }
    while (height<1 || height>8);

    //For Rows
    for (int rows = 0; rows < height; rows++){
        //This is for gap space before #
        for (int j = 0; j < height - rows - 1; j++)
        {
                printf(" ");

        }
            //This is for column
            for (int column = 0; column <= rows; column++)
            {
                printf("#");

            }
            printf("\n");
    }
}