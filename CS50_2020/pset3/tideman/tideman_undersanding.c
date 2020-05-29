#include <stdio.h>
#include <cs50.h>

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);


bool vote(int rank, string name, int ranks[])
{
    /*
    Look for a candidate called name.
    If candidate found, update ranks and return true.
    Ranks[i] is the voter's i'th preference.
    If no candidate found, don't update any ranks and return false.
    */

}


void record_preferences(int ranks[])
{
    /*
    Update preferences array based on the current voter's ranks.

    */

}


void add_pairs(void)
{
    /*
    Add each pair of candidates to pairs array if one candidate is preffered over the other.
    Update global variable pair_count to be the total number of pairs.
    */
}

void sort_pairs(void)
{
    /*
    Sort the pairs according to strength of victory.
    */

}

void lock_pairs(void)
{
    /*
    Update locked to create the locked graph by adding all edges in decreasing order of victory strength, as long as there is no cycle.
    */
}

void print_winner(void)
{
    /*
    Print the winner of the election
    */
}