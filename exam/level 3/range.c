#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i = 0;
	int	len = abs(end - start) + 1;
	int	*res = (int *)malloc(sizeof(int) * len);

	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}

int	*range(int start, int end)
{
	int i = 0;
	int n = abs(start - end) + 1;
	int *range = (int *)malloc(sizeof(int) * n);

	if (range)
	{
		if (start < end)
		{
			range[i] = start;
			start++;
			i++;
		}
		else
		{
			range[i] = start;
			start--;
			i++;
		}
	}
	return (range);
}
  