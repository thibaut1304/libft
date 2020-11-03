#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
 {
 	int	i;
 	char			*dest;
 
 	i = 0;
 	if (!s)
 		return (NULL);
 	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
 		return (NULL);
 	while (s[i])
 	{
 		dest[i] = (*f)((char)s[i]);
 		i++;
 	}
 	dest[i] = 0;
 	return (dest);
 }