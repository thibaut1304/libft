
static int		ft_isspace(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' || str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

static int		ft_number(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

static int		ft_sign(char str)
{
	if (str == '-' || str == '+')
		return (1);
	return (0);
}

static int		ft_atoi_plus(int sign, int i, char *str)
{
	int 	nb;

	nb = 0;
	while (str[i] == '9')
	{
		nb++;
		i++;
	}
	if (nb >= 19 && sign == 0)
		return (-1);
	else if (nb >= 19 && sign > 0)
		return (0);
	i -= nb;
	nb = 0;
	while (ft_number(str[i]))
	{
		nb++;
		i++;
	}
	if (nb > 19 && sign == 0)
		return (-1);
	else if (nb > 19 && sign > 0)
		return (0);
	return (2);

}

int		ft_atoi(char *str)
{
	int i;
	long int result;
	int sign;
	int	check;

	i = 0;
	result = 0;
	sign = 0;
	check = 0;
	while (ft_isspace(str[i]))
			i++;
	while (ft_sign(str[i]))
	{
		if (str[i] == '-')
			sign++;
		i++;
		check++;
	}
	if (check > 1)
		return (0);
	result = ft_atoi_plus(sign, i, str);
	if (result == 2)
	{
		result = 0;
		while (ft_number(str[i]))
		{
			result = (str[i] - 48)  + result * 10;
			i++;
		}
		if ((sign % 2))
			result = -result;
		return (result);
	}
	return (result);
}
