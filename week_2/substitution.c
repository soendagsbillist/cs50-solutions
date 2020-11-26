/*
  Implementation of the substitution cipher for cs50 pset2
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ALPH_LEN 26

bool validate_key(string key);
void substitute(string txt, string key);


int main(int argc, string argv[])
{
    if(argc == 2)
    {
	if(validate_key(argv[1]))
	{
	    string plaintext = get_string("plaintext: ");
	    substitute(plaintext, argv[1]);
	    return 0;
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
	for (int i = 0; i < ALPH_LEN; i++)
	{
	    counter = 0;
	    for (int j = 0; j < ALPH_LEN; j++)
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
	for (int i = 0; i < len; i++)
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

void substitute(string txt, string key)
{
    int upper[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		     80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
    int lower[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
		     110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
		     122};

    for (int i = 0; i < strlen(txt); i++)
    {
	if(txt[i] <= 90 && txt[i] >= 65)
	{
	    for (int j = 0; j < 26; j++)
	    {
		if(txt[i] == upper[j])
		{
		    txt[i] = toupper(key[j]);
		    break;
		}
	    }
	}
	else if (txt[i] <= 122 && txt[i] >= 97)
	{
	    for (int j = 0; j < 26; j++)
	    {
		if(txt[i] == lower[j])
		{
		    txt[i] = tolower(key[j]);
		    break;
		}
	    }
	}
    }
    printf("ciphertext: %s\n", txt);
}
