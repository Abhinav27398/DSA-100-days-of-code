#include <stdio.h>

int main() {
    int m, n;
    int matrix[50][50];

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int isSymmetric = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0)
            break;
    }

    if(isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
