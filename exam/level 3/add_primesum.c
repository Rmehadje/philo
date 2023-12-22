#include <unistd.h>

int	ft_atoi(char	*str)
{
	int	res = 0;

	while (*str)
		res = res * 10 + *str++ - '0';
	return (res);
}

int	isprime(int		nb)
{
	int	i = 2;
	
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;	
	}
	return (1);
}

void	put_nbr(int		nb)
{
	if (nb >= 10)
		put_nbr(nb / 10);
	char digit = nb % 10 + '0';
	write (1, &digit, 1);
}

int	main (int argc, char **argv)
{

	if (argc == 2)
	{
		int		nbr = ft_atoi(argv[1]);
		int		sum = 0;

		while (nbr > 0)
		{
			if (isprime(nbr))
				sum += nbr;
			nbr--;
		}
		put_nbr(sum);
	}
	write (1, "\n", 1);
	return (0);
}







int		ft_atoi(char	*s)
{
	int		res = 0;

	while (*s)
		res = res * 10 + *s++ - '0';
	return (res);
}

int	isprime(int		nb)
{
	int		i = 2;

	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int		nb)
{
	if (nb >= 10)
		put_nbr(nb / 10);
	char digit = nb % 10 + '0';
	write (1, &digit, 1); 
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	nbr = ft_atoi(argv[1]);
		int	sum = 0;

		while (nbr > 0)
		{
			if (isprime(nbr))
				sum += nbr;
			nbr--;
		}
		put_nbr(sum);
	}
	write (1, "\n", 1);
	return (0);
}