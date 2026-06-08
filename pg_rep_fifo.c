#include<stdio.h>
#include<conio.h>

void main()
{
    int pages[50], frame[20];
    int n, f, i, j, pos = 0;
    int faults = 0, hit, k;

    clrscr();

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        hit = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }

        if(hit == 0)
        {
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }

        printf("\n%d -> ", pages[i]);
        for(k = 0; k < f; k++)
            printf("%d ", frame[k]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    getch();
}

// opt
#include<stdio.h>
#include<conio.h>

void main()
{
    int pages[50], frame[20];
    int n, f, i, j, k;
    int faults = 0, hit;
    int farthest, pos, index;

    clrscr();

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        hit = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }

        if(hit == 0)
        {
            faults++;

            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    frame[j] = pages[i];
                    break;
                }
            }

            if(j == f)
            {
                farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++)
                {
                    index = 9999;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == pages[k])
                        {
                            index = k;
                            break;
                        }
                    }

                    if(index > farthest)
                    {
                        farthest = index;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
            }
        }

        printf("\n%d -> ", pages[i]);
        for(k = 0; k < f; k++)
            printf("%d ", frame[k]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    getch();
}

// lru
#include<stdio.h>
#include<conio.h>

void main()
{
    int pages[50], frame[20];
    int n, f, i, j, k;
    int faults = 0, hit;
    int least, pos, lastUsed;

    clrscr();

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        hit = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }

        if(hit == 0)
        {
            faults++;

            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    frame[j] = pages[i];
                    break;
                }
            }

            if(j == f)
            {
                least = 9999;
                pos = -1;

                for(j = 0; j < f; j++)
                {
                    lastUsed = -1;

                    for(k = i - 1; k >= 0; k--)
                    {
                        if(frame[j] == pages[k])
                        {
                            lastUsed = k;
                            break;
                        }
                    }

                    if(lastUsed < least)
                    {
                        least = lastUsed;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
            }
        }

        printf("\n%d -> ", pages[i]);
        for(k = 0; k < f; k++)
            printf("%d ", frame[k]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    getch();
}