#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int index;
};

struct node *createNode(int data, int index)
{
    if (data == -1)
    {
        return NULL;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->index = index;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *buildTree(int arr[], int index, int size)
{
    if (index >= size || arr[index] == -1)
    {
        return NULL;
    }

    struct node *root = createNode(arr[index], index);
    root->left = buildTree(arr, 2 * index, size);
    root->right = buildTree(arr, 2 * index + 1, size);
    return root;
}

int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

int balanceFactor(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return leftHeight - rightHeight;
}

void printNodeDetails(struct node *nodes[], int currentIndex)
{
    struct node *current = nodes[currentIndex];

    if (current->index > 1)
    {
        int parentIndex = current->index / 2;
        const char *position = (current->index % 2 == 0) ? "L" : "R";
        if (nodes[parentIndex] != NULL)
        {
            printf("(%d %s) ", nodes[parentIndex]->data, position);
        }
    }
    printf("(%d B) ", balanceFactor(current));
}

void printLevelOrder(struct node *root, int size)
{
    if (root == NULL)
    {
        return;
    }

    struct node *nodes[MAX_SIZE] = {NULL};
    nodes[root->index] = root;

    int currentLevelStart = 1;
    int nextLevelStart = 2;

    for (int i = 1; i < size; i++)
    {
        if (nodes[i] != NULL)
        {
            struct node *current = nodes[i];
            printf("%d ", current->data);

            printNodeDetails(nodes, i);

            if (2 * i < size && current->left != NULL)
            {
                nodes[2 * i] = current->left;
            }
            if (2 * i + 1 < size && current->right != NULL)
            {
                nodes[2 * i + 1] = current->right;
            }
        }
        if (i + 1 == nextLevelStart)
        {
            printf("\n");
            nextLevelStart *= 2;
        }
    }
    printf("\n");
}

void mainFunction()
{
    int arr[MAX_SIZE] = {0};
    int size = 1;
    int data;

    while (1)
    {
        scanf("%d", &data);
        if (data == -2)
            break;
        arr[size++] = data;
    }

    struct node *root = buildTree(arr, 1, size);

    printLevelOrder(root, size);
}

int main()
{
    mainFunction();
    return 0;
}
