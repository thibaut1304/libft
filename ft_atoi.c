/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:11:34 by thhusser          #+#    #+#             */
/*   Updated: 2020/11/04 01:11:34 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' ||
		str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

static int	ft_number(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

static int	ft_sign(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[nb] == '-' || str[nb] == '+')
	{
		if (str[nb] == '-')
			i++;
		nb++;
	}
	if (nb > 1)
		return (-1);
	return (i);
}

static int	ft_atoi_plus(int sign, int i, char *str)
{
	int nb;

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

int			ft_atoi(char *str)
{
	int			i;
	long int	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	sign = ft_sign(str);
	if (sign == -1)
		return (0);
	i = sign;
	result = ft_atoi_plus(sign, i, str);
	if (result == 2)
	{
		result = 0;
		while (ft_number(str[i]))
			result = (str[i++] - 48) + result * 10;
		result = (sign % 2) ? -result : result;
	}
	return (result);
}
