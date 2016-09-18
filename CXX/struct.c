/*
* File: struct.c
* Author: Wesley Leenstra (0879752) & Niels Vogelaar (0874968)
* Version: 1.0
* Description: Struct assignment.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
* char* phonemes is an array containing all phoneme file names
*/
char* phonemes[] = {"AA", "AE", "AH", "AO", "AW", "AX", "AY", "b", "CH", "d",
                    "DH", "EH", "ER", "EY","f", "g", "HH", "IH", "IY", "j",
                    "k", "l", "m", "n", "NG", "OW", "OY", "p", "r", "s", "SH",
                    "t", "TH", "UH", "UW", "v", "w", "WH", "y", "YU", "z", "ZH"
                   };
/*
* Implement a struct. A struct is a collection of data.
* For this exercise implement a struct with an integer "length"
* and an integer array "wordPart"
*/
struct word
{
	int length;
	int wordPart[2];
};

/*
* This function plays a single phoneme. It uses the build in audioplayer of linux.
* Note that this function is blocking (eg your program will not continue until
* linux has finished playing the audio file).
*/
int playSound(char *filename )
{
    char command[256];
    int status;

    // create command to execute playback
    sprintf(command, "aplay -c 1 -q -t wav Phonemes/%s", filename);
    // play sound
    status = system(command);
    // if return = 0 then succesful playback, else an error has occured
    return status;
}

/*
* This function plays a word. The function requires a pointer to a struct.
* If you created a struct with a typedef and named it "word" you can use this
* function directly. Otherwise you need to modify the parameter part of this function.
*/
int playStruct(struct word *structPointer)
{
    int i;
    i = 0;
    while(i < structPointer->length)
    {
        playSound(phonemes[structPointer->wordPart[i]]);
        i++;
    }
}

/*
* Build a program using the struct and the playWord function to playback an entire word
* Choose a small word of 4 or 5 letters to play.
*/
int main(void)
{
    /*
    * declare a struct here and make a pointer to that struct
    * Fill the struct with data (the length and the wordParts)
    * pass the pointer to the playStruct() function
    *
    * The wordPart integer array should be filled with the index numbers
    * of the phoneme list. The example wordPart[0] = 0 will play the phoneme "AA" and
    * wordPart[1] = 3 will play the phoneme "AO".
    */
	struct word hoi;

	hoi.length = 2;
	hoi.wordPart[0] = 16;
	hoi.wordPart[1] = 26;

    playStruct(&hoi);

    return 0;
}



