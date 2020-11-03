#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		j;
	
	j = 0;
	if (to_find[0] == 0)
		return ((char *)str);
	j = ft_strlen(to_find);
	while (*str && len >= j)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, j) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
