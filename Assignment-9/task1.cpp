#include <stdio.h>
int main() {
    int n = 5, tq = 3; 
    int AT[] = {4, 0, 6, 2, 1};
    int BT[] = {7, 5, 3, 9, 4};
    int remBT[5], CT[5], TAT[5], WT[5];
   for (int i = 0; i < n; i++)
remBT[i] = BT[i];
    int time = 0, completed = 0;
    while (completed < n) {
        int idle = 1;
        for (int i = 0; i < n; i++) {
            if (AT[i] <= time &&remBT[i] > 0) {
                idle = 0;
                if (remBT[i] >tq) {
                    time += tq;
remBT[i] -= tq;
                } else {
                    time += remBT[i];
remBT[i] = 0;
                    CT[i] = time;
                    completed++;
                }
            }
        }
        if (idle)
time++;
    }
printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i]  = TAT[i] - BT[i];
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
    return 0;
}

