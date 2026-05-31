#include <stdio.h>

int main() {
    int pages, frames, i, j;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages];

    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int pageFaults = 0;
    int index = 0;

    printf("\nPage\tFrames\n");

    for(i = 0; i < pages; i++) {

        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[index] = page[i];
            index = (index + 1) % frames;
            pageFaults++;
        }

        printf("%d\t", page[i]);

        for(j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }

        printf("\n");
    }


    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
