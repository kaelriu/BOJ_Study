#include<stdio.h>

int main(void)
{
	int n, m;
	int i, j, check;
	int* max;
	int* answer;

	scanf("%d %d", &n, &m);

	check = n;
	max = (int*)malloc(sizeof(int)*n);
	answer = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		max[i] = 1;
	}

	i = 0;
	j = 1;

	while (check != 0)
	{
		while (1)
		{
			if (max[i] == 0) i++;
			else break;

			if (i == n) i = 0;
		}
		if (j == m)
		{
			answer[check-1] = i+1;
			max[i] = 0;
			j = 0;
			check--;
		}
		j++;
		i++;
		if (i == n) i = 0;
	}

	printf("<");

	for (i = n - 1; i >= 1; i--) printf("%d, ", answer[i]);

	printf("%d>", answer[0]);

	return 0;
