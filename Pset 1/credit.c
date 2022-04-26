#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc = get_long("Number: ");

    long other = cc / 10;
    long rest = cc;
    long start = cc;

    int checksum = 0;
    int length = 0;

    // Calculate the others count
    do
    {
        int otherchar = other % 10;
        if(otherchar * 2 >= 10)
        {
            int digit1 = (otherchar * 2) % 10;
            int digit2 = (otherchar * 2) / 10;
            checksum = checksum + digit1 + digit2;
        }
        else
        {
            checksum = checksum + (otherchar * 2);
        }
        other = other / 100;
        length++;
    }
    while(other > 0);

    // Calculate the rest of the numbers
    do
    {
        int restchar = rest % 10;
        checksum = checksum + restchar;
        rest = rest / 100;
        length++;
    }
    while(rest > 0);

    //Get the first two digits
    do
    {
        start = start / 10;
    }
    while(start > 100);



    if(checksum % 10 == 0)
    {
        if(length == 15 && (start == 34 || start == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            if(length == 16 && (start >= 51 && start <= 55))
            {
                printf("MASTERCARD\n");
            }
            else {
                if((length == 16 || length == 13) && start / 10 == 4) {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }

    return 0;
}

// cc % 10 ==> To get the last number
// cc / 100 ==> To truncate the last number
// other = cc / 10 ==> Because we must start from the previous to the last number
// length ==> To count how many numbers there are in the cc