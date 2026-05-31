
#include <stdio.h>

int main() {
    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np], allocation[np];

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }


    for(i = 0; i < np; i++) {
        int bestIdx = -1;

        for(j = 0; j < nb; j++) {
            if(block[j] >= process[i]) {

                if(bestIdx == -1 ||
                   block[j] < block[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }

    printf("\nBest Fit Memory Allocation\n");

    printf("Process\tProcess Size\tBlock Allocated\n");


    for(i = 0; i < np; i++) {
        printf("P%d\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }


    return 0;
}
