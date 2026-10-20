#include <stdio.h>
#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_TERMS 100

void printMatrix(int matrix[][3]) {
    for (int i = 0; i <= matrix[0][2]; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
    printf("\n");
}

void sparseToCompact(int a[MAX_ROWS][MAX_COLS], int r, int c, int b[][3]) {
    b[0][0] = r;  
    b[0][1] = c;  
    int k = 1;    

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k = k + 1;
            }
        }
    }
    b[0][2] = k - 1; 
}

void transpose(int b[][3], int c[][3]) {
    c[0][0] = b[0][1]; 
    c[0][1] = b[0][0]; 
    c[0][2] = b[0][2]; 
    
    int k = 1;
    int cols = b[0][1];
    int terms = b[0][2];

    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (b[j][1] == i) {
                c[k][0] = b[j][1];
                c[k][1] = b[j][0];
                c[k][2] = b[j][2];
                k = k + 1;
            }
        }
    }
}

void fastTranspose(int b[][3], int c[][3]) {
    c[0][0] = b[0][1];
    c[0][1] = b[0][0];
    c[0][2] = b[0][2];

    int cols = b[0][1];
    int terms = b[0][2];

    if (terms > 0) {
        int rowTerms[MAX_COLS] = {0};
        int startingPos[MAX_COLS] = {0};

        for (int i = 1; i <= terms; i++) {
            rowTerms[b[i][1]]++;
        }

        startingPos[0] = 1;
        for (int i = 1; i < cols; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        for (int i = 1; i <= terms; i++) {
            int col = b[i][1];
            int j = startingPos[col]++;
            
            c[j][0] = b[i][1];
            c[j][1] = b[i][0];
            c[j][2] = b[i][2];
        }
    }
}

int main() {
    int sparseMatrix[MAX_ROWS][MAX_COLS];
    int compactMatrix[MAX_TERMS][3];
    int simpleTrans[MAX_TERMS][3];
    int fastTrans[MAX_TERMS][3];
    int rows, cols;

    printf("Enter number of rows and columns (max %d x %d): ", MAX_ROWS, MAX_COLS);
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    sparseToCompact(sparseMatrix, rows, cols, compactMatrix);
    printf("\nCompact Matrix\n");
    printMatrix(compactMatrix);

    transpose(compactMatrix, simpleTrans);
    printf("After Simple Transpose\n");
    printMatrix(simpleTrans);

    fastTranspose(compactMatrix, fastTrans);
    printf("After Fast Transpose\n");
    printMatrix(fastTrans);

    return 0;
}
