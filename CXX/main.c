#include <stdio.h>
#include <stdlib.h>
#include "libraries/doubleLinkedList.h"
#include "libraries/graph.h"

FILE *file;

void nextLine()
{
	//0xA translates to char "\n" in ASCII
	while(fgetc(file) != 0xA);
}

void skipChar(int n)
{
	//skip n amount of characters in the file stream
	for (int i = 0; i < n; i++)
	{
		int rubbish = fgetc(file);
	}
}

graph *readFile()
{
	//Create graph pointer so we can start filling a graph
	graph *readGraph = createEmptyGraph();

	//Open the file for reading
	file = fopen("shortestPath.gdf", "r");

	//Check if the file is indeed open
	if(file == NULL)
	{
		printf("Error opening file");
	}

	//Skip the first line because its just initialization
	nextLine();

	//Create and link all the vertices
	while(1)
	{
		//The first character now corresponds to the name of the vertex
		int name = fgetc(file);

		//If name equals character e (0x65 in ASCII)  break the while loop
		if(name == 0x65)
		{
			break;
		}

		//skip the ," portion of the line
		skipChar(2);

		//Create the string array
		char location[50];

		//Fill the string array
		for(int i = 0; i  < 50; i++)
		{
			//read in current char
			int readResult = fgetc(file);

			//Only gets added to the string if the current result is not equal to the character " (0x22 in ASCII)
			if(readResult != 0x22)
			{
				location[i] = readResult;
			}
			else
			{
				//We break the for loop since it is not needed to continue
				break;
			}
		}

		//We can now create the vertex with the parameters that where previously read
		vertex *newVertex = createUnlinkedVertex((int)setInt(name), (char)setChar(location[0]));

		//We can now add the complete vertex to the graph
		addVertex(newVertex, readGraph);

		//Now continue to the next line
		nextLine();
	}

	//Skip this line since it is just configurations
	nextLine();



	//return the graph, it is done now and can be used for further purposes
	return readGraph;
}



//readFile
//readLine
//writeFile
//findShortestPath

int main(void)
{
	graph *newGraph = readFile();
	printf("\nWe loaded %d", getNodeCount(newGraph->vertices));
	printf(" vertices in the graph" );
	return 0;
}
