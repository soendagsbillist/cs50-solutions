#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);

int main(int argc, string argv[])
{
    if(argc < 2)
    {
	printf("Usage: ./plurality candidate1 candidate2 ...");
	return 1;
    }
    else
    {
	candidate_count = argc - 1;
	if(candidate_count > MAX)
	{
	    printf("Maximum number of candidates is %i\n", MAX);
	    return 1;
	}
	for (int i = 0; i < candidate_count; i++)
	{
	    candidates[i].name = argv[i + 1];
	    candidates[i].votes = 0;
	}

	int voter_count = get_int("Give number of voters: ");

	for (int i = 0; i < voter_count; i++)
	{
	    vote(get_string("Vote: "));
	}
	//print_winner();
    }
}

//assume there's no duplication in names of the candidates
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
	if(strcmp(name, candidates[i].name) == 0)
	{
	    candidates[i].votes ++;
	    return true;
	}
    }
    return false;
}
