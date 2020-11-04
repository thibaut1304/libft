int		ft_compare_str(char *dest, char *t_dest)
{
	int i;

	i = 0;
	while (t_dest[i])
	{
		if (dest[i] != t_dest[i])
			return (1);
		i++;
	}
	i = 0;
	while (dest[i])
	{
		if (dest[i] != t_dest[i])
			return (1);
		i++;
	}
	return (0);
}