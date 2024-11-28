struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

void insertFB(struct nodeFB **startFB, int id, int age)
{
	if (*startFB == NULL)
	{
		*startFB = (struct nodeFB *)malloc(sizeof(struct nodeFB));
		(*startFB)->next = NULL;
		(*startFB)->id = id;
		(*startFB)->age = age;
		return;
	}
	if ((*startFB)->id > id)
	{
		struct nodeFB *geciciPtr = (struct nodeFB *)malloc(sizeof(struct nodeFB));
		geciciPtr->id = id;
		geciciPtr->age = age;
		geciciPtr->next = *startFB;
		*startFB = geciciPtr;
		return;
	}
	struct nodeFB *sayacPtr = *startFB;
	while (sayacPtr->next != NULL && sayacPtr->next->id < id)
	{
		sayacPtr = sayacPtr->next;
	}
	struct nodeFB *geciciPtr = (struct nodeFB *)malloc(sizeof(struct nodeFB));
	geciciPtr->next = sayacPtr->next;
	sayacPtr->next = geciciPtr;
	geciciPtr->id = id;
	geciciPtr->age = age;
	return;
}
void insertGS(struct nodeGS **startGS, int id)
{
	if (*startGS == NULL)
	{
		*startGS = (struct nodeGS *)malloc(sizeof(struct nodeGS));
		(*startGS)->next = NULL;
		(*startGS)->id = id;
		return;
	}
	if ((*startGS)->id < id)
	{
		struct nodeGS *geciciPtr = (struct nodeGS *)malloc(sizeof(struct nodeGS));
		geciciPtr->id = id;
		geciciPtr->next = *startGS;
		*startGS = geciciPtr;
		return;
	}
	struct nodeGS *sayacPtr = *startGS;
	while (sayacPtr->next != NULL && sayacPtr->next->id > id)
	{
		sayacPtr = sayacPtr->next;
	}
	struct nodeGS *geciciPtr = (struct nodeGS *)malloc(sizeof(struct nodeGS));
	geciciPtr->next = sayacPtr->next;
	sayacPtr->next = geciciPtr;
	geciciPtr->id = id;
}
void printFB(struct nodeFB *startFB)
{
	while (startFB != NULL)
	{
		printf("%d %d\n", startFB->id, startFB->age);
		startFB = startFB->next;
	}
	printf("\n");
}
void printGS(struct nodeGS *startGS)
{
	while (startGS != NULL)
	{
		printf("%d\n", startGS->id);
		startGS = startGS->next;
	}
	printf("\n");
}
void createFinalList(struct newNodeFB **startNewFB, struct nodeFB *startFB, struct nodeGS *startGS)
{
	struct newNodeFB *currentNewFB = NULL;
	struct newNodeGS *currentNewGS = NULL;

	while (startFB != NULL && startGS != NULL)
	{
		struct newNodeFB *newFBNode = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
		newFBNode->id = startFB->id;
		newFBNode->age = startFB->age;
		newFBNode->next = NULL;

		struct newNodeGS *newGSNode = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
		newGSNode->id = startGS->id;
		newGSNode->next = NULL;

		newFBNode->next = newGSNode;

		if (*startNewFB == NULL)
		{
			*startNewFB = newFBNode;
		}
		else
		{
			currentNewGS->next = newFBNode;
		}

		currentNewFB = newFBNode;
		currentNewGS = newGSNode;

		startFB = startFB->next;
		startGS = startGS->next;
	}
}
void printAll(struct newNodeFB *startNewFB)
{
	while (startNewFB != NULL)
	{
		printf("%d %d\n", startNewFB->id, startNewFB->age);
		if (startNewFB->next != NULL)
		{
			struct newNodeGS *nextGS = startNewFB->next;
			printf("%d\n", nextGS->id);
			startNewFB = nextGS->next;
		}
		// else
		// {
		// 	break;
		// }
	}
}

// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.
