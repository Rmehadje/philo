#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int i = 0;
	int step = 1;
	int n = end - start;
	
	if (n < 0)
		n *= -1;
	n++;

	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		if (start < end)
			step = -1;
		while (i < n)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}

int		*rrange(int start, int end)
{
	int i = 0;
	int *range;
	int n = end - start;
	int step = 1;

	if (n < 0)
		n *= -1;
	n++;

	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		if (start < end)
			step = - 1;
		while (i < n)
		{
			range[i] = start;
			end = end + step;
			i++;
		}	
	}
	return (range);
}