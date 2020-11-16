/*
  Implementation of the caesar cipher for cs50 pset2
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
