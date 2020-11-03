#include "../includes/libft.h"

void	*ft_memset (void *s, char c, size_t n)
{
	unsigned char *s_a;

	s_a = (unsigned char *)s;
	while (n--)
		*s_a++ = (unsigned char)c;
	return (s);
}
