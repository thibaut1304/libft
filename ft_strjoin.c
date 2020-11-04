/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:13:41 by thhusser          #+#    #+#             */
/*   Updated: 2020/11/04 01:13:41 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		size;

	if (!s1 || !s2)
		return (NULL);
	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
	else if (s1)
		size = ft_strlen(s1);
	else if (s2)
		size = ft_strlen(s2);
	else
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
