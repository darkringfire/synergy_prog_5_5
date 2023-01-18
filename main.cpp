#include <iostream>
#define MAXMN 100
#define MINX (-2)
#define MAXX 7

#define MAXRNDX (MAXX - MINX + 1)

int main() {
    int arr[MAXMN][MAXMN];
    int m, n;
    do {
        printf("Enter number of rows (1..%i):", MAXMN);
        scanf("%i", &n);
    } while (n < 1 || n > MAXMN);
    do {
        printf("Enter number of columns (1..%i):", MAXMN);
        scanf("%i", &m);
    } while (m < 1 || m > MAXMN);

    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            arr[j][i] = rand() % MAXRNDX + MINX;
        }
    }

    printf("\nGenerated array:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%6i", arr[j][i]);
        }
        printf("\n");
    }

    int maxmn = m > n ? m : n;

    for (int j = 0; j < maxmn; j++) {
        for (int i = j + 1; i < maxmn; i++) {
            int tmp = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = tmp;
        }
    }

    printf("\nTransposed array:\n");
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            printf("%6i", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
