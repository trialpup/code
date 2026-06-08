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