#include "libft.h"

void	ft_putstr(char const *str)
{
	int i;
	if (!str)
 		return ;
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}