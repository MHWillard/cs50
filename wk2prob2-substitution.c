/*
Design and implement a program, substitution, that encrypts messages using a substitution cipher.

Implement your program in a file called substitution.c in a directory called substitution.
Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1
(which tends to signify an error) immediately.
If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf)
and return from main a value of 1 immediately.
Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext;
non-alphabetical characters should be outputted unchanged.
Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
*/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

bool length_check(string argument);
bool alpha_check(string argument);
bool repeat_check(string argument);
void convert_text(string input, string argument);

int main(int argc, string argv[]) {

    if (argv[1]) {
        string argument = argv[1];
        string input = get_string("plaintext: ");

        bool length = length_check(argument);
        if (length) {
            return 1;
        }

        bool notalpha = alpha_check(argument);
        if (notalpha) {
            return 1;
        }

        bool repeat = repeat_check(argument);
        if (repeat) {
            return 1;
        }

        convert_text(input, argument);
        return 0;
    } else {
        printf("Usage: ./substitution key\n");
        return 0;
    }
}


bool length_check(string argument) {
    //TODO: check for repeat characters
    if (strlen(argument) != 26) {
        printf("Argument must be exactly 26 characters.\n");
        return true;
    }
    return false;
}

bool alpha_check(string argument) {
    for (int i = 0; i < strlen(argument); i++) {
        if (isalpha(argument[i]) == 0) {
            printf("Argument must only contain letters.\n");
            return true;
        }
    }
    return false;
}

bool repeat_check(string argument) {
    for (int i = 0; i < strlen(argument); i++) {
        char x = argument[i];

        char *first = strchr(argument, x);
        char *last = strrchr(argument, x);

        if (first != last) {
            printf("Characters cannot repeat.\n");
            return true;
        }
    }
    return false;
}

void convert_text(string input, string argument) {
    printf("ciphertext: ");

    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {

        //if upper: subtract to get certain letter, if lower; subtract other number
        //also: mark if letter is upper or lower
        //subtract to get key index
        //get key and compare
        //bump to upper or lower based on what it was
        //print

            //using ASCII values to calc 0-25 index for ciphertext.
            int capital_index;
            bool is_upper;

            if (isupper(input[i])) {
                capital_index = input[i] - 65;
                is_upper = true;
            } else {
                capital_index = input[i] - 97;
                is_upper = false;
            }

            char y = argument[capital_index];

            if (is_upper) {
                printf("%c",toupper(y));
            } else {
                printf("%c",tolower(y));
            }

        } else {
            printf("%c", input[i]);
        }
    }
     printf("\n");
}