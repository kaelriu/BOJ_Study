#include<stdio.h>
#include<stdlib.h>

void quickSort(int arr[], int left, int right);

int main(void)
{
	int *temp;
	int N;
	int i;

	scanf("%d", &N);

	temp = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) scanf("%d", &temp[i]);

	quickSort(temp, 0, N - 1);

	if (N % 2)
	{
		printf("%d", temp[N / 2] * temp[N / 2]);
	}
	else
	{
		printf("%d", temp[0] * temp[N - 1]);
	}

	return 0;
}

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}
