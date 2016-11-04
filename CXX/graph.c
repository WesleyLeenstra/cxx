/*! Graph library */

#include "graph.h"
#include "doubleLinkedList.h"

/**
 * addVertex function
 * Adds a vertex to the given graph.
 */
void addVertex(vertex* thisVertex, graph* thisGraph)
{
	addNodeTail(createUnlinkedNode((vertex*)thisVertex), thisGraph->vertices );
}

/**
 * searchVertexName function
 * Searches for a vertex in the given graph that has the given name.
 */
vertex* searchVertexName(char* thisName, graph* thisGraph)
{
	DLLNode* currentNode = thisGraph->vertices->head;			//Set the current node to the head of the list

	while(currentNode->next != NULL)			//Loop till the end of the list
	{
		vertex *currentVertex = currentNode->data;

		if(currentVertex->name == thisName)		//If the predicate function meets the currentNode data
		{
			return currentVertex;					//Exit function and return the currentNode
		}
		currentNode = currentNode->next;		//Else move currentNode pointer to the next in list
	}
	return NULL;
}

/**
 * searchVertexData function
 * Searches for a vertex in the given graph that has the given data
 */
vertex* searchVertexData(bool (*predicate)(void *thisData), graph* thisGraph)
{
	DLLNode* currentNode = thisGraph->vertices->head;			//Set the current node to the head of the list

	while(currentNode->next != NULL)			//Loop till the end of the list
	{
		vertex* currentVertex = currentNode->data;

		if((*predicate)(currentVertex->data))		//If the predicate function meets the currentNode data
		{
			return currentVertex;					//Exit function and return the currentNode
		}
		currentNode = currentNode->next;		//Else move currentNode pointer to the next in list
	}
	return NULL;
}

/**
 * addEdge function
 * Adds an edge to the given vertex in the given graph.
 */
void addEdge(edge* thisEdge, vertex* thisVertex, double cost)
{
	thisEdge->costs = cost;
	thisEdge->destination = thisVertex;

	addNodeTail(createUnlinkedNode((edge*)thisEdge), thisVertex->edges);
}

/**
 * deleteEdge function
 * Deletes an edge from the given vertex in the given graph.
 */
void deleteEdge(edge* thisEdge)
{
	doubleLinkedList *edges = thisEdge->destination->edges;
	DLLNode *currentNode = edges->head;

	while(currentNode->next != NULL)			//Loop till the end of the list
	{
		edge* currentEdge = currentNode->data;

		if(currentEdge == thisEdge)		//If the predicate function meets the currentNode data
		{
			DLLNode *nextTemp = currentNode->next;
			DLLNode *previousTemp = currentNode->previous;

			previousTemp->next = nextTemp;
			nextTemp->previous = previousTemp;

			free(currentEdge);

			return;
		}
		currentNode = currentNode->next;		//Else move currentNode pointer to the next in list
	}
}

/**
 * disposeGraph function
 * Disposes the graph an frees the memory
 */
void disposeGraph(graph* thisGraph, DataFreeFunction datafree)
{
	doubleLinkedList *vertices = thisGraph->vertices;

	DLLNode *currentNode = vertices->head;

	while(currentNode->next != NULL)
	{
		vertex *currentVertex = currentNode->data;

		disposeDLL(currentVertex->edges, datafree);

		currentNode = currentNode->next;
	}

	disposeDLL(vertices, datafree);

	free(thisGraph);
}

graph* createEmptyGraph()
{
	graph *thisGraph = (graph*)malloc(sizeof(graph));
	thisGraph->vertices = createEmptyDLL();

	return thisGraph;
}

vertex* createUnlinkedVertex(void* data, char* name)
{
	vertex *thisVertex = (vertex*)malloc(sizeof(vertex));
	thisVertex->data = data;
	thisVertex->name = name;
	thisVertex->edges = createEmptyDLL();

	return thisVertex;
}

edge* createUnlinkedEdge()
{
	edge *thisEdge = (edge*)malloc(sizeof(edge));
	thisEdge->costs = 0.0;
	thisEdge->destination = NULL;

	return thisEdge;
}

char *setChar(char name)							//Example user defined function
{
	char *c = malloc(sizeof(char));				//Create new int pointer and allocate memory to it
	*c = name;									//set int * to data entered
	return c;									//return int pointer
}