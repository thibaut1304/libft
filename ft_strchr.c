/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:13:15 by thhusser          #+#    #+#             */
/*   Updated: 2020/11/04 01:13:15 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char 	car;

	car = (unsigned char)c;
	while (*s)
	{
		if (*s == car)
			return (s);
		s++;
	}
	if (car == 0)
		return (s);
	return (NULL);
}