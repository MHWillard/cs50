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
    // ORG: person *p = create_family(GENERATIONS); run create_family and assign it to a *p pointer of the person data type structure
    person *p = create_family(3);

    // Print family tree of blood types
    print_family(p, 2);

    // Free memory
    // ORG: free_family(p);
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
        person *p_two = malloc(sizeof(person));
        if (p_two != NULL)
        {
            p_two->parents[0] = NULL;
            p_two->parents[1] = NULL;
        // TODO: Randomly assign alleles
        for (int i = 0; i < 2; i++) {
            char a;
            a = random_allele();
            p_new->alleles[i] = a;
            }
        }

        // TODO: Recursively create blood type histories for parents

        // TODO: Randomly assign child alleles based on parents

    }

    // Generation without parent data
    //this is recursive so it gets triggered with create_family(generations - 1)
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

    p_new->parents[0] = p_two;
    // TODO: Return newly created person
    return p_new;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    free(p);

    // TODO: Free parents

    // TODO: Free child
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
