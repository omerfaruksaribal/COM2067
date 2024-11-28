#include <stdio.h>

#define SIZE 5

void matrixPrinter(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[SIZE][SIZE], rowSum = 0, colSum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        rowSum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            rowSum += matrix[i][j];
        }
        for (int k = 0; k < SIZE; k++)
        {
            matrix[k][i] += rowSum;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        colSum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            colSum += matrix[j][i];
        }
        for (int k = 0; k < SIZE; k++)
        {
            matrix[i][k] += colSum;
        }
    }

    matrixPrinter(matrix);
    return 0;
}