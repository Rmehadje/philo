#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n = 0;

	while(*str)
	{
		n = n * 10;
		n = n + *str - '0';
		str++;
	}
	return (n);
}

void	ft_printhex(int n)
{
	int	*hex[] = "0123456789abcdef";

	if (n >= 16)
		ft_printhex(n / 16);
	write(1, &hex[n % 16], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_printhex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}