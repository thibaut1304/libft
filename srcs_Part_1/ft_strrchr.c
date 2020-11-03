#include "../includes/libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char 	car;

	i = 0;
	car = (unsigned char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == car)
			return (s + i);
		i--;
	}
	return (NULL);
}