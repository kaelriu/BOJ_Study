#include<stdio.h>

#define MAX 100000

void quickSort(int inputseq[], int left, int right);

int main()
{
	int n;
	int i;

	int inputseq[MAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &inputseq[i]);
	}

	int a = -1;
	int temp = 0;
	for (i = 0; i < n; i++)
	{
		if (inputseq[i] <= n)
		{
			temp = (i - inputseq[i] + n) % n;
			if (a < 0) a = temp;
			else if (a != temp)
			{
				printf("0");
				return 0;
			}
		}
	
	}

	quickSort(inputseq, 0, n - 1);

	for (i = 0; i < n - 1; i++)
	{
		if (inputseq[i] == inputseq[i + 1])
		{
			printf("0");
			return 0;
		}
	}
	
	printf("1");

	return 0;
}

void quickSort(int inputseq[], int left, int right) {
	int i = left, j = right;
	int pivot = inputseq[(left + right) / 2];
	int temp;
	do
	{
		while (inputseq[i] < pivot)
			i++;
		while (inputseq[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = inputseq[i];
			inputseq[i] = inputseq[j];
			inputseq[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);


	if (left < j)
		quickSort(inputseq, left, j);

	if (i < right)
		quickSort(inputseq, i, right);
}
