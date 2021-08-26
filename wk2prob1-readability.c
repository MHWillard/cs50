#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Design and implement a program, readability, that computes the Coleman-Liau index of the text.

Implement your program in a file called readability.c in a directory called readability.
Your program must prompt the user for a string of text (using get_string).
Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z,
any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number.
If the index number is less than 1, your program should output "Before Grade 1".
*/

string text;
float count_letters(string input);
float count_words(string input);
float count_sentences(string input);
float calculate_reading(float letters, float words, float sentences);
void grade_output(int formula);

int main(void) {
    text = get_string("Text: ");

    float letterc = count_letters(text);
    float wordc = count_words(text);
    float sentencec = count_sentences(text);

    int formula = calculate_reading(letterc, wordc, sentencec);

    grade_output(formula);
}

float count_letters(string input) {
    int letters = 0;

    for (int i = 0; i <= strlen(input); i++) {
        if (isalnum(input[i])) {
            letters++;
        }
    }
    return letters;
}

float count_words(string input) {
    int words = 1;

    for (int i = 0; i <= strlen(input); i++) {
        if (isspace(input[i])) {
            words++;
        }
    }
    return words;
}

float count_sentences(string input) {
    int sentences = 0;

    for (int i = 0; i <= strlen(input); i++) {
        int ascii = input[i];
        //33, 63, 46 = ASCII codes for ., ?, and !

        if (input[i] == 33 || input[i] == 63 || input[i] == 46) {
            sentences++;
        }
    }
    return sentences;
}

//run the formula: it has to be float or it throws floating point exceptions
float calculate_reading(float letters, float words, float sentences) {
    float L = letters / (words / 100);
    float S = sentences / (words / 100);
    float formula = round((0.0588 * L) - (0.296 * S) - 15.8);
    return formula;
}

void grade_output(int formula) {
    if (formula < 1 ) {
        printf("Before Grade 1\n");
    } else if (formula >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", formula);
    }
}