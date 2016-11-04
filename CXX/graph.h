/* graph.h
 *
 *  Created on: Oct 12, 2016
 *      Author: archwez
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

#ifndef LIBRARIES_GRAPH_H_
#define LIBRARIES_GRAPH_H_

typedef struct
{
	char* name;
	void* data;
	doubleLinkedList* edges;
} vertex;

typedef struct
{
	vertex* destination;
	double costs;
} edge;

typedef struct
{
	doubleLinkedList* vertices;
} graph;

void addVertex(vertex* thisVertex, graph* thisGraph);
vertex* searchVertexName(char* thisName, graph* thisGraph);
vertex* searchVertexData(bool (*predicate)(void *thisData), graph* thisGraph);
void addEdge(edge* thisEdge, vertex* thisVertex, double cost);
void deleteEdge(edge* thisEdge);
void disposeGraph(graph* thisGraph, DataFreeFunction datafree);

graph* createEmptyGraph();
vertex* createUnlinkedVertex(void* data, char* name);

char *setChar(char name);

#endif /* LIBRARIES_GRAPH_H_ */
