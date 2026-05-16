#include <stdio.h>

void readMatrix(int a[10][10], int r, int c) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int a[10][10], int r, int c) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int sum[10][10], int r, int c) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int r2, int c2) {
    int i, j, k;
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int a[10][10], int t[10][10], int r, int c) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }
}

int main() {
    int a[10][10], b[10][10], sum[10][10], mul[10][10], trans[10][10];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    readMatrix(a, r1, c1);

    printf("\n1. Matrix Addition\n2. Matrix Multiplication\n3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if(r1 != r2 || c1 != c2) {
                printf("Addition not possible\n");
            } else {
                printf("Enter elements of Matrix B:\n");
                readMatrix(b, r2, c2);

                addMatrix(a, b, sum, r1, c1);

                printf("Sum Matrix:\n");
                displayMatrix(sum, r1, c1);
            }
            break;

        case 2:
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if(c1 != r2) {
                printf("Multiplication not possible\n");
            } else {
                printf("Enter elements of Matrix B:\n");
                readMatrix(b, r2, c2);

                multiplyMatrix(a, b, mul, r1, c1, r2, c2);

                printf("Multiplication Matrix:\n");
                displayMatrix(mul, r1, c2);
            }
            break;

        case 3:
            transposeMatrix(a, trans, r1, c1);
            printf("Transpose Matrix:\n");
            displayMatrix(trans, c1, r1);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}