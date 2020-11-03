#include "../includes/libft.h"

static int		is_c(char c, char charset)
{

	if (charset == c)
		return (1);
	return (0);
}

static char	**count_words(char const *str, char charset, char **tab)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && is_c(str[i], charset) == 0)
			i++;
		words++;
		while (str[i] && is_c(str[i], charset) == 1)
			i++;
	}
	if (!(tab = malloc(sizeof(char*) * words + 1)))
		return (0);
	tab[words] = 0;
	return (tab);
}

static char	**count_letters(char const *str, char charset, char **tab)
{
	int i;
	int index;
	int letters;

	i = 0;
	index = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] && is_c(str[i], charset) == 0)
		{
			letters++;
			i++;
		}
		if (!(tab[index] = malloc(sizeof(char*) * letters + 1)))
			return (0);
		tab[index][letters] = 0;
		index++;
		while (str[i] && is_c(str[i], charset) == 1)
			i++;
	}
	return (tab);
}

static char	**split_copy(char const *str, char charset, char **tab)
{
	int i;
	int index;
	int letters;

	i = 0;
	index = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] && is_c(str[i], charset) == 0)
		{
			tab[index][letters] = str[i];
			letters++;
			i++;
		}
		index++;
		while (str[i] && is_c(str[i], charset) == 1)
			i++;
	}
	return (tab);
}

char	**ft_split(char const *str, char charset)
{
	char **tab;

	if (!str || !charset)
 		return (NULL);
	while (*str && is_c(*str, charset) == 1)
		str++;
	tab = NULL;
	tab = count_words(str, charset, tab);
	tab = count_letters(str, charset, tab);
	tab = split_copy(str, charset, tab);
	return (tab);
}