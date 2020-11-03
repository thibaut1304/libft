#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t src_size;
	size_t dest_size;
	size_t i;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (size == 0)
		return (src_size);
	while (src[i] && dest_size + i + 1 < size)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	if (dest_size > size)
	{
		return (src_size + size);
	}
	else
	{
		dest[dest_size + i] = 0;
	}
	return (src_size + dest_size);
}