// fcfs 
#include <stdio.h>
#include <conio.h>

void main()
{
    int req[20], n, head, i;
    int seek = 0;

    clrscr();

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i=0;i<n;i++)
    {
        seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", seek);

    getch();
}

// sstf
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int req[20], visited[20];
    int n, head, i, j;
    int seek = 0;

    clrscr();

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter request queue:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("\nSeek Sequence: %d", head);

    for(i=0;i<n;i++)
    {
        int min = 9999;
        int index = -1;

        for(j=0;j<n;j++)
        {
            if(!visited[j] && abs(head-req[j]) < min)
            {
                min = abs(head-req[j]);
                index = j;
            }
        }

        visited[index] = 1;
        seek += abs(head - req[index]);
        head = req[index];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", seek);

    getch();
}

// scan
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void main()
{
    int req[20], n, head, size;
    int i, pos;
    int seek = 0;

    clrscr();

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests:\n");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    sort(req,n);

    for(pos=0; pos<n; pos++)
    {
        if(req[pos] > head)
            break;
    }

    printf("\nSeek Sequence: %d", head);

    for(i=pos;i<n;i++)
    {
        seek += abs(head-req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    seek += abs(head-(size-1));
    head = size-1;

    printf(" -> %d", head);

    for(i=pos-1;i>=0;i--)
    {
        seek += abs(head-req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", seek);

    getch();
}

// cscan
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void main()
{
    int req[20], n, head, size;
    int i, pos;
    int seek = 0;

    clrscr();

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests:\n");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    sort(req,n);

    for(pos=0; pos<n; pos++)
    {
        if(req[pos] > head)
            break;
    }

    printf("\nSeek Sequence: %d", head);

    for(i=pos;i<n;i++)
    {
        seek += abs(head-req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    seek += abs(head-(size-1));
    head = size-1;
    printf(" -> %d", head);

    seek += abs(head-0);
    head = 0;
    printf(" -> %d", head);

    for(i=0;i<pos;i++)
    {
        seek += abs(head-req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", seek);

    getch();
}

