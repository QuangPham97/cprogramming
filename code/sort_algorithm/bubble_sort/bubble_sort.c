#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SIZE_ARR	20
#define	BUBBLE_SORT	0
#define	INSERTION_SORT 1
#define	SELECTION_SORT 2

void bubble_sort(int a[], const int n);
void insertion_sort(int a[], const int size);
void swap(int a[], int i, int j);
void genarate_random_number(int *a, unsigned int num);
void show_array(int a[], const int size);

void show_array(
	int a[],
	const int size
)
{
	if(size > 0)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}else
	{
		printf("[%s][%d] Size array invalid!",__FUNCTION__, __LINE__);
		return;
	}
}

void genarate_random_number(
	int *a,
	unsigned int num 
)
{
	int i;
	if(num > 0)
	{
		srand((int)time(0));
		for (i = 0; i < num; i++)
		{
			a[i] = 0 + rand() % (100 + 1 - 0);
		}
		printf("\n");
	}else
	{
		printf("[%s][%d] Size array invalid!",__FUNCTION__, __LINE__);
		return;
	}
}
void swap(
	int a[],
	int i,
	int j
)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp; 
}

void bubble_sort(
	int a[], 
	const int n
)
{
	int i, j, need_swap;
	for (i = 0; i < n - 1; i++)
	{
		/* going-up the bottom */
		/* a[0] a[1] ... a[j-1] a[j]*/
		need_swap = 0;
		for (j = n - 1; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a, j , j - 1);
				need_swap = 1;
			}
		}
		if(!need_swap) break;
	}
}

void insertion_sort(
	int a[],
	const int size
)
{
	int i, j;
	for (i = 1; i < size; i++)
	{
		int temp = a[i];
		j = i - 1;
		for (; j > 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void selection_sort(
	int a[],
	const int size
)
{
	int i, j;
	for(i = 0; i < size - 1; i++)
	{
		int imin = i;
		for (j = i + 1; j < size ; j++)
		{
			if(a[j] < a[imin])
				imin = j;
		}
		if(imin != i)
			swap(a, i , imin);
	}
}
int main(int argv, char **argc)
{
	int a[SIZE_ARR];
	genarate_random_number(a, SIZE_ARR);
	printf("Array origin: \n");
	show_array(a, SIZE_ARR);

	unsigned int c;

	scanf("%u", &c);
	printf("Chose: %u\n", c);
	switch (c)
	{
	case BUBBLE_SORT:
		{
			bubble_sort(a, SIZE_ARR);
			printf("\nArray after use bubble sort algorithm: \n");
			show_array(a, SIZE_ARR);
		}
		break;
	case INSERTION_SORT:
		{
			insertion_sort(a, SIZE_ARR);
			printf("\nArray after use insertion sort algorithm: \n");
			show_array(a, SIZE_ARR);
		}	
		break;
	case SELECTION_SORT:
		{
			selection_sort(a, SIZE_ARR);
			printf("\nArray after use insertion sort algorithm: \n");
			show_array(a, SIZE_ARR);
		}
		break;
	default:
		printf("Chose value invalid!");
		break;
	}

	return 0;
}
