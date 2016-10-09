#include "munit/munit.h"
#include "doubleLinkedList.h"

static MunitResult test_addNodeHead()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(500));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	if(DLL->head == node3)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_addNodeTail()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(500));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));

	addNodeTail(node1, DLL);
	addNodeTail(node2, DLL);
	addNodeTail(node3, DLL);

	if(DLL->tail == node3)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_addNodeBefore()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(500));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));
	DLLNode *node4 = createUnlinkedNode((int)setInt(900));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);
	addNodeBefore(node4, node3, DLL);

	if(node3->previous == node4)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_addNodeAfter()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(500));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));
	DLLNode *node4 = createUnlinkedNode((int)setInt(900));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);
	addNodeAfter(node4, node2, DLL);

	if(node2->next == node4)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_searchFirst()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(800));
	DLLNode *node2 = createUnlinkedNode((int)setInt(100));
	DLLNode *node3 = createUnlinkedNode((int)setInt(100));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	DLLNode *result = searchFirst(&findIntSmallerThan150, DLL);

	if(result == node3)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_searchLast()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(800));
	DLLNode *node2 = createUnlinkedNode((int)setInt(100));
	DLLNode *node3 = createUnlinkedNode((int)setInt(100));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	DLLNode *result = searchFirst(&findIntSmallerThan150, DLL);

	if(result == node3)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_getFirstBefore()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(800));
	DLLNode *node2 = createUnlinkedNode((int)setInt(100));
	DLLNode *node3 = createUnlinkedNode((int)setInt(100));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	DLLNode *result = getFirstBefore(&findIntSmallerThan150, node1, DLL);

	if(result == node2)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_getFirstAfter()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(100));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	DLLNode *result = getFirstAfter(&findIntSmallerThan150, node3, DLL);

	if(result == node2)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_getNodeCount()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(100));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	int result = getNodeCount(DLL);

	if(result == 3)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitResult test_dispose()
{
	doubleLinkedList *DLL = createEmptyDLL();

	DLLNode *node1 = createUnlinkedNode((int)setInt(100));
	DLLNode *node2 = createUnlinkedNode((int)setInt(100));
	DLLNode *node3 = createUnlinkedNode((int)setInt(900));

	addNodeHead(node1, DLL);
	addNodeHead(node2, DLL);
	addNodeHead(node3, DLL);

	doubleLinkedList *temp = DLL;

	dispose(DLL, data_free);

	if(&DLL != &temp)
	{
		return MUNIT_OK;
	}
	return MUNIT_FAIL;
}

static MunitTest test_suite_tests[] =
{
	{(char*) "/addNodeHead", test_addNodeHead, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/addNodeTail", test_addNodeTail, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/addNodeBefore", test_addNodeBefore, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/addNodeAfter", test_addNodeAfter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/searchFirst", test_searchFirst, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/searchLast", test_searchLast, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/getFirstBefore", test_getFirstBefore, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/getFirstAfter", test_getFirstAfter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/getNodeCount", test_getNodeCount, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{(char*) "/dispose", test_dispose, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
	{NULL,NULL,NULL,NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static MunitSuite test_suite =
{
	(char *) "test",
	test_suite_tests,
	NULL,
	1,
	MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
    return munit_suite_main(&test_suite, (void*) "munit", argc, argv);
}
