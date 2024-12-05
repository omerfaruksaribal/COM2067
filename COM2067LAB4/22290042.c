#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[100];
    char number[100];
    struct node *right;
    struct node *left;
};

struct node *insertNode(struct node *root, char name[100], char number[100])
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        strcpy(root->name, name);
        strcpy(root->number, number);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (strcmp(name, root->name) < 0)
    {
        root->left = insertNode(root->left, name, number);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = insertNode(root->right, name, number);
    }
    return root;
}

int searchNode(struct node *root, char *prefix, int *count)
{
    if (root == NULL)
    {
        return 0;
    }

    int found = 0;

    if (searchNode(root->left, prefix, count))
    {
        found = 1;
    }

    if (strncmp(root->name, prefix, strlen(prefix)) == 0)
    {
        printf("%s\n", root->name);
        (*count)++;
        found = 1;
    }

    if (searchNode(root->right, prefix, count))
    {
        found = 1;
    }

    return found;
}

void traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    traversal(root->left);
    printf("%s %s\n", root->name, root->number);
    traversal(root->right);
}

int main()
{
    struct node *root = NULL;
    char input[200];
    while (1)
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "-1") == 0)
        {
            break;
        }

        char name[100], number[100];
        int items = sscanf(input, "%99s %99s", name, number);

        if (items == 2)
        {
            root = insertNode(root, name, number);
        }
    }

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "-1") == 0)
        {
            break;
        }

        int count = 0;
        if (!searchNode(root, input, &count))
        {
            printf("nobody\n");
            break;
        }
        else if (count == 1)
        {
            break;
        }
    }

    return 0;
}
