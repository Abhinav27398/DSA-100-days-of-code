#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], merged[200];
    int i = 0, j = 0, k = 0;


    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);

    for (j = 0; j < q; j++) {
        scanf("%d", &b[j]);
    }

    i = 0;
    j = 0;

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    while (i < p) {
        merged[k++] = a[i++];
    }

    while (j < q) {
        merged[k++] = b[j++];
    }

    for (i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
