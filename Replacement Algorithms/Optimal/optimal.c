
#include <stdio.h>

int main() {
    int n, frames, i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int pageFaults = 0;

    printf("\nPage\tFrames\n");


    for(i = 0; i < n; i++) {

        int found = 0;


        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {

            int replaceIndex = -1;


            for(j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }


            if(replaceIndex == -1) {

                int farthest = -1;

                for(j = 0; j < frames; j++) {

                    int nextUse;

                    for(nextUse = i + 1; nextUse < n; nextUse++) {
                        if(frame[j] == pages[nextUse])
                            break;
                    }

                    if(nextUse == n) {
                        replaceIndex = j;
                        break;
                    }

                    if(nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }
            }

            frame[replaceIndex] = pages[i];
            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for(k = 0; k < frames; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }

        printf("\n");
    }


    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
