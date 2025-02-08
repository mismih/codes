#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool has_duplicate();

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

    if(has_duplicate(length, allocated_list))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    free(allocated_list);
}

bool has_duplicate(int new_lenght, int list[])
{
    for (int i = 0; i < new_lenght; i++)
    {
        for (int j = i + 1; j < new_lenght; j++)
        {
            if (list[i] == list[j])
            {
                return true;
            }
        }
    }
    return false;
}