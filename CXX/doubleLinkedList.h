#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

typedef void(* DataFreeFunction)(void*);

typedef struct
{
	void *data;
	struct DLLNode *next;
	struct DLLNode *previous;
}DLLNode;

typedef struct
{
	DLLNode *head;
	DLLNode *tail;
}doubleLinkedList;

//This function adds a node at the head position
void addNodeHead(DLLNode *newNode, doubleLinkedList *DLL);
//This function adds a node at the tail position
void addNodeTail(DLLNode *newNode, doubleLinkedList *DLL);
//This function adds a node before a given node
void addNodeBefore(DLLNode *newNode, DLLNode *positionNode, doubleLinkedList *DLL);
//This function adds a node after a given node
void addNodeAfter(DLLNode *newNode, DLLNode *positionNode, doubleLinkedList *DLL);

//This function deletes a given node
void deleteNode(DLLNode *node, doubleLinkedList *DLL);

//This function searches for the first node that contains the given data
DLLNode* searchFirst(bool (*predicate)(void *data), doubleLinkedList *DLL);
//This function searches for the last node that contains the given data
DLLNode* searchLast(bool (*predicate)(void *data), doubleLinkedList *DLL);

//This function searches for the first node that contains the given data after a specific node
DLLNode* getFirstBefore(bool (*predicate)(void *data), DLLNode *positionNode, doubleLinkedList *DLL);
//This function searches for the first node that contains the given data before a specific node
DLLNode* getFirstAfter(bool (*predicate)(void *data), DLLNode *positionNode, doubleLinkedList *DLL);

//returns the total ammount of nodes
int getNodeCount(doubleLinkedList *DLL);

//Deletes the doubleLinkedList and frees memory
void dispose(doubleLinkedList *DLL, DataFreeFunction datafree);

//Creates a unlinked node
DLLNode *createUnlinkedNode(void *data);
//Creates a empty double linked list
doubleLinkedList *createEmptyDLL();

//Function used to free data in a node
void data_free(void* data);

//Function used to create a integer
int *setInt(int data);

//Example user defined functions to use in search functions
bool findIntGreaterThan0(void *data);
bool findIntSmallerThan150(void *data);

#endif /* DOUBLELINKEDLIST_H_ */
