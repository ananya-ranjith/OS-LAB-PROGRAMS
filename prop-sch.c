#include <stdio.h>

int main() {
    int n, i;
    float totalWeight = 0, totalCPU;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int task[n];
    float weight[n], cpuShare[n];

    printf("Enter Total CPU Time Available: ");
    scanf("%f", &totalCPU);


    for(i = 0; i < n; i++) {
        task[i] = i + 1;

        printf("\nEnter weight for Task %d: ", i + 1);
        scanf("%f", &weight[i]);

        totalWeight += weight[i];
    }


    for(i = 0; i < n; i++) {
        cpuShare[i] = (weight[i] / totalWeight) * totalCPU;
    }


    printf("\n\nProportional Scheduling\n");

    printf("Task\tWeight\t\tCPU Share\n");


    for(i = 0; i < n; i++) {
        printf("T%d\t%.2f\t\t%.2f\n",
               task[i], weight[i], cpuShare[i]);
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
