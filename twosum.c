#include <stdio.h>
#include <stdlib.h>

void findTwoSum(int array[], int size, int target) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (array[i] + array[j] == target)
            {
                printf("%d and %d\n", i, j);
                return;
            }
        }
    }
    printf("No solution\n");
}

int main() {
    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    if (size <= 0) 
    {
        printf("Length must be greater than 0\n");
        return 1;
    }
    
    int *array = (int *)malloc(size * sizeof(int));
    
    printf("Enter %d number/s:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    
    findTwoSum(array, size, target);

    free(array);
    return 0;
}

