#include <stdio.h>

#define LEFT -1
#define RIGHT 1

/* Function to find mobile element */
int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, mobile_prev = 0;

    for(int i = 0; i < n; i++)
    {
        if(dir[a[i]-1] == LEFT && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        if(dir[a[i]-1] == RIGHT && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    return mobile;
}

/* Function to print permutation */
void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* Johnson-Trotter Algorithm */
void johnsonTrotter(int n)
{
    int a[n], dir[n];

    /* Initialize permutation and directions */
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while(1)
    {
        int mobile = getMobile(a, dir, n);

        if(mobile == 0)
            break;

        int pos;

        /* Find position of mobile element */
        for(int i = 0; i < n; i++)
        {
            if(a[i] == mobile)
            {
                pos = i;
                break;
            }
        }

        /* Swap mobile element */
        if(dir[mobile-1] == LEFT)
        {
            int temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;

            pos = pos - 1;
        }
        else
        {
            int temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;

            pos = pos + 1;
        }

        /* Reverse direction of larger elements */
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mobile)
            {
                dir[a[i]-1] = -dir[a[i]-1];
            }
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
