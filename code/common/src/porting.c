#include "types.h"
void genarate_random_number(
	UInt8 *a,
	UInt8 num 
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
void handler_array(
	UInt8 *a, 
	UInt8 *size
)
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
void show_array(
	UInt8 *a,
	const UInt8 size
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
		printf("[%s][%d] Size array invalid!\n",__FUNCTION__, __LINE__);
		return;
	}
}
