#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int iter = 0;
    int c;

    do {
      c = get_int("Height: ");
    }
    while(c < 1 || c > 8);

    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < c - i - 1; j++) {
          printf(" ");
          iter++;
        }

        for(int k = 0; k < c - iter; k++) {
          printf("#");
        }

        iter = 0;
        printf("  ");

        for(int l = 0; l < i + 1; l++) {
          printf("#");
        }

        printf("\n");
    }
}