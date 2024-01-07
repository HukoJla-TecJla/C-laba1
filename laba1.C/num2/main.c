#include <stdio.h>
#include <string.h>
#include <math.h>

double geometric(double array[], int count)
{
	double multipl_arg = 1;
	for (int i = 0; i < count; i++)
	{
		multipl_arg *= array[i];
	}
	return pow(multipl_arg, 0.5);
}

double involution(double arg, int degree)
{
	if (degree == 0)
	{
		return 1;
	}
	if (degree % 2 == 0)
	{
		double p = involution(arg, degree / 2);
		return p * p;
	}
	else
	{
		return arg * involution(arg, degree - 1);
	}
}
void main()
{
	double array_arg[] = { 4.56, 13.07, 16.43, 3.66 };
	int count_arg = sizeof(array_arg) / sizeof(array_arg[0]);
	printf("%f\n", geometric(array_arg, count_arg));
	printf("%f", involution(14.56, 3));
}