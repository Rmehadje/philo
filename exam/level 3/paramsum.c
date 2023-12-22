#include <unistd.h>

void	put_nbr(int nb)
{
	if (nb > 10)
		put_nbr(nb / 10);
	char digit = (nb % 10) + '0';
	write (1, &digit, 1);
}

int main(int argc, char **argv)
{
	(void)argv;

	put_nbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}