#include <stdio.h>

#define MAX 10

int board[MAX];

int SAFE(int row, int col)
{
    for(int i = 1; i < row; i++)
    {
        /* Check same column */
        if(board[i] == col)
            return 0;

        /* Check diagonals */
        if((board[i] - i) == (col - row) ||
           (board[i] + i) == (col + row))
            return 0;
    }

    return 1;
}

void M_QUEENS(int row, int n)
{
    if(row > n)
    {
        printf("\nSolution:\n");

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(board[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }

        return;
    }

    for(int col = 1; col <= n; col++)
    {
        if(SAFE(row, col))
        {
            board[row] = col;      // Place queen

            M_QUEENS(row + 1, n);  // Recursive call

            board[row] = 0;        // Backtracking
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    M_QUEENS(1, n);

    return 0;
}
