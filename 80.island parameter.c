#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                perimeter += 4;

                if (i > 0 && grid[i-1][j] == 1) perimeter--;
                if (i < gridSize - 1 && grid[i+1][j] == 1) perimeter--;
                if (j > 0 && grid[i][j-1] == 1) perimeter--;
                if (j < gridColSize[i] - 1 && grid[i][j+1] == 1) perimeter--;
            }
        }
    }

    return perimeter;
}

int main() {
    int gridSize = 4;

    // Step 1: allocate grid
    int **grid = (int**)malloc(gridSize * sizeof(int*));
    int *gridColSize = (int*)malloc(gridSize * sizeof(int));

    for (int i = 0; i < gridSize; i++) {
        gridColSize[i] = 4;              // each row has 4 columns
        grid[i] = (int*)malloc(4 * sizeof(int));
    }

    // Step 2: fill the grid
    int temp[4][4] = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < 4; j++)
            grid[i][j] = temp[i][j];

    // Step 3: call function
    printf("Island perimeter = %d\n", islandPerimeter(grid, gridSize, gridColSize));

    // Step 4: free memory
    for (int i = 0; i < gridSize; i++) free(grid[i]);
    free(grid);
    free(gridColSize);

    return 0;
}
