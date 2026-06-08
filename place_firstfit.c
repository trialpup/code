// first
#include <stdio.h>
#include <conio.h>

void main()
{
    int block[20], process[20];
    int nb, np, i, j, allocation[20];

    clrscr();

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of memory blocks:\n");
    for(i=0;i<nb;i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for(i=0;i<np;i++)
        scanf("%d", &process[i]);

    for(i=0;i<np;i++)
        allocation[i] = -1;

    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i=0;i<np;i++)
    {
        if(allocation[i] != -1)
            printf("%d\t%d\t%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("%d\t%d\tNot Allocated\n", i+1, process[i]);
    }

    getch();
}

//BEst
#include <stdio.h>
#include <conio.h>

void main()
{
    int block[20], process[20];
    int nb, np, i, j, bestIdx, allocation[20];

    clrscr();

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of memory blocks:\n");
    for(i=0;i<nb;i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for(i=0;i<np;i++)
        scanf("%d", &process[i]);

    for(i=0;i<np;i++)
        allocation[i] = -1;

    for(i=0;i<np;i++)
    {
        bestIdx = -1;

        for(j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                if(bestIdx == -1 || block[j] < block[bestIdx])
                    bestIdx = j;
            }
        }

        if(bestIdx != -1)
        {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i=0;i<np;i++)
    {
        if(allocation[i] != -1)
            printf("%d\t%d\t%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("%d\t%d\tNot Allocated\n", i+1, process[i]);
    }

    getch();
}

//worst
#include <stdio.h>
#include <conio.h>

void main()
{
    int block[20], process[20];
    int nb, np, i, j, worstIdx, allocation[20];

    clrscr();

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of memory blocks:\n");
    for(i=0;i<nb;i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for(i=0;i<np;i++)
        scanf("%d", &process[i]);

    for(i=0;i<np;i++)
        allocation[i] = -1;

    for(i=0;i<np;i++)
    {
        worstIdx = -1;

        for(j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                if(worstIdx == -1 || block[j] > block[worstIdx])
                    worstIdx = j;
            }
        }

        if(worstIdx != -1)
        {
            allocation[i] = worstIdx;
            block[worstIdx] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i=0;i<np;i++)
    {
        if(allocation[i] != -1)
            printf("%d\t%d\t%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("%d\t%d\tNot Allocated\n", i+1, process[i]);
    }

    getch();
}

//next
#include <stdio.h>
#include <conio.h>

void main()
{
    int block[20], process[20];
    int nb, np, i, j, allocation[20];
    int last = 0, count;

    clrscr();

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of memory blocks:\n");
    for(i=0;i<nb;i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for(i=0;i<np;i++)
        scanf("%d", &process[i]);

    for(i=0;i<np;i++)
        allocation[i] = -1;

    for(i=0;i<np;i++)
    {
        count = 0;
        j = last;

        while(count < nb)
        {
            if(block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] -= process[i];
                last = j;
                break;
            }

            j = (j + 1) % nb;
            count++;
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i=0;i<np;i++)
    {
        if(allocation[i] != -1)
            printf("%d\t%d\t%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("%d\t%d\tNot Allocated\n", i+1, process[i]);
    }

    getch();
}