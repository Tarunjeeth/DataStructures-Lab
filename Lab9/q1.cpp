#include <iostream>

void processQueries(int k, int q, int a[], int queries[]) {
    for (int i = 0; i < q; i++) {
        int m = queries[i];
        while (1) {
            int cnt = 0;
            for (int j = 0; j < k; j++) {
                if (a[j] <= m) {
                    cnt++;
                } else {
                    break;
                }
            }
            if (cnt == 0) {
                break; 
            }
            m -= cnt;
        }
        printf("%d ", m);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k, q;
        scanf("%d %d", &k, &q);
        int a[k];
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }
        int queries[q];
        for (int i = 0; i < q; i++) {
            scanf("%d", &queries[i]);
        }
        processQueries(k, q, a, queries); 
    }
    return 0;
}
