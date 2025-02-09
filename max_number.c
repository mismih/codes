#include <stdio.h>
#include <stdlib.h>

int max_number(int array[], int lenght);

int main()
{
    int length;
    printf("Enter length: ");
    scanf("%d", &length);
    
    if (length <= 0) 
    {
        printf("Lenght must be greater than 0\n");
        return 1;
    }
    
    int *allocated_list = (int *)malloc(length * sizeof(int));
    
    printf("Enter %d number/s:\n", length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &allocated_list[i]);
    }
    
    int max = max_number(allocated_list, length);
    printf("Max number is: %d\n", max);
    
    free(allocated_list);
}

int max_number(int array[], int lenght)
{
    int *max = &array[0];
    
    for (int i = 1; i < lenght; i++)
    {
        if (*max < array[i])
        {
            max = &array[i];
        }
    }
    
    return *max;
}