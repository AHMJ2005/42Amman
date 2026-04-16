#include <stdlib.h>

int *rang(int start , int end)
{
	int *arr;
	int i = 0;
	int size;
	if (start > end)
		size = (start - end) + 1;
	else 
		size = (end - start) + 1;
	//printf("%d size = {0}" , size);
	arr = (int *)malloc( (size));
	i = 0;
	while (i < size)
	{
		if (start <= end)
			arr[i++] = start++;
		else if(start >= end)
			arr[i++] = start--;
	}
	arr[i] = '\0';
	return arr;
}
int main()
{
	int *a = rang(0 , -3);
	int i = 0;
	while (i < 4)
	{
	printf("%d\n" , a[i]);
	i++;
	}
}

