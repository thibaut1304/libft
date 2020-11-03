#include "../includes/libft.h"

char	*ft_strchr(char *s, int c)
{
	char 	car;

	car = (unsigned char)c;
	while (*s)
	{
		if (*s == car)
			return (s);
		s++;
	}
	if (car == 0)
		return (s);
	return (NULL);
}