
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
	int wordPart[4];
};

typedef struct listNodeTag
{
	struct listNodeTag *next;
	struct word word;
} listNode;

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

void playList(listNode* n)
{
	while (n != 0)
	{
		playStruct(&n->word);

		n = n -> next;
	}
	printf("\n");
}

/*
* Build a program using the struct and the playWord function to playback an entire word
* Choose a small word of 4 or 5 letters to play.
*/
int main(void)
{
	struct word word0;
	struct word word1;
	struct word word2;

	//Word: ik
	word0.length = 2;
	word0.wordPart[0] = 18;
	word0.wordPart[1] = 20;

	//Word: ben
    word1.length = 3;
    word1.wordPart[0] = 7;
    word1.wordPart[1] = 21;
    word1.wordPart[2] = 23;

    //Word: PC
	word2.length = 4;
	word2.wordPart[0] = 27;
	word2.wordPart[1] = 13;
	word2.wordPart[2] = 40;
	word2.wordPart[3] = 13;

	struct word words[3];
	words[0] = word0;
	words[1] = word1;
	words[2] = word2;

	listNode *head = 0;
	listNode *tail = 0;
	int aantalNodes = 3;

	for (int n = 0; n < aantalNodes; n++)
	{
		listNode *newNode = (listNode *) malloc(sizeof(listNode));
		newNode -> word = words[n];
		newNode -> next = 0;
		if(head == 0)
		{
			head = tail = newNode;
		}
		else
		{
			tail = tail -> next = newNode;
		}
	}

	playList(head);

    return 0;
}
