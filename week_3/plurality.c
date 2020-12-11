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
void print_winner(candidate cands[]);

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
	print_winner(candidates);
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

void print_winner(candidate cands[])
{
    int key, j;
    candidate swap_candidate;

    for (int i = 1; i < candidate_count; i++)
    {
    	key = cands[i].votes;
	swap_candidate = cands[i];
    	j = i - 1;
    	while(j >= 0 && cands[j].votes > key)
    	{
    	    cands[j+1] = cands[j];
    	    j -= 1;
    	}
	cands[j+1].votes = key;
	cands[j+1] = swap_candidate;
    }

    int winner_position = candidate_count - 1;

    for(int i = winner_position; i >= 0; i--)
    {
	int winner_score = cands[winner_position].votes;
	//check the first place with second
	if(winner_score != cands[winner_position - 1].votes)
	{
	    printf("the only one winner is: %s\n", cands[winner_position].name);
	    return;
	}
	else if(winner_score == cands[i].votes && strcmp(cands[winner_position].name, cands[i].name) != 0)
	{
	    printf("tie");
	}
    }
}
