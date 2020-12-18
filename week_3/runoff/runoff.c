#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
	if(strcmp(name, candidates[i].name) == 0)
	{
	    // updates preferences array with the index of the
	    // candidate[j'th in preferences[i][j]] voter voted for
	    // so if there are 3 candidates to vote for, and first voter (preferences[0][j])
	    // votes for the last candidate -> preferences[0][2], then first one -> [0][2,0],
	    // then the second one [0][2,0,1]. In the main() program iterates over the
	    // preferences[i][j] and vote() essentially updates the preferences of the
	    // each voter (i'th in preferences[i][j])
	    preferences[voter][rank] = i;
	    return true;
	}
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
	for (int j = 0; j < candidate_count; j++)
	{
	    if (candidates[preferences[i][j]].eliminated == false)
	    {
	    	candidates[preferences[i][j]].votes++;
	    	break;
	    }
	}
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
	if(candidates[i].votes > (voter_count / 2))
	{
	    printf("candidate %s with %i votes  won\n", candidates[i].name,candidates[i].votes);
	    return true;
	}
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int key, j;
    candidate sorted_candidates[MAX_CANDIDATES];
    candidate candidate_swap;

    //copy array to avoid side effects
    for (int i = 0; i < candidate_count; i++)
    {
	sorted_candidates[i] = candidates[i];
    }

    for (int i = 0; i < candidate_count; i++)
    {
	if (sorted_candidates[i].eliminated == false)
	{
	    key = sorted_candidates[i].votes;
	    candidate_swap = sorted_candidates[i];
	    j = i - 1;
	    while(j >= 0 && sorted_candidates[j].votes > key)
	    {
		sorted_candidates[j+1] = sorted_candidates[j];
		j -= 1;
	    }
	    sorted_candidates[j+1].votes = key;
	    sorted_candidates[j+1] = candidate_swap;
	}
    }
    return sorted_candidates[0].votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
