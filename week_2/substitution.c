/*
  Implementation of the substitution cipher for cs50 pset2
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool validate_key(string key);

#define ALPH_LEN 26

int main(int argc, string argv[])
{
    if(argc == 2)
    {
	if(validate_key(argv[1]))
	{
	    string plaintext = get_string("plaintext: ");
	}
    }
    else
    {
	printf("Key must contain 26 characters.\n");
	return 1;
    }
}


bool validate_key(string key)
{
    int validated_key[ALPH_LEN];
    int counter;

    if(strlen(key) != ALPH_LEN)
    {
	printf("Key must contain 26 characters.\n");
	return false;
    }
    else
    {
	for (int i=0; i < ALPH_LEN; i++)
	{
	    counter = 0;
	    for (int j=0; j < ALPH_LEN; j++)
	    {
		if(validated_key[j] == key[i])
		{
		    printf("Key must not contain repeated characters.\n");
		    return false;
		}
		else
		{
		    counter ++;
		    if(counter == ALPH_LEN - 1) // zero indexed alphabet would have length 25
		    {
			validated_key[i] = key[i];
			break;
		    }
		}
	    }

	}

	int len = sizeof(validated_key) / sizeof(validated_key[0]);
	for (int i = 0; i < len; i ++)
	{
	    if(!isalpha(validated_key[i]))
	    {
		printf("%i\n", validated_key[i]);
		printf("Key must contain only letters.\n");
		return false;
	    }
	}
    }
    return true;
}
