
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int task[n], burst[n], deadline[n];


    for(i = 0; i < n; i++) {
        task[i] = i + 1;

        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%d", &burst[i]);

        printf("Task %d Deadline: ", i + 1);
        scanf("%d", &deadline[i]);
    }


    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            if(deadline[i] > deadline[j]) {

                int temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = task[i];
                task[i] = task[j];
                task[j] = temp;
            }
        }
    }

    printf("\n\nEarliest Deadline First (EDF) Scheduling\n");

    printf("Task\tExecution Time\tDeadline\tPriority\n");


    for(i = 0; i < n; i++) {
        printf("T%d\t%d\t\t%d\t\t%d\n",
               task[i], burst[i], deadline[i], i + 1);
    }

       int currentTime = 0;

    printf("\nDeadline Status:\n");

    printf("Task\tCompletion Time\tStatus\n");


    for(i = 0; i < n; i++) {

        currentTime += burst[i];

        if(currentTime <= deadline[i])
            printf("T%d\t%d\t\tMet\n", task[i], currentTime);
        else
            printf("T%d\t%d\t\tMissed\n", task[i], currentTime);
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
