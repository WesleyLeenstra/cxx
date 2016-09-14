/*
* File: pointers2.c
* Author: Wesley Leenstra (0879752) & Niels Vogelaar (0874968)
* Version: 1.0
* Description: Step 2 of pointer assignments.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int a[10];
    int *b;

    int i;

    // Fill array a with ascending values
    for(i = 0; i < 10; i++)
    {
        a[i] = i;
    }

    // Pointers can be used to index arrays
    b = a; // This statement is the same as b = &a[0]
    // it will point b to the first index of array a.
    // with b++ you can step through the array.
    // print the entire array using pointer b
    printf("Eerste print: \n");

    for(b = a; b <= &a[9]; b++)
    {
    	printf("%d\n", *b);
    }

    // Now print the entire array once again, but with each element incremented by 1.
    // Again only use pointers.
    printf("\nTweede print: \n");

    for(b = a; b <= &a[9]; b++)
    {
        printf("%d\n", *b+1);
    }

    // Now adjust the program to reverse the array using pointers (you might need more than 1 pointer)
    // Print the reversed array
    printf("\nDerde print: \n");

    int *c = &a[9];
    int storedB;				//b side value of the array
    int storedC;				//c side value of the array

    for(b = a; b <= &a[4]; b++) //We know the length of the array so we can do 5 loop iterations
    {
    	storedB = a[*b];		//Store b side value
    	storedC = a[*c];		//Store c side value
    	a[*b] = storedC;		//Change b side value to c side value
    	a[*c] = storedB;		//Change c side value to b side value
    	c--;					//Set c pointer the next lower element
    }

    for(b = a; b <= &a[9]; b++)			 //Print the reversed array
    {
        printf("%d\n", *b);
    }

    return 0;
}
