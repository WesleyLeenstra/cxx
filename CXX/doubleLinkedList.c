#include "doubleLinkedList.h"

void addNodeHead(DLLNode *newNode, doubleLinkedList *DLL)
{
	if (DLL->head == NULL)
	{
		DLL->head = newNode;					//List is empty, set node to both head and tail
		DLL->tail = newNode;
	}
	else
	{
		DLLNode *temp = DLL->head;				//Save current head pointer in temp

		DLL->head = newNode;					//Change current head pointer to the newNode pointer
		DLL->head->next = temp;					//Link previous pointer to the node saved in temp pointer
		temp->previous = DLL->head;				//Complete double link by setting temp node's next pointer to the new head pointer
	}
}

void addNodeTail(DLLNode *newNode, doubleLinkedList *DLL)
{
	if (DLL->tail == NULL)
	{
		DLL->head = newNode;					//List is empty, set node to both head and tail
		DLL->tail = newNode;
	}
	else
	{
		DLLNode *temp = DLL->tail;				//Save current tail pointer in temp

		DLL->tail = newNode;					//Change current tail pointer to the newNode pointer
		DLL->tail->previous = temp;     		//Link previous pointer to the node saved in temp pointer
		temp->next = DLL->tail;					//Complete double link by setting temp node's next pointer to the new tail pointer
	}
}

void addNodeBefore(DLLNode *newNode, DLLNode *positionNode, doubleLinkedList *DLL)
{
	newNode->next = positionNode;				//Point the next and previous pointers of newNode to their new locations
	newNode->previous = positionNode->previous;

	positionNode->previous = newNode;			//positionNode's previous pointer has te change aswell to complete the double link

	if(newNode->previous == NULL)				//Check if the node was added at tail or head position
	{											//and change the pointers accordingly
		DLL->head = newNode;
	}
	if(newNode->next == NULL)
	{
		DLL->tail = newNode;
	}
}

void addNodeAfter(DLLNode *newNode, DLLNode *positionNode, doubleLinkedList *DLL)
{
	newNode->previous = positionNode;			//Point the next and previous pointers of newNode to their new locations
	newNode->next = positionNode->next;

	positionNode->next = newNode;				//PositionNode's previous pointer has te change aswell to complete the double link

	if(newNode->previous == NULL)				//Check if the node was added at tail or head position
	{											//and change the pointers accordingly
		DLL->head = newNode;
	}
	if(newNode->next == NULL)
	{
		DLL->tail = newNode;
	}
}

DLLNode* searchFirst(bool (*predicate)(void *data), doubleLinkedList *DLL)
{
	DLLNode* currentNode = DLL->head;			//Set the current node to the head of the list

	while(currentNode->next != NULL)			//Loop till the end of the list
	{
		if((*predicate)(currentNode->data))		//If the predicate function meets the currentNode data
		{
			return currentNode;					//Exit function and return the currentNode
		}
		currentNode = currentNode->next;		//Else move currentNode pointer to the next in list
	}
	return NULL;								//If nothing is found return NULL
}

DLLNode* searchLast(bool (*predicate)(void *data), doubleLinkedList *DLL)
{
	DLLNode* currentNode = DLL->tail;			//Set the current node to the tail of the list

	while(currentNode->previous != NULL)		//Loop till the beginning of the list
	{
		if((*predicate)(currentNode->data))		//If the predicate function meets the currentNode data
		{
			return currentNode;					//Exit function and return the currentNode
		}
		currentNode = currentNode->previous;	//Else move currentNode pointer to the next in list
	}
	return NULL;								//If nothing is found return NULL
}

DLLNode* getFirstBefore(bool (*predicate)(void *data), DLLNode *positionNode, doubleLinkedList *DLL)
{
	DLLNode* currentNode = positionNode;		//Set the current node to the positioNode of the list

	while(currentNode->previous != NULL)		//Loop till the end of the list
	{
		if((*predicate)(currentNode->data))		//If the predicate function meets the currentNode data
		{
			return currentNode;					//Exit function and return the currentNode
		}
		currentNode = currentNode->previous;	//Else move currentNode pointer to the next in list
	}
	return NULL;								//If nothing is found return NULL
}

DLLNode* getFirstAfter(bool (*predicate)(void *data), DLLNode *positionNode, doubleLinkedList *DLL)
{
	DLLNode* currentNode = positionNode;		//Set the current node to the head of the list

	while(currentNode->next != NULL)			//Loop till the end of the list
	{
		if((*predicate)(currentNode->data))		//If the predicate function meets the currentNode data
		{
			return currentNode;					//Exit function and return the currentNode
		}
		currentNode = currentNode->next;		//Else move currentNode pointer to the next in list
	}
	return NULL;								//If nothing is found return NULL
}

int getNodeCount(doubleLinkedList *DLL)
{
	int count = 0;								//Create count integer

	DLLNode* currentNode = DLL->head;			//Set the current node to the tail of the list

	while(currentNode->next != NULL)			//Loop till the beginning of the list
	{
		count++;								//Add +1 to count

		currentNode = currentNode->next;		//Move to next node
	}
	count++;

	return count;								//return ammount of nodes in the list
}

void dispose(doubleLinkedList *DLL, DataFreeFunction datafree)
{
	DLLNode* nextNode = DLL->head;			//Set the current node to the tail of the list

	while(nextNode)		//Loop till the beginning of the list
	{
		DLLNode *currentNode = nextNode;		//Change to the next node, after node is freed it cannot be accessed anymore
		nextNode = currentNode->next;
		(*datafree)(currentNode->data);			//Free node memory
		free(currentNode);
		currentNode = NULL;
	}

	free(DLL);									//Also free the list memory
}

void data_free(void* data)
{
	free(data);
};

DLLNode *createUnlinkedNode(void *data)
{
	DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));	//Allocate memory for the new node

	newNode->data = data;						//Set variables to default values
	newNode->next = NULL;
	newNode->previous = NULL;

	return newNode;
}

doubleLinkedList *createEmptyDLL()
{
	doubleLinkedList *DLL = (doubleLinkedList *)malloc(sizeof(doubleLinkedList));	//Allocate memory for the new list

	DLL->head = NULL;							//Set variables to default values
	DLL->tail = NULL;

	return DLL;
}

bool findIntGreaterThan0(void *data)			//Example user defined function
{
	return *(int *)data >= 0;					//Typecast void* to int*
}

bool findIntSmallerThan150(void *data)			//Example user defined function
{
	return *(int *)data <= 100;					//Typecast void* to int*
}

int *setInt(int data)							//Example user defined function
{
	int *i = malloc(sizeof(int));				//Create new int pointer and allocate memory to it
	*i = data;									//set int * to data entered
	return i;									//return int pointer
}
