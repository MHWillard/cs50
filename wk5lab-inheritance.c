/*
Complete the implementation of inheritance.c, such that it creates a family of a specified generation size and assigns blood type alleles to each family member. The oldest generation will have alleles assigned randomly to them.

The create_family function takes an integer (generations) as input and should allocate (as via malloc) one person for each member of the family of that number of generations, returning a pointer to the person in the youngest generation.
For example, create_family(3) should return a pointer to a person with two parents, where each parent also has two parents.
Each person should have alleles assigned to them. The oldest generation should have alleles randomly chosen (as by calling the random_allele function), and younger generations should inherit one allele (chosen at random) from each parent.
Each person should have parents assigned to them. The oldest generation should have both parents set to NULL, and younger generations should have parents be an array of two pointers, each pointing to a different parent.
We’ve divided the create_family function into a few TODOs for you to complete.

First, you should allocate memory for a new person. Recall that you can use malloc to allocate memory, and sizeof(person) to get the number of bytes to allocate.
Next, we’ve included a condition to check if generations > 1.
If generations > 1, then there are more generations that still need to be allocated. Your function should set both parents by recursively calling create_family. (How many generations should be passed as input to each parent?) The function should then set both alleles by randomly choosing one allele from each parent.
Otherwise (if generations == 1), then there will be no parent data for this person. Both parents should be set to NULL, and each allele should be generated randomly.
Finally, your function should return a pointer for the person that was allocated.
The free_family function should accept as input a pointer to a person, free memory for that person, and then recursively free memory for all of their ancestors.

Since this is a recursive function, you should first handle the base case. If the input to the function is NULL, then there’s nothing to free, so your function can return immediately.
Otherwise, you should recursively free both of the person’s parents before freeing the child.
*/

// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    // run create_family and assign it to a *p pointer of the person data type structure
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *p_new = malloc(sizeof(person));

    // Generation with parent data
    if (generations > 1)
    {
        if (p_new != NULL)
        {
            // TODO: Recursively create blood type histories for parents
            //recur here to add parents to the p_new pointer
            p_new->parents[0] = create_family(generations - 1);
            p_new->parents[1] = create_family(generations - 1);

            // TODO: Randomly assign child alleles based on parents
            //access the pointer properties and roll random to grab an allele
            p_new->alleles[0] = p_new->parents[0]->alleles[rand() % 2];
            p_new->alleles[1] = p_new->parents[1]->alleles[rand() % 2];
        }
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        if (p_new != NULL)
        {
            p_new->parents[0] = NULL;
            p_new->parents[1] = NULL;

        // TODO: Randomly assign alleles
        for (int i = 0; i < 2; i++) {
            char a;
            a = random_allele();
            p_new->alleles[i] = a;
            }
        }
    }

    // TODO: Return newly created person
    return p_new;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }

    if (p) {
        // TODO: Free parents
        //call free_family on the parents property of the p pointer person
        free_family(p->parents[0]);
        free_family(p->parents[1]);

        // TODO: Free child
        free(p);
    }
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}