// problem: https://algospot.com/judge/problem/read/MAXSUM
// hint: dp
// level: moderate
#include <stdio.h>

#define MAX_N_NUMS	100000
#define LOW_NUM		(-100)
#define HIGH_NUM	( 100)
#define LOW_BOUND	(LOW_NUM * MAX_N_NUMS)

#define max(a, b)	((a) > (b)? (a): (b))

inline int getMaxSum(int *elems, int n)
{
	int i, sum;
	int maxSum = LOW_BOUND;

	sum = elems[0];
	for(i = 1; i < n; i++)
	{
		sum = max(elems[i], elems[i]+sum);
		if(sum > maxSum)
			maxSum = sum;
	}

	return maxSum;
}

int main(void)
{
	int c, i, num;
	int elems[MAX_N_NUMS];

	scanf("%d", &c);
	while(c--)
	{
		scanf("%d", &num);
		for(i = 0; i < num; i++)
			scanf("%d", &elems[i]);

		printf("%d\n", getMaxSum(elems, num));
	}

	return 0;
}
