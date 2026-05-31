
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int task[n], period[n], burst[n];


    for(i = 0; i < n; i++) {
        task[i] = i + 1;

        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%d", &burst[i]);

        printf("Task %d Period: ", i + 1);
        scanf("%d", &period[i]);
    }


    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            if(period[i] > period[j]) {

                int temp;

                temp = period[i];
                period[i] = period[j];
                period[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = task[i];
                task[i] = task[j];
                task[j] = temp;
            }
        }
    }


    printf("\n\nRate Monotonic Scheduling (RMS)\n");

    printf("Task\tExecution Time\tPeriod\tPriority\n");

    for(i = 0; i < n; i++) {
        printf("T%d\t%d\t\t%d\t%d\n",
               task[i], burst[i], period[i], i + 1);
    }




    printf("\nExecution Sequence:\n");

    for(i = 0; i < n; i++) {
        printf("T%d", task[i]);

        if(i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
