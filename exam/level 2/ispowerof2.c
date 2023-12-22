int 	is_power_of_2(unsigned int nb)
{
	if (nb == 0)
		return (0);
	while (nb % 2 == 0)
		nb = nb / 2;
	return ((nb == 1) ? 1 : 0);
}