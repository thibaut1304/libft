#include "./includes/libft.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>

// "\033[38;5;231m" blanc
// "\033[38;5;196m" rouge
// "\033[38;5;2m" vert
// "\033[38;5;3m" jaune

void	ft_funtion(char *s)
{

		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		else if (*s >= 'A' && *s <= 'Z')
			*s += 32;
}

int		ft_compare_str(char *dest, char *t_dest)
{
	int i;

	i = 0;
	while (t_dest[i])
	{
		if (dest[i] != t_dest[i])
			return (1);
		i++;
	}
	i = 0;
	while (dest[i])
	{
		if (dest[i] != t_dest[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}


int main()
{
		printf("\n");
	{
		printf("%s\n", ft_strtrim("Salut"));
		return 0;
		{
		char *src = "the cake is a lie !\0I'm hidden lol\r\n";		
		char buff[0xF0];		
		char *ret = ft_memmove(buff, src, 100);

		if (ret == ((void *)0))
			printf("Faux\n");
		else
			printf("OK\n");
		printf("%s\n", ret);
	}
		printf("\033[38;5;3m" "FT_STRLCPY :\n");

		char src[10]	= "ab121";
		char dest[10]	= "12123123";

		unsigned int 	nb2 = 8;

		printf("\033[38;5;231m" "Str: %zu\n", ft_strlcpy(dest, src, nb2));
		printf("Str officeil: %zu\n", strlcpy(dest, src, nb2));
		return (0);
	}
	{
	/*---------------------------------------------------------------------------------*/
		char str[] = "Voici une grande phrase pour tester ce memset qui ma fait\\0";
		char str_2[] = "Voici une grande phrase pour tester ce memset qui ma fait\\0";
		int i = 4 * sizeof(char);
		int n_octet = 2;
		char octet = '.';
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_MEMSET :\n");
		ft_memset(str_2 + n_octet, octet, i);
		memset(str + n_octet, octet, i); 
		if (ft_compare_str(str_2, str) == 1)
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", str_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", str);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", str_2);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char 	str[] = "je suis un grand test";
		char 	str_2[] = "je suis un grand test";
		size_t	n = 0;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_BZERO :\n");

		ft_bzero(str_2, n);
		bzero(str, n);
		if (!ft_compare_str(str, str_2))
			printf("\033[38;5;2m" "OK ==> %s\n", str_2);
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", str_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", str);
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
	    char *dest = NULL;
	    char *dest_2 = NULL;
	    int n = sizeof(char) * 5;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_MEMCPY :\n");

	    dest = malloc(n + 1);
	    dest_2 = malloc(n + 1);

	/*---------------------------------------------------------------------------------*/
	   	memcpy(dest, ft_strdup("salut"), n);
	   	ft_memcpy(dest_2, ft_strdup("salut"), n);
	/*---------------------------------------------------------------------------------*/
	    dest[n + 1] = 0;
	    dest_2[n + 1] = 0;
	    if (ft_compare_str(dest, dest_2))
	    {
			printf("\033[38;5;196m" "NOK =============> %s\n", dest_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", dest);
	    }
	    else
			printf("\033[38;5;2m" "OK ==> %s\n", dest_2);
	    free(dest);
	    free(dest_2);
	}
	printf("\n");
	// scanf("%*c");

	{
		printf("\033[38;5;3m" "FT_MEMCCPY :\n");
		void	*mem;
		void	*membis;
		int arg;

		arg = 0;	

		if (!(mem = malloc(sizeof(*mem) * 30)))
			return (0);
		memset(mem, '0', 29);
		((char*)mem)[29] = '\0';
		membis = mem;
		printf("\033[38;5;231m" "4 choix possible de test 1 à 4.\n");
		// scanf("%d", &arg);
		if (arg == 1)
		{
			printf("Le Resultat attendu : \n00000000000000000000\nabcdefghi00000000000000000000\n");
			if (!(mem = ft_memccpy(mem, "abcdefghijklmnoparstuvwxyz", 'i', 20)))
				ft_print_result("NULL");
			else
			{
				printf("Resulat :\n");
				ft_print_result(mem);
				write(1, "\n", 1);
				ft_print_result(membis);
				write(1, "\n", 1);
			}
		}
		else if (arg == 2)
		{
			printf("Le Resultat attendu : \nNULL\n");
			if (!(mem = ft_memccpy(mem, "abcdefghijklmnoparstuvwxyz", 'r', 3)))
				ft_print_result("NULL");
			else
			{
				printf("Resulat :\n");
				ft_print_result(mem);
				write(1, "\n", 1);
				ft_print_result(membis);
				write(1, "\n", 1);
			}
		}
		else if (arg == 3)
		{
			printf("Le Resultat attendu : \n000\nabcdefghijklmnoparstuvwxyz000\n");
			if (!(mem = ft_memccpy(mem, "abcdefghijklmnoparstuvwxyz", 'z', 26)))
				ft_print_result("NULL");
			else
			{
				printf("Resulat :\n");
				ft_print_result(mem);
				write(1, "\n", 1);
				ft_print_result(membis);
				write(1, "\n", 1);
			}
		}
		else if (arg == 4)
		{
			printf("Le Resultat attendu : \n00000000000000000000000000\nabc00000000000000000000000000\n");
			if (!(mem = ft_memccpy(mem, "abcdefghijkl", 'c', 20)))
				ft_print_result("NULL");
			else
			{
				printf("Resulat :\n");
				ft_print_result(mem);
				write(1, "\n", 1);
				ft_print_result(membis);
				write(1, "\n", 1);
			}
		}

	// /*---------------------------------------------------------------------------------*/
	//     char *dest;
	//     char *dest_2;
	//     char test[] = "Salutm";
	//     int c = 'l';
	//     size_t n = 3;
	// /*---------------------------------------------------------------------------------*/
	// 	printf("\033[38;5;3m" "FT_MEMCCPY :\n");
	//     if (!(dest = malloc(sizeof(*dest) * 15)))
	// 		return (0);
	// 	memset(dest, '0', 14);
	// 	((char*)dest)[14] = '\0';
	// 	dest_2 = dest;
	// 	dest = ft_memccpy(dest, test, c, n);
	// 	if (dest != NULL)
	// 		printf("%s\n", dest_2);
	// 	else
	// 		printf("%s\n", dest);
	// 	dest_2 = dest;
	// 	dest = memccpy(dest, test, c, n);
	// 	if (dest != NULL)
	// 		printf("%s\n", dest_2);
	// 	else
	// 		printf("%s\n", dest);
	// 	dest_2 = dest;
	// 	if (!(dest = ft_memccpy(dest, "Salutm", 't', 3)))
	// 		ft_print_result("NULL");
	// 	else
	// 	{
	// 		ft_print_result(dest);
	// 		write(1, "\n", 1);
	// 		ft_print_result(dest_2);
		// }

	//     if (ft_compare_str(dest, dest_2))
	//     {
	// 		printf("\033[38;5;196m" "NOK =============> %s\n", dest_2);
	// 		printf("\033[38;5;196m" "Resultat attendu : %s\n", dest);
	//     }
	//     else
	// 		printf("\033[38;5;2m" "OK ==> %s\n", dest_2);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char 	src[50] = "aluts";
		char 	dest[50] = "S";
		char 	dest_2[50] = "S";
		size_t 	n = 0;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_MEMMOVE :\n");
		while (n != 6)
		{
			if (ft_compare_str(memmove(dest+1, src, n), ft_memmove(dest_2+1, src, n)) == 0)
				printf("\033[38;5;2m" "OK ==> [%s]\n", dest_2);
			else
			{
				printf("\033[38;5;196m" "NOK =============> [%s]\n", dest_2);
				printf("\033[38;5;196m" "Resultat attendu : [%s]\n", dest);
			}
			n++;
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		size_t 	n = 5;
		char	s[] = "Salut";
		int 	c = 'l';
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_MEMCHR :\n");
		while (n != 0)
		{
			if (memchr(s, c, n) == NULL && ft_memchr(s, c, n) == NULL)
				printf("\033[38;5;2m" "OK ==> %s\n", ft_memchr(s, c, n));
			else if (memchr(s, c, n) != NULL && ft_memchr(s, c, n) == NULL)
			{
				printf("\033[38;5;196m" "NOK =============> %s\n", ft_memchr(s, c, n));
				printf("\033[38;5;196m" "Resultat attendu : %s\n", memchr(s, c, n));
			}
			else if (memchr(s, c, n) == NULL && ft_memchr(s, c, n) != NULL)
			{	
				printf("\033[38;5;196m" "NOK =============> %s\n", ft_memchr(s, c, n));
				printf("\033[38;5;196m" "Resultat attendu : %s\n", memchr(s, c, n));
			}
			else if (ft_compare_str(memchr(s, c, n), ft_memchr(s, c, n)) == 0)
				printf("\033[38;5;2m" "OK ==> %s\n", ft_memchr(s, c, n));
			else
			{
				printf("\033[38;5;196m" "NOK =============> %s\n", ft_memchr(s, c, n));
				printf("\033[38;5;196m" "Resultat attendu : %s\n", memchr(s, c, n));
			}
			n--;
		}
			
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char 	s1[] = "Salut";
		char 	s2[] = "Salut";
		char 	s1bis[] = "Saxut";
		char 	s2bis[] = "Salut";
		size_t	n = 4;
		size_t 	x = 2;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_MEMCMP :\n");
		if (memcmp(s1, s2, n) == ft_memcmp(s1, s2, n))
			printf("\033[38;5;2m" "OK ==> %d\n", ft_memcmp(s1, s2, n));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_memcmp(s1, s2, n));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", memcmp(s1, s2, n));
		}
		if (memcmp(s1bis, s2bis, n) == ft_memcmp(s1bis, s2bis, n))
			printf("\033[38;5;2m" "OK ==> %d\n", ft_memcmp(s1bis, s2bis, n));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_memcmp(s1bis, s2bis, n));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", memcmp(s1bis, s2bis, n));
		}
		if (memcmp(s1bis, s2bis, x) == ft_memcmp(s1bis, s2bis, x))
			printf("\033[38;5;2m" "OK ==> %d\n", ft_memcmp(s1bis, s2bis, x));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_memcmp(s1bis, s2bis, x));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", memcmp(s1bis, s2bis, x));
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	str[] = "Test strlen total";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRLEN :\n");

		int x = 0;
		while (str[x])
			x++;
		if (ft_strlen(str) == x)
			printf("\033[38;5;2m" "OK ==> %d\n", x);
		else
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_strlen(str));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", x);
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	src[] = "Salut";
		char	src_2[] = "Salut";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRDUP :\n");

		if (ft_compare_str(ft_strdup(src_2), strdup(src)) == 1)
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", ft_strdup(src_2));
			printf("\033[38;5;196m" "Resultat attendu : %s\n", strdup(src));
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", ft_strdup(src));
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	dest[] = "Bonjour";
		char	dest_2[] = "Bonjour";
		char	src[] = "Salut";
		char	src_2[] = "Salut";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRCPY :\n");

		if (ft_compare_str(strcpy(dest, src), ft_strcpy(dest_2, src_2)) == 1)
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", dest_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", dest);
		}
		else 
			printf("\033[38;5;2m" "OK ==> %s\n", dest_2);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	dest[] = "hello";
		char	dest_2[] = "hello";
		char	src[] = "WORLD";
		char	src_2[] = "WORLD";
		unsigned int 	n = 3;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRNCPY :\n");

		if (ft_compare_str(strncpy(dest, src, n), ft_strncpy(dest_2, src_2, n)) == 1)
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", dest_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", dest);
		}
		else 
			printf("\033[38;5;2m" "OK ==> %s\n", dest_2);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	dest[11] = "Salut";
		char	src[] = "hello";
		char	dest_2[11] = "Salut";
		char	src_2[] = "hello";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRCAT :\n");

		if (ft_compare_str(ft_strcat(dest_2, src_2), strcat(dest, src)) == 1)
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", dest_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", dest);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", dest_2);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	dest[11] = "Salut";
		char	src[] = "hello";
		char	dest_2[11] = "Salut";
		char	src_2[] = "hello";
		unsigned int n = 2;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRNCAT :\n");

		if (ft_compare_str(ft_strncat(dest_2, src_2, n), strncat(dest, src, n)) == 1)
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", dest_2);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", dest);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", dest_2);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char dest[50] = "Salut";
		char dest_2[50] = "Salut";
		char src[] = "Bonjour";
		size_t size = 6;
		size_t size_2 = 6;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRLCAT :\n");
		printf("Function 	: %lu\n", strlcat(dest, src, size));
		printf("Function_2 	: %zu\n", ft_strlcat(dest_2, src, size_2));
		printf("Dest 		: %s\n", dest);
		printf("Dest_2 		: %s\n", dest_2);
		printf("Src 		: %s\n", src);
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		int 	c = 'l';
		int 	x = ' ';
		char 	src[] = "Salut";
		char 	src_2[] = "Salut";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRCHR :\n");
		if (ft_compare_str(strchr(src, c), ft_strchr(src, c)) == 0)
			printf("\033[38;5;2m" "OK ==> %s\n", ft_strchr(src, c));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", ft_strchr(src, c));
			printf("\033[38;5;196m" "Resultat attendu : %s\n", strchr(src, c));
		}
		if (strchr(src_2, x) == NULL && ft_strchr(src_2, x) == NULL)
			printf("\033[38;5;2m" "OK ==> %s\n", ft_strchr(src_2, c));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", ft_strchr(src_2, x));
			printf("\033[38;5;196m" "Resultat attendu : %s\n", strchr(src_2, x));
		}

	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		int 	c = 'l';
		int 	x = ' ';
		char 	src[] = "Salutlut";
		char 	src_2[] = "Salutlut";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRRCHR :\n");
		if (ft_compare_str(strrchr(src, c), ft_strrchr(src, c)) == 0)
			printf("\033[38;5;2m" "OK ==> %s\n", ft_strrchr(src, c));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", ft_strrchr(src, c));
			printf("\033[38;5;196m" "Resultat attendu : %s\n", strrchr(src, c));
		}
		if (strrchr(src_2, x) == NULL && ft_strrchr(src_2, x) == NULL)
			printf("\033[38;5;2m" "OK ==> %s\n", ft_strrchr(src_2, c));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", ft_strrchr(src_2, x));
			printf("\033[38;5;196m" "Resultat attendu : %s\n", strrchr(src_2, x));
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char 	src[] = "Je suis une gra grandee grande chaine de caractere";
		char 	to_find[] = "grande";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRSTR :\n");
		if (!(ft_compare_str(strstr(src, to_find), ft_strstr(src, to_find))))
			printf("\033[38;5;2m" "OK ==> %s\n", ft_strstr(src, to_find));
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", ft_strstr(src, to_find));
			printf("\033[38;5;196m" "Resultat attendu : %s\n", strstr(src, to_find));
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char 	src[] = "Je suis une gra grandee grande chaine de caractere";
		char 	to_find[] = "grande";
		size_t	n = 10;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRNSTR :\n");
		while (n < 31)
		{
			if (strnstr(src, to_find, n) == NULL && ft_strnstr(src, to_find, n) == NULL)
				printf("\033[38;5;2m" "OK ==> %s\n", ft_strnstr(src, to_find, n));
			else if (strnstr(src, to_find, n) != NULL && ft_strnstr(src, to_find, n) == NULL)
			{
				printf("\033[38;5;196m" "NOK =============> %s\n", ft_strnstr(src, to_find, n));
				printf("\033[38;5;196m" "Resultat attendu : %s\n", strnstr(src, to_find, n));
			}	
			else if (strnstr(src, to_find, n) == NULL && ft_strnstr(src, to_find, n) != NULL)
			{
				printf("\033[38;5;196m" "NOK =============> %s\n", ft_strnstr(src, to_find, n));
				printf("\033[38;5;196m" "Resultat attendu : %s\n", strnstr(src, to_find, n));
			}
			else if (ft_compare_str(strnstr(src, to_find, n), ft_strnstr(src, to_find, n)))
			{
				printf("\033[38;5;196m" "NOK =============> %s\n", ft_strnstr(src, to_find, n));
				printf("\033[38;5;196m" "Resultat attendu : %s\n", strnstr(src, to_find, n));
			}
			else
				printf("\033[38;5;2m" "OK ==> %s\n", ft_strnstr(src, to_find, n));
			n += 5;
		}
		// printf("Officiel	: %s\n", strnstr(src, to_find, n));
		// printf("Perso		: %s\n", ft_strnstr(src, to_find, n));
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	s1[] = "Bonj";
		char	s2[] = "Bonjxur";
		char	s1_2[] = "Bonj";
		char	s2_2[] = "Bonjxur";

		char	str[] = "Salut";
		char	str_2[] = "Salut";
		char	str2[] = "Salut";
		char	str2_2[] = "Salut";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRCMP :\n");

		if (ft_strcmp(s1_2, s2_2) != strcmp(s1, s2))
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_strcmp(s1_2, s2_2));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", strcmp(s1, s2));
		}
		else
			printf("\033[38;5;2m" "OK ==> %d\n", ft_strcmp(s1_2, s2_2));

		if (ft_strcmp(str2, str2_2) != strcmp(str, str_2))
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_strcmp(str2, str2_2));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", strcmp(str, str_2));
		}
		else
			printf("\033[38;5;2m" "OK ==> %d\n", ft_strcmp(str2, str2_2));
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	s1[] = "Bonj";
		char	s2[] = "Bonjxur";
		char	s1_2[] = "Bonj";
		char	s2_2[] = "Bonjxur";

		char	str[] = "Salut";
		char	str_2[] = "Salut";
		char	str2[] = "Salut";
		char	str2_2[] = "Salut";
		unsigned int n = 5;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRNCMP :\n");

		if (ft_strncmp(s1_2, s2_2, n) != strncmp(s1, s2, n))
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_strncmp(s1_2, s2_2, n));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", strncmp(s1, s2, n));
		}
		else
			printf("\033[38;5;2m" "OK ==> %d\n", ft_strncmp(s1_2, s2_2, n));

		if (ft_strncmp(str2, str2_2, n) != strncmp(str, str_2, n))
		{
			printf("\033[38;5;196m" "NOK =============> %d\n", ft_strncmp(str2, str2_2, n));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", strncmp(str, str_2, n));
		}
		else
			printf("\033[38;5;2m" "OK ==> %d\n", ft_strncmp(str2, str2_2, n));
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char	str_2[] = "   	+--+-2147483648gyhuji78987654";
		char	str[] = "-2147483648";
		char	strbis_2[] = "   	+--+2147483649gyhuji78987654";
		char	strbis[] = "-2147483647";
		char	strr_2[] = "     w12";
		char	strr[] = "0";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_ATOI :\n");
		printf("\033[38;5;231m" "Attendu : %s\t", str);
		printf("\033[38;5;231m" "Attendu : %s\t", strbis);
		printf("\033[38;5;231m" "Attendu : %s\n", strr);
		printf("\033[38;5;231m" "=========>%d\t", ft_atoi(str_2));
		printf("\033[38;5;231m" "=========>%d\t", ft_atoi(strbis_2));
		printf("\033[38;5;231m" "=========>%d\n", ft_atoi(strr_2));
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		int c_1 = '0';
		int c_2 = 'a';
		int c_3 = 'A';
		int c_4 = '*';
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_ISALPHA :\n");

		if (ft_isalpha(c_1) == isalpha(c_1))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_1, c_1, ft_isalpha(c_1));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_1, c_1, ft_isalpha(c_1));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalpha(c_1));			
		}
		if (ft_isalpha(c_2) == isalpha(c_2))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_2, c_2, ft_isalpha(c_2));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_2, c_2, ft_isalpha(c_2));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalpha(c_2));			
		}
		if (ft_isalpha(c_3) == isalpha(c_3))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_3, c_3, ft_isalpha(c_3));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_3, c_3, ft_isalpha(c_3));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalpha(c_3));			
		}
		if (ft_isalpha(c_4) == isalpha(c_4))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_4, c_4, ft_isalpha(c_4));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_4, c_4, ft_isalpha(c_4));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalpha(c_4));			
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		int c_1 = '0';
		int c_2 = 'a';
		int c_3 = '*';
		int c_4 = '9';	
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_ISDIGIT :\n");

		if (ft_isdigit(c_1) == isdigit(c_1))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_1, c_1, ft_isdigit(c_1));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_1, c_1, ft_isdigit(c_1));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isdigit(c_1));			
		}
		if (ft_isdigit(c_2) == isdigit(c_2))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_2, c_2, ft_isdigit(c_2));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_2, c_2, ft_isdigit(c_2));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isdigit(c_2));			
		}
		if (ft_isdigit(c_3) == isdigit(c_3))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_3, c_3, ft_isdigit(c_3));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_3, c_3, ft_isdigit(c_3));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isdigit(c_3));			
		}
		if (ft_isdigit(c_4) == isdigit(c_4))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_4, c_4, ft_isdigit(c_4));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_4, c_4, ft_isdigit(c_4));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isdigit(c_4));			
		}
	}
	printf("\n");
	// scanf("%*c");
	{

	/*---------------------------------------------------------------------------------*/
		int c_1 = '0';
		int c_2 = 'a';
		int c_3 = '*';
		int c_4 = '9';	
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_ISALNUM :\n");

		if (ft_isalnum(c_1) == isalnum(c_1))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_1, c_1, ft_isalnum(c_1));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_1, c_1, ft_isalnum(c_1));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalnum(c_1));			
		}
		if (ft_isalnum(c_2) == isalnum(c_2))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_2, c_2, ft_isalnum(c_2));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_2, c_2, ft_isalnum(c_2));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalnum(c_2));			
		}
		if (ft_isalnum(c_3) == isalnum(c_3))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_3, c_3, ft_isalnum(c_3));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_3, c_3, ft_isalnum(c_3));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalnum(c_3));			
		}
		if (ft_isalnum(c_4) == isalnum(c_4))
			printf("\033[38;5;2m" "OK (%d-%c)==> %d\n", c_4, c_4, ft_isalnum(c_4));
		else
		{
			printf("\033[38;5;196m" "NOK (%d-%c)=======> %d\n", c_4, c_4, ft_isalnum(c_4));
			printf("\033[38;5;196m" "Resultat attendu : %d\n", isalnum(c_4));			
		}
	}
	printf("\n");
	// scanf("%*c");
	{
		int i = 0;
		int x = 0;
		int y = 0;
		printf("\033[38;5;3m" "FT_ISASCII :\n");

		while (i <= 255)
		{
			if (!(ft_isascii(i) == isascii(i)))
			{
				x = 1;
				y++;
			}
			if (x == 1)
				printf("\033[38;5;196m" "NOK (%c)=======> %d\n", i, ft_isascii(i));
			x = 0;
			i++;
		}
		if (y == 0)
			printf("\033[38;5;2m" "OK\n");
	}
	printf("\n");
	// scanf("%*c");
	{
		int i = 0;
		int x = 0;
		int y = 0;
		printf("\033[38;5;3m" "FT_ISPRINT :\n");

		while (i <= 255)
		{
			if (!(ft_isprint(i) == isprint(i)))
			{
				x = 1;
				y++;
			}
			if (x == 1)
				printf("\033[38;5;196m" "NOK (%c)=======> %d\n", i, ft_isprint(i));
			x = 0;
			i++;
		}
		if (y == 0)
			printf("\033[38;5;2m" "OK\n");
	}
	printf("\n");
	// scanf("%*c");
	{
		int i = 0;
		int x = 0;
		int y = 0;
		printf("\033[38;5;3m" "FT_TOUPPER :\n");

		while (i <= 255)
		{
			if (!(ft_toupper(i) == toupper(i)))
			{
				x = 1;
				y++;
			}
			if (x == 1)
				printf("\033[38;5;196m" "NOK (%c)=======> %c\n", i, ft_toupper(i));
			x = 0;
			i++;
		}
		if (y == 0)
			printf("\033[38;5;2m" "OK\n");
	}
	printf("\n");
	// scanf("%*c");
	{
		int i = 0;
		int x = 0;
		int y = 0;
		printf("\033[38;5;3m" "FT_TOLOWER :\n");

		while (i <= 255)
		{
			if (!(ft_tolower(i) == tolower(i)))
			{
				x = 1;
				y++;
			}
			if (x == 1)
				printf("\033[38;5;196m" "NOK (%c)=======> %c\n", i, ft_tolower(i));
			x = 0;
			i++;
		}
		if (y == 0)
			printf("\033[38;5;2m" "OK\n");
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		char 	str[] = "Voici ma chaine de caractere";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_PUTSTR | FT_PUTCHAR :\n");

		printf("\033[38;5;231m" "Resultat attendu : \nVoici ma chaine de caractere\n");
		printf("\033[38;5;231m" "Resultat :\n");
		ft_putstr(str);
		printf("\n");

	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		int nb_2 = 2147483647;
		int nb1_2 = -2147483648;
		int nb2_2 = -42;
		int nb3_2 = 42;
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_PUTNBR :\n");

		printf("\033[38;5;231m" "Attendu : %d\n", nb_2);
		ft_putnbr(nb_2);
		printf( "\n" );
		printf("\033[38;5;231m" "Attendu : %d\n", nb1_2);
		ft_putnbr(nb1_2);
		printf("\n");
		printf("\033[38;5;231m" "Attendu : %d\n", nb2_2);
		ft_putnbr(nb2_2);
		printf("\n");
		printf("\033[38;5;231m" "Attendu : %d\n", nb3_2);
		ft_putnbr(nb3_2);
		printf("\n");
	}
	printf("\n");
	// scanf("%*c");
	{

	/*---------------------------------------------------------------------------------*/
		char dest[] = "SsAaLlUuTt";
		char src[] = "sSaAlLuUtT";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_STRITER :\n");

		ft_striter(dest, &ft_funtion);
		if (ft_compare_str(src, dest) == 0)
			printf("\033[38;5;2m" "OK ==> %s\n", dest);
		else
		{
			printf("\033[38;5;196m" "NOK =============> %s\n", dest);
			printf("\033[38;5;196m" "Resultat attendu : %s\n", src);
		}
	}
	printf("\n");
	// scanf("%*c");
	{
	/*---------------------------------------------------------------------------------*/
		int nb1 = 1234;
		int nb2 = -1234;
		int nb3 = 2147483647;
		int nb4 = -2147483648;
		char *result_1 = "1234";
		char *result_2 = "-1234";
		char *result_3 = "2147483647";
		char *result_4 = "-2147483648";
	/*---------------------------------------------------------------------------------*/
		printf("\033[38;5;3m" "FT_ITOA :\n");
		
		if (ft_compare_str(result_1, ft_itoa(nb1)))
		{
			printf("\033[38;5;196m" "NOK\n");
			printf("\033[38;5;196m" "Resultat attendu : %s\n", result_1);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", ft_itoa(nb1));

		if (ft_compare_str(result_2, ft_itoa(nb2)))
		{	
			printf("\033[38;5;196m" "NOK\n");
			printf("\033[38;5;196m" "Resultat attendu : %s\n", result_2);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", ft_itoa(nb2));

		if (ft_compare_str(result_3, ft_itoa(nb3)))
		{
			printf("\033[38;5;196m" "NOK\n");
			printf("\033[38;5;196m" "Resultat attendu : %s\n", result_3);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", ft_itoa(nb3));

		if (ft_compare_str(result_4, ft_itoa(nb4)))
		{
			printf("\033[38;5;196m" "NOK\n");
			printf("\033[38;5;196m" "Resultat attendu : %s\n", result_4);
		}
		else
			printf("\033[38;5;2m" "OK ==> %s\n", ft_itoa(nb4));
	}
	printf("\n");
	// scanf("%*c");






	return (0);
}