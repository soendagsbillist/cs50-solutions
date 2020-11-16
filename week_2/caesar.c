/*
  Implementation of the caesar cipher for cs50 pset2
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(int letter, int key);

int KEY;
string PLAINTEXT;

int main(int argc, string argv[])
{
    if(argc == 2)
    {
	int len = strlen(argv[1]);
	int counter = 0;
	for(int i = 0; i < len; i++)
	{
	    if(isdigit(argv[1][i]))
	    {
		KEY = atoi(argv[1]);
	    	counter ++;
	    }
	}

	if(counter == len)
	{
	    //key is validated, program can start
	    PLAINTEXT = get_string("plaintext: ");
	    for(int i = 0; i < strlen(PLAINTEXT); i++)
	    {
		shift(PLAINTEXT[i], KEY);
		PLAINTEXT[i] = shift(PLAINTEXT[i], KEY);
	    }
	    printf("ciphertext: %s\n", PLAINTEXT);
	}
	else
	{
	    printf("Usage: ./caesar key\n");
	    return 1;
	}
    }
    else
    {
	printf("Usage: ./caesar key\n");
	return 1;
    }
}

int shift(int letter, int key)
{
    int ciphertext;

    if (isalpha(letter))
    {
	if (letter < 97 && isalpha(letter))
	{
	    ciphertext = (letter + key) % 90;
	    if (ciphertext < 65)
	    {
		return ciphertext = ciphertext + 65 - 1;
	    }
	    else
	    {
		return ciphertext;
	    }
	}
	else
	{
	    ciphertext = (letter + key) % 122;
	    if (ciphertext < 97)
	    {
		return ciphertext = ciphertext + 97 - 1;
	    }
	    else
	    {
		return ciphertext;
	    }
	}
    }
    else
    {
	return letter;
    }
}
