#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    *returnSize = codeSize;
    int* result = (int*)malloc(sizeof(int) * codeSize);

    for (int i = 0; i < codeSize; i++) {
        int sum = 0;

        if (k > 0) {
            for (int offset = 1; offset <= k; offset++) {
                sum += code[(i + offset) % codeSize];
            }
        } else if (k < 0) {
            for (int offset = 1; offset <= -k; offset++) {
                sum += code[(i - offset + codeSize) % codeSize];
            }
        } 
        result[i] = sum;
    }

    return result;
}

// Example usage
int main() {
    int code[] = {5, 7, 1, 4};
    int k = 2;
    int returnSize;
    int* decrypted = decrypt(code, 4, k, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", decrypted[i]);
    }
    printf("\n");

    free(decrypted);
    return 0;
}
