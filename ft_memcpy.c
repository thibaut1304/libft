#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}