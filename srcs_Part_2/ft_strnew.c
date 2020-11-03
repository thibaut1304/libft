#include "../includes/libft.h"

char 	*ft_strnew(size_t size)
{
	size_t	i;
	char 	*new;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}