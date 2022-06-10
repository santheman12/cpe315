#include <stdio.h>
#include <stdlib.h>

int **matMult (int **C, int **A, int **B, int height, int width);

int main() {

    int c, d, k;
    int sum = 0;

    int size = 3;

    int **A;
    int **B;
    int **C;

    A = (int**)malloc(sizeof(int *) * size);
    B = (int**)malloc(sizeof(int *) * size);
    C = (int**)malloc(sizeof(int *) * size);


    for (c = 0; c < size; c++){
        A[c] = (int * ) malloc(size * sizeof(int));
        for(d = 0; d < size; d++){
            A[c][d] = rand() % 2;
        }
    }

    for (c = 0; c < size; c++){
        B[c] = (int*)malloc(sizeof(int)* size);
        for(d = 0; d < size; d++){
            B[c][d] = rand() % 2;
        }
    }

    
    //calculate c
    C = matMult(C, A, B, size, size);


    // //print A
    // printf("Matrix A: \n");
    // for (c = 0; c < size; c++){
    //     for(d = 0; d < size; d++){
    //         printf("%d\t", A[c][d]);
            
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    // //print B
    // printf("Matrix B: \n");
    // for (c = 0; c < size; c++){
    //     for(d = 0; d < size; d++){
    //         printf("%d\t", B[c][d]);
            
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    //print C
    printf("Matrix C: \n");
    for (c = 0; c < size; c++){
        for(d = 0; d < size; d++){
            printf("%d\t", C[c][d]);
            
        }
        printf("\n");
    }

    return 0;
}

int **matMult (int **C, int **A, int **B, int height, int width){
    int c, d, k;
    int sum = 0;

    int size = width;

    for (int x = 0; x<size; x++){
        C[x] = (int *)malloc(size * sizeof(int));
    }

    for (c = 0; c < size; c++) {
      for (d = 0; d < size; d++) {
          C[c][d] = 0;
         for (k = 0; k < size; k++) {
            C[c][d] += A[c][k] * B[k][d];
         }
      }
   }
    return C;
}