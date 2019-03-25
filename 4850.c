#include<stdio.h>


int main()
{
	int N, w, d, sum;

	while(~scanf("%d %d %d %d", &N, &w, &d, &sum))
	{
		int expect = (N*(N - 1) / 2)*w;

		if((expect - sum) / d==0)printf("%d\n", N);
		else printf("%d\n", (expect - sum) / d);
	}

	
	return 0;
}
