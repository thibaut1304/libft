#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	s_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*s_ptr = 0;
		s_ptr++;
		i++;
	}
}