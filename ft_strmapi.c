#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
 {
 	unsigned int	i;
 	char			*dest;
 
 	i = 0;
 	if (!s)
 		return (NULL);
 	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
 		return (NULL);
 	while (s[i])
 	{
 		dest[i] = (*f)(i, (char)s[i]);
 		i++;
 	}
 	dest[i] = '\0';
 	return (dest);
 }