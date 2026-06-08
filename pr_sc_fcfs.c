#include <stdio.h>

void fcfs(int at[], int bt[], int n)
{
    int wt[20], tat[20], ct[20];
    int i;

    // First process
    wt[0] = 0;
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];

    for(i = 1; i < n; i++)
    {
        // If CPU is idle
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,
               at[i],
               bt[i],
               ct[i],
               wt[i],
               tat[i]);
    }
}

int main()
{
    int n, i;
    int at[20], bt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    fcfs(at, bt, n);

    return 0;
}

// sjf
#include <stdio.h>

void sjf(int at[], int bt[], int n)
{
    int ct[20], wt[20], tat[20];
    int completed[20] = {0};

    int time = 0;
    int done = 0;
    int i, shortest;

    while(done < n)
    {
        shortest = -1;

        // Find shortest arrived process
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(shortest == -1 ||
                   bt[i] < bt[shortest])
                {
                    shortest = i;
                }
            }
        }

        // No process has arrived
        if(shortest == -1)
        {
            time++;
            continue;
        }

        time += bt[shortest];
        ct[shortest] = time;

        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        completed[shortest] = 1;
        done++;
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,
               at[i],
               bt[i],
               ct[i],
               wt[i],
               tat[i]);
    }
}

//srtf
#include <stdio.h>

void srtf(int at[], int bt[], int n)
{
    int rt[20], ct[20], wt[20], tat[20];
    int complete = 0, time = 0;
    int shortest, i;

    // Copy BT into RT
    for(i = 0; i < n; i++)
        rt[i] = bt[i];

    while(complete < n)
    {
        shortest = -1;

        // Find process with shortest remaining time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(shortest == -1 ||
                   rt[i] < rt[shortest])
                {
                    shortest = i;
                }
            }
        }

        // No process has arrived yet
        if(shortest == -1)
        {
            time++;
            continue;
        }

        // Execute for 1 unit of time
        rt[shortest]--;
        time++;

        // Process completed
        if(rt[shortest] == 0)
        {
            complete++;

            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            if(wt[shortest] < 0)
                wt[shortest] = 0;
        }
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               wt[i],
               tat[i]);
    }
}

int main()
{
    int n, i;
    int at[20], bt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    srtf(at, bt, n);

    return 0;
}

// rr
#include <stdio.h>

void roundRobin(int at[], int bt[], int n, int tq)
{
    int rt[20], ct[20], wt[20], tat[20];
    int time = 0, completed = 0;
    int i;

    for(i = 0; i < n; i++)
        rt[i] = bt[i];

    while(completed < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                found = 1;

                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    rt[i] = 0;

                    completed++;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        // CPU Idle
        if(found == 0)
            time++;
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               wt[i],
               tat[i]);
    }
}

int main()
{
    int n, tq, i;
    int at[20], bt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(at, bt, n, tq);

    return 0;
}

// prio
#include <stdio.h>

void priorityScheduling(int at[], int bt[], int pr[], int n)
{
    int ct[20], wt[20], tat[20];
    int completed = 0, time = 0;
    int visited[20] = {0};

    int i, idx, min_pr;

    while(completed < n)
    {
        idx = -1;
        min_pr = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && visited[i] == 0)
            {
                if(pr[i] < min_pr)
                {
                    min_pr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            visited[idx] = 1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               pr[i],
               ct[i],
               wt[i],
               tat[i]);
    }
}

int main()
{
    int n, i;
    int at[20], bt[20], pr[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority of P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    priorityScheduling(at, bt, pr, n);

    return 0;
}
