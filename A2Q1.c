#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix, int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }
}

void multiplyMatrices(int **mat1, int **mat2, int **result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            *(*(result + i) + j) = 0; 
            for (int k = 0; k < cols1; k++) {
                *(*(result + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);
            }
        }
    }
}

void displayMatrix(int **matrix,int rows,int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));        
            }
        printf("\n");
    }

}

int main(){
    int r1,c1,r2,c2;
//Determine dimensions of Matrix A
printf("enter rows and columns of matrix 1");
scanf("%d%d",&r1,&c1);

//Determine dimensions of Matrix B
printf("enter rows and columns of matrix 2");
scanf("%d%d",&r2,&c2);

//Cond check A.Cols == B.Rows
    if (c1!=r2) {
        printf("Matrix multiplication is not possible with the given dimensions.\n");
        return -1;
    }
//Allocate memory to Mat1 ,Mat2 and Result 
   int **mat1 = (int **)malloc(r1 * sizeof(int *));
    int **mat2 = (int **)malloc(r2 * sizeof(int *));
    int **result = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
    }
    for (int i = 0; i < r2; i++) {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r1; i++) {
        result[i] = (int *)malloc(c2 * sizeof(int));
        }

//Read Inputs to Matrix A & B.
readMatrix(mat1, r1, c1);
readMatrix(mat2, r2, c2);

//Multiply tow matrices C=A*B
multiplyMatrices(mat1, mat2, result, r1, c1, c2);
//Display matrices
displayMatrix(result,r1,c2);
//Free memory – Matrix A 
for (int i = 0; i < r1; i++) {
        free(mat1[i]);
    }
    for (int i = 0; i < r2; i++) {
        free(mat2[i]);
    }
    for (int i = 0; i < r1; i++) {
        free(result[i]);
    }
free(mat1);
//Free memory – Matrix B 
free(mat2);
//Free memory – Matrix C
free(result);



}