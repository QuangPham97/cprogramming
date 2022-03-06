/***********************************************************
 *      Array Algorithm : Sum of all element
 *                        Search for an element 
 *                        Count number of appearances
 *                        Delete one element
 * 
 * 
 * 
 * **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum_element(int a[], int size)
{
        int i = 0, sum = 0;
        for(; i < size; i++)
        {
                sum += a[i];
        }
        return sum;

}

int *search_element(int a[], int size, int value)
{
        int i = 0;
        int j = 0;
        int *tmp = (int *)malloc(sizeof(int));
        for(; i < size; i++)
        {
                if (a[i] == value)
                {
                        tmp[j++] = i;
                        
                }
        }
        tmp[j] = 0;
        return tmp;
}

int main()
{
        int a[10] = {1, 2, 3, 4, 5, 5, 7, 8, 5, 10};
        int sum = sum_element(a, 10);
        printf("Sum =  %d\n", sum);
        int *pos;
        int index = 0;
        pos = search_element(a, 10, 5);
        printf("Index value 5 position:");
        while (pos[index] != 0)
        {
                printf(" %d ", pos[index]);
                index++;
        }
        
        return EXIT_SUCCESS;
}