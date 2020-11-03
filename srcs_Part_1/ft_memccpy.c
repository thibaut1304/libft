#include "../includes/libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	unsigned char 	*dest_ptr;
	unsigned char 	*src_ptr;
	size_t 			i;

	i = 0;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;

	while (i < n)
	{
		*dest_ptr = *src_ptr;
		if (*src_ptr == (unsigned char)c)
			return (dest + i + 1);
		dest_ptr++;
		src_ptr++;
		i++;
	}
	return (NULL);
}