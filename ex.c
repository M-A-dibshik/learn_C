#include "main.h"

void sum()
{
	int a = 1, b = 2, sum = 0;

	printf("%d%d", &a,&b);
	sum = a+b;
	printf("sum = %d\n", sum);
}

void main()
{
	sum();
}
