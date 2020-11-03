#include "../includes/libft.h"

void 	*ft_memalloc(size_t size)
{
	void			*temp;
	unsigned char	*temp_ptr;
	size_t			i;

	i = 0;

	if (!(temp = malloc(size)))
		return (NULL);
	temp_ptr = (unsigned char *) temp;
	while (i < size)
		temp_ptr[i++] = 0;
	return (temp);
}