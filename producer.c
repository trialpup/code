#include<stdio.h>
#include<conio.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void producer()
{
    if((mutex == 1) && (empty != 0))
    {
        mutex = 0;
        x++;
        printf("\nProducer produces item %d", x);
        full++;
        empty--;
        mutex = 1;
    }
    else
    {
        printf("\nBuffer is Full!");
    }
}

void consumer()
{
    if((mutex == 1) && (full != 0))
    {
        mutex = 0;
        printf("\nConsumer consumes item %d", x);
        x--;
        full--;
        empty++;
        mutex = 1;
    }
    else
    {
        printf("\nBuffer is Empty!");
    }
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid Choice!");
        }

        printf("\nBuffer Status:");
        printf("\nFull = %d", full);
        printf("\nEmpty = %d", empty);

    } while(choice != 3);

    getch();
}

// banker
#include<stdio.h>
#include<conio.h>

void main()
{
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10];
    int finish[10];
    int safe[10];

    int n, m;
    int i, j, k;
    int count = 0, found;

    clrscr();

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
        work[i] = avail[i];
    }

    printf("\nNeed Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
        finish[i] = 0;

    while(count < n)
    {
        found = 0;

        for(i=0;i<n;i++)
        {
            if(finish[i] == 0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m)
                {
                    for(k=0;k<m;k++)
                        work[k] += alloc[i][k];

                    safe[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n)
    {
        printf("\n\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");

        for(i=0;i<n;i++)
        {
            printf("P%d", safe[i]);

            if(i != n-1)
                printf(" -> ");
        }
    }
    else
    {
        printf("\n\nSystem is NOT in SAFE state.");
    }

    getch();
}