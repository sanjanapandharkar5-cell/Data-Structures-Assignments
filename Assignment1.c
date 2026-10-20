#include <stdio.h>

void readMatrix(int mat[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void add(int a[10][10], int b[10][10], int res[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int a[10][10], int b[10][10], int res[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transpose(int a[10][10], int res[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[j][i] = a[i][j];
        }
    }
}

int main() {
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2, choice;

    while (1) {
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting\n");
            break;
        }

        if (choice >= 1 && choice <= 3) {
            printf("Enter rows and cols for first matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter elements of first matrix:\n");
            readMatrix(a, r1, c1);

            printf("Enter rows and cols for second matrix: ");
            scanf("%d %d", &r2, &c2);
            printf("Enter elements of second matrix:\n");
            readMatrix(b, r2, c2);
        } else if (choice == 4) {
            printf("Enter rows and cols for matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter elements:\n");
            readMatrix(a, r1, c1);
        } else {
            printf("Invalid choice\n");
            continue;
        }

        switch (choice) {
            case 1: if (r1 == r2 && c1 == c2) {
                      add(a, b, res, r1, c1);
                      printf("Result:\n");
                      printMatrix(res, r1, c1);
                  } else {
                      printf("Matrices cannot be added.\n");
                  }
                  break;

            case 2: if (r1 == r2 && c1 == c2) {
                       subtract(a, b, res, r1, c1);
                       printf("Result:\n");
                       printMatrix(res, r1, c1);
                  } else {
                      printf("Matrices cannot be subtracted.\n");
                  }
                  break;

            case 3: if (c1 == r2) {
                       multiply(a, b, res, r1, c1, c2);
                       printf("Result:\n");
                       printMatrix(res, r1, c2); 
                   } else {
                       printf("Matrices cannot be multiplied.\n");
                  }
                  break;

            case 4:  transpose(a, res, r1, c1);
                     printf("Transpose:\n");
                     printMatrix(res, c1, r1); 
                     break;
        }
    }
    
    return 0;
}
