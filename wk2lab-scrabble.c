#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void declare_winner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    declare_winner(score1, score2);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    /*
    This function generates the ASCII value for each character in the word string, from 65-90, after bumping them to uppercase.
    The end result is from 0 - 25: if it's anything else, the assigned point total is 0.
    It matches the converted value to the POINTS array index, fetches the score, and adds it to the returned total.
    */

    int score = 0;

    for (int i = 0; i < strlen(word); i++) {
        int score_index = (toupper(word[i])) - 65;

        if (score_index >= 0 && score_index <= 25) {
            int earned = POINTS[score_index];
            score += earned;
        } else {
            score += 0;
        }
    }

    return score;

}

void declare_winner(int score1, int score2) {
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}