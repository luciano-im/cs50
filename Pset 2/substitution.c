#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  // Checking we receive just one parameter
  if(argc != 2) {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  string c = argv[1];

  // Checking length
  if(strlen(c) != 26)
  {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  // Checking alpha condition
  for(int i = 0; i < strlen(c); i++){
    if(!isalpha(c[i]))
    {
      printf("Just letters are allowed.\n");
      return 1;
    }
  }

  // Checking repeated letters
  for(int i = 0; i < strlen(c)-1; i++)
  {
    for(int j = i + 1; j < strlen(c); j++)
    {
      if(toupper(c[i]) == toupper(c[j]))
      {
        printf("Repeated characters are not allowed.\n");
        return 1;
      }
    }
  }

  string message = get_string("plaintext: ");
  string a = "ABCDEFGHIJKLMNOPQRSTUVWYXZ";

  printf("ciphertext: ");

  for(int i = 0; i < strlen(message); i++)
  {
    // k validates if a characted was encrypted
    int k = 0;
    for(int j = 0; j < strlen(a); j++)
    {
      if(toupper(message[i]) == toupper(a[j]))
      {
        if(islower(message[i]))
        {
          printf("%c", tolower(c[j]));
        }
        else
        {
          printf("%c", toupper(c[j]));
        }
        k = 1;
        break;
      }
    }

    // If a character wasn't encrypted print the original character
    if(k == 0)
    {
      printf("%c", message[i]);
    }
  }
  printf("\n");
  return 0;
}