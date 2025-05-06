#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int strengths[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &strengths[i]);
        }

        int max1 = -1, max2 = -1;
        for (int i = 0; i < n; i++) {
            if (strengths[i] > max1) {
                max2 = max1;
                max1 = strengths[i];
            } else if (strengths[i] > max2) {
                max2 = strengths[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (strengths[i] == max1) {
                printf("%d ", max1 - max2);
            } else {
                printf("%d ", strengths[i] - max1);
            }
        }
        printf("\n");
    }

    return 0;
}