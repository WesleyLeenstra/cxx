/*
* File: pointers1.c
* Author: Wesley Leenstra (0879752) & Niels Vogelaar (0874968)
* Version: 1.0
* Description: Step 1 of pointer assignments.
*/

* Author: Niels en Wesley
* Version: 1
* Description: opdracht 1: Pointers step 1
*/
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int a, b, c;
    int *d, *e;

    a = 5;
    b = 6;
    c = 10;

    // Print the value and the addresses of variable a, b, and c by only using pointer d.
    d = &a;
    printf("a: %d\n", *d);

	d = &b;
	printf("b: %d\n", *d);

	d = &c;
	printf("c: %d\n", *d);

	// You can also do arithmetic operations using pointers.
    // It works just as normal variables, just remember to use the dereference *
    d = &a;
    c = b + *d;

    printf("\nc: %d\n", c);

    // Now calculate c = a * b using pointers d and e and print the result.
    e = &b;

    c = *e * (*d);

    printf("c: %d\n", c);

    return 0;
}

