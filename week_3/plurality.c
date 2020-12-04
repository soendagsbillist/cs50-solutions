#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int main(int argc, string argv[])
{
    if(argc < 2)
    {
	printf("Usage: ./plurality candidate1 candidate2 ...");
	return 1;
    }
    else
    {
	int candidate_count = argc - 1;
	if(candidate_count > MAX)
	{
	    printf("Maximum number of candidates is %i\n", MAX);
	    return 1;
	}
	printf("%i", candidate_count);
	for (int i = 0; i < candidate_count; i++)
	{
	    candidates[i].name = argv[i + 1];
	    candidates[i].votes = 0;
	}

	int voter_count = get_int("Give number of voters: ");

	for (int i = 0; i < voter_count; i++)
	{
	    string vote = get_string("Vote: ");
	    //vote(vote);
	}
	//print_winnter();
    }
}
