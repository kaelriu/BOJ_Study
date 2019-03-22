#include<stdio.h>

#define MAX 250000

int inputseq[MAX];
int sortseq[MAX];

void quickSort(int left, int right);

int main()
{
	int n;
	int i, j;
	int flag = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &inputseq[i]);
	}

	if (flag == 0)
	{
		printf("0");
		return 0;
	}

	j = 0;
	for (i = 0; i < n; i++)
	{
		if (inputseq[i] <= n)
		{
			sortseq[j] = inputseq[i];
			j++;
		}
	}
	j--;

	for (i = 0; i < j - 1; i++)
	{
		if (sortseq[i] > sortseq[i + 1]) flag++;
	}
	if (sortseq[j - 1] > sortseq[0]) flag++;

	quickSort(0,j);

	for(i=0;i<j-1;i++)
	{
		if(inputseq[i]==inputseq[i+1])
		{
			printf("0");
			return 0;
		}
	}

	if (flag == 2) printf("1");
	else printf("0");

	return 0;
}

void quickSort(int left, int right) {
      int i = left, j = right;
      int pivot = inputseq[(left + right) / 2];
      int temp;
      do
      {
        while (inputseq[i] < pivot)
            i++;
        while (inputseq[j] > pivot)
            j--;
        if (i<= j)
        {
            temp = inputseq[i];
            inputseq[i] = inputseq[j];
            inputseq[j] = temp;
            i++;
            j--;
        }
      } while (i<= j);

    /* recursion */
    if (left < j)
        quickSort(left, j);

    if (i < right)
        quickSort(i, right);
}
