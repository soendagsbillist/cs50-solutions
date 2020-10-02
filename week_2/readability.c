/*
  Implementation of the readability program for cs50 pset2,
  that computes the approximate grade level of the given corpus.
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calculate_chars(string text);
int calculate_words(string text);
int calculate_sentences(string text);
void estimate_grade(int letters, int words, int sentences);

int main(int argc, string argv[])
{
    string corpus = get_string("Text: ");
    estimate_grade(calculate_chars(corpus),
		   calculate_words(corpus),
		   calculate_sentences(corpus));
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
	    counter++;
	}
    }
    return counter;
}

int calculate_words(string text)
{
    int counter = 0;
    int len = strlen(text);
    for(int i = 0; i < len; i++)
    {
	if(isspace(text[i]))
	{
	    counter++;
	}
    }
    //n+1 to determine last word that doesn't have white-space after.
    counter++;
    return counter;
}

int calculate_sentences(string text)
{
    int counter = 0;
    int len = strlen(text);
    for(int i = 0; i < len; i++)
    {
	if(ispunct(text[i]) && (text[i] == 46 || text[i] == 33 || text[i] == 63))
	{
	    counter++;
	}
    }
    return counter;
}

void estimate_grade(int letters, int words, int sentences)
{
    float letters_per_hundred = (float) letters / words * 100;
    float sentences_per_hundred = (float) sentences / words * 100;
    float index = 0.0588 * letters_per_hundred - 0.296 * sentences_per_hundred - 15.8;
    if(round(index) > 16)
    {
	printf("Grade 16+\n");
    }
    else if(round(index < 1))
    {
	printf("Before Grade 1\n");
    }
    else
    {
	printf("Grade %.0f\n", round(index));
    }
}
