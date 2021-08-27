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

/*
-takes command line argument: has to be a 26 alphabetical key with each character only once or it returns an error (error check function)
--stores this as a key
-takes plaintext input; stores as plaintext_input

-runs second array that's normal A-Z alphabet

-for now: capitalize plaintext to run through ascii codes

-iterating through plaintext
--if not alphabetical character: pass
--if alhapbetical:
---get ascii code
---compare to index of key array
---get key array character
---push to new converted ciphertext array

return: ciphertext: [cipher array]
--exit 0 from main
*/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

string key_check(string argument);

int main(int argc, string argv[]) {
    //take command line argument
    //confirm that argument is 26 characters, alphabetical only, and each character only appears once
    //if good: continue
    //if not: error
    if (argv[1]) {
        string argument = argv[1];
        string input = get_string("plaintext: ");
        printf("Input: %s\n", input);
        printf("Argument: %s\n", argument);
        string key = key_check(argument);
        printf("Key: %s\n", key);
    } else {
        printf("Need argument.\n");
        return 0;
    }
}

/*
key_check
-get key as argument
-check length: if array !== 26 length, pass false
-check characters: iterate, if a character is not alphabetical, pass false (or use strchr to check for non-alphabetical?)
-check for repeaty characters: if found, pass false (work on this one later)

otherwise, pass true

how can one programatically check if a character repeats?
-one thought: as a string is iterated, push each character to a check array
--then, iterate through check array with successive passes: if any of them match any characters found in the check array, throw a false
--making ASCII array to check for these characters against each other as well
*/

string key_check(string argument) {
    //TODO: check for repeat characters
    if (strlen(argument) != 26) {
        return "invalid";
    } else {
        return "valid";
    }
}