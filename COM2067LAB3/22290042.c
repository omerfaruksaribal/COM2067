#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int order;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void enqueue(int data, int order)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->order = order;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int dequeue()
{
    if (head == NULL)
    {
        return -1;
    }
    struct node *temp = head;
    int data = head->data;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return data;
}

void moveAndCleanCache()
{
    struct node *tempHead = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(tempHead);

    struct node *tempTail = tail;
    tail = tail->prev;
    if (tail != NULL)
    {
        tail->next = NULL;
    }
    free(tempTail);
}

int maxSum(int step, int *selectedValues, int *selectedOrders)
{
    int sum = 0;

    for (int i = 0; i < step; i++)
    {
        if (head == NULL)
        {
            break;
        }

        if (head->data >= tail->data)
        {
            selectedValues[i] = head->data;
            selectedOrders[i] = head->order;

            sum += head->data;

            moveAndCleanCache();
        }
        else
        {
            selectedValues[i] = tail->data;
            selectedOrders[i] = tail->order;

            sum += tail->data;

            moveAndCleanCache();
        }
    }

    return sum;
}

int main()
{
    int value;
    int order = 1;

    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        enqueue(value, order);
        order++;
    }
    int step;
    scanf("%d", &step);

    int selectedValues[step];
    int selectedOrders[step];

    int result = maxSum(step, selectedValues, selectedOrders);

    printf("%d\n", result);

    for (int i = 0; i < step; i++)
    {
        if (selectedValues[i] != 0)
        {
            printf("%d %d\n", selectedValues[i], selectedOrders[i]);
        }
    }

    return 0;
}