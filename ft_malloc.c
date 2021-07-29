/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:45:40 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/29 16:45:40 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t count, size_t size)
{
	char	*mem;

	mem = (char *)malloc(count * size);
	if (!mem)
		return (NULL);
	return (mem);
}
