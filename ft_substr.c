/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:14:15 by thhusser          #+#    #+#             */
/*   Updated: 2020/11/04 01:14:15 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
 
 	if (!s)
 		return (NULL);
 	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
 		return (NULL);
 	ft_strncpy(dest, (char *)s + start, (int)len);
 	dest[len] = 0;
 	return (dest);
}