/*
* File: pointers3.c
* Author: Wesley Leenstra (0879752) & Niels Vogelaar (0874968)
* Version: 1.0
* Description: Step 3 of pointer assignments.
*/

#include <stdlib.h>
#include <stdio.h>

// function prototypes
//void swap(int *a, int *b);

int main(void)
{
    int a, b;

    a = 5;
    b = 10;

    printf("The value of a was %d\nThe value of b was %d\n", a, b);

    // now you must swap the values of A and B using pointers
    // use the skeleton function void swap(int *a, int *b) to swap the values
    swap(&a,&b);

    printf("The value of a is %d\nThe value of b is %d\n", a, b);

    return 0;
}

// This function must swap the values of variable pointed to by p1
// with the variable pointed to by p2, without returning any values.
void swap(int *p1, int *p2)
{
	int c, d;

	c = *p1;		//Set parameter pointers to temporary values
	d = *p2;

	*p1 = d;		//Swap parameter pointers
	*p2 = c;
}
