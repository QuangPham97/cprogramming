#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SIZE_ARR		20
#define	BUBBLE_SORT		0
#define	INSERTION_SORT 	1
#define	SELECTION_SORT 	2
#define QUICK_SORT		3

void bubble_sort(int a[], const int n);
void insertion_sort(int a[], const int size);
void swap(int a[], int i, int j);
void genarate_random_number(int *a, unsigned int num);
void show_array(int a[], const int size);
void handler_array(int a[], int *size);

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
	int *a,
	int i,
	int j
)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp; 
}

void swap_1(int *a, int *b)
{
	int *tmp = malloc(sizeof(int));
	*tmp = *a;
	*a = *b;
	*b = *tmp;
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
int partion(int *a, int high, int low)
{
	int pivot = a[low]; /* Select pivot is first element */
	int left = low + 1; /* Mark left in the next element */
	int right = high;	/* Mark right in the last element */
	while(1)
	{
		/* Nếu phần tử tại vị trí left nhỏ hơn pivot và left nhỏ hơn right thì tăng left cho đến khi gặp phần tử lớn hơn pivot để swap cho a[right] */
		while (left <= right && a[left] < pivot)
		{
			left++;
		}
		/* Nếu phần tử tại vị trí right lớn hơn pivot và right lớn hơn right thì tăng right cho đến khi gặp phần tử nhỏ hơn pivot để swap cho a[left] */
		while (right >= left && a[right] > pivot)
		{
			right--;
		}
		if(left >= right)
			break;/* Nếu không còn phần tử nào thỏa mãn swap thì break khỏi while */
		/* Nếu a[left] > pivot và a[right] < pivot và left nhỏ hơn right thì đổi chỗ */
		swap_1(&(a[left]), &(a[right]));
		left++; /* Dịch con trỏ left lên vị trí tiếp theo để duyệt */
		right--;
	}
	/* Khi break khỏi while(1) thì sẽ đổi chỗ a[left - 1] cho a[low] vì left đã được cộng lên để bằng right nên mới break */
	swap_1(&(a[left-1]), &(a[low]));
	return left - 1; /* Trả về vị trí mà pivot cho lần chia mảng a[0] a[1] pivot a[n-1] a[n] */
}
void quick_sort(
	int *a,
	int high,
	int low
)
{
	if(low < high)
	{
		int pi = partion(a, high, low);
		quick_sort(a, pi-1, low);
		quick_sort(a, high, pi+1);
	}
}
void handler_array(int *a, int *size)
{
	int i,j;
	for(i = 0; i < *size; i++)
	{
		for(j = 0; j < *size; j++)
		{
			if(a[j] == a[i] && j!=i)
			{
				int k;
				for(k = j; k < *size - 1; k++)
				{
					a[k] = a[k+1];
				}
				(*size)--;
			}

		}
	}
}

int main(int argv, char **argc)
{
	int a[SIZE_ARR];
	genarate_random_number(a, SIZE_ARR);
	printf("Array origin: \n");
	printf("Sort Algorithm\n");
	printf("0. Bubble Sort\n");
	printf("1. Insertion Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Quick Sort\n");
	int size = SIZE_ARR;
	handler_array(a, &size);
	show_array(a, size);
	unsigned int c;
	printf("Chose: ");
	scanf("%u", &c);
	switch (c)
	{
	case BUBBLE_SORT:
		{
			bubble_sort(a, size);
			printf("\nArray after use bubble sort algorithm: \n");
			show_array(a, size);
		}
		break;
	case INSERTION_SORT:
		{
			insertion_sort(a, size);
			printf("\nArray after use insertion sort algorithm: \n");
			show_array(a, size);
		}	
		break;
	case SELECTION_SORT:
		{
			selection_sort(a, size);
			printf("\nArray after use insertion sort algorithm: \n");
			show_array(a, size);
		}
		break;
	case QUICK_SORT:
		{
			quick_sort(a,size - 1, 0);
			printf("\nArray after use quick sort algorithm: \n");
			show_array(a, size);
		}
		break;
	default:
		printf("Chose value invalid!");
		break;
	}

	return 0;
}
