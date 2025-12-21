#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {   // **returnColumnSizes - actual pointer to pointer.
    *returnSize = numRows;

    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));   // allocating memory to  pointer . here , **returncolumnsize points to  the a[] after doing this. 
    int **result = (int **)malloc(numRows * sizeof(int*));      // allocating memory to result . this will be returned.

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        result[i] = malloc((i + 1) * sizeof(int));

        result[i][0] = 1;
        result[i][i] = 1;

        for (int j = 1; j < i; j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }

    return result;
}

int main() {
    int **a;
    int returnSize;
    int *returnColumnSizes;

    a = generate(5, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < returnSize; i++) {
        free(a[i]);
    }
    free(a);
    free(returnColumnSizes);

    return 0;
}
