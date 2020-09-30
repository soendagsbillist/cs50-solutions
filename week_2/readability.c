/*
  Implementation of the readability program for cs50 pset2
  It computes the approximate grade lelev of the given corpus
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int calculate_chars(string text);

int main(int argc, string argv[])
{
	string corpus = get_string("Text: ");
	calculate_chars(corpus);
}

//String -> Int
int calculate_chars(string text)
{
	int counter = 0;
	int len = strlen(text);
	for(int i = 0; i < len; i++)
	{
		if(isalpha(text[i]))
		{
			int letter = text[i];
			counter++;
		}
	}
	printf("%i", counter);
	return counter;
}
