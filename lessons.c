#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Ошибка\n");
        return 1;
    }
    
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Ошибка\n");
        return 1;
    }
    
    int n, m;
    fscanf(f, "%d%d", &n, &m);
    
    int a[100][100];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[i][j] < 0) {
                sum += a[i][j];
            }
        }
    }

    int max_j = 0;
    for (int j = 1; j < m; j++) {
        if (a[2][j] > a[2][max_j]) {
            max_j = j;
        }
    }

    a[2][max_j] = sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
