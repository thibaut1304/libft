NAME	=	libft.a

SRCS	=	./srcs_Part_1/ft_strcat.c \
			./srcs_Part_1/ft_strcpy.c \
			./srcs_Part_1/ft_strdup.c \
			./srcs_Part_1/ft_strlen.c \
			./srcs_Part_1/ft_strncat.c \
			./srcs_Part_1/ft_strncpy.c \
			./srcs_Part_1/ft_memset.c \
			./srcs_Part_1/ft_strcmp.c \
			./srcs_Part_1/ft_strncmp.c \
			./srcs_Part_1/ft_atoi.c \
			./srcs_Part_1/ft_isalpha.c \
			./srcs_Part_1/ft_isdigit.c \
			./srcs_Part_1/ft_isalnum.c \
			./srcs_Part_1/ft_isascii.c \
			./srcs_Part_1/ft_isprint.c \
			./srcs_Part_1/ft_toupper.c \
			./srcs_Part_1/ft_tolower.c \
			./srcs_Part_1/ft_bzero.c \
			./srcs_Part_1/ft_memcpy.c \
			./srcs_Part_1/ft_memccpy.c \
			./srcs_Part_1/ft_memmove.c \
			./srcs_Part_1/ft_memchr.c \
			./srcs_Part_1/ft_memcmp.c \
			./srcs_Part_1/ft_strchr.c \
			./srcs_Part_1/ft_strrchr.c \
			./srcs_Part_1/ft_strstr.c \
			./srcs_Part_1/ft_strnstr.c \
			./srcs_Part_1/ft_strlcat.c \
			./srcs_Part_1/ft_calloc.c \
			./srcs_Part_1/ft_strlcpy.c \
			./srcs_Part_2/ft_memdel.c \
			./srcs_Part_2/ft_memalloc.c \
			./srcs_Part_2/ft_putnbr.c \
			./srcs_Part_2/ft_putstr.c \
			./srcs_Part_2/ft_putchar.c \
			./srcs_Part_2/ft_strnew.c \
			./srcs_Part_2/ft_strclr.c \
			./srcs_Part_2/ft_strdel.c \
			./srcs_Part_2/ft_striter.c \
			./srcs_Part_2/ft_striteri.c \
			./srcs_Part_2/ft_strmap.c \
			./srcs_Part_2/ft_strmapi.c \
			./srcs_Part_2/ft_strequ.c \
			./srcs_Part_2/ft_strnequ.c \
			./srcs_Part_2/ft_substr.c \
			./srcs_Part_2/ft_strtrim.c \
			./srcs_Part_2/ft_split.c \
			./srcs_Part_2/ft_putchar_fd.c \
			./srcs_Part_2/ft_putstr_fd.c \
			./srcs_Part_2/ft_putendl_fd.c \
			./srcs_Part_2/ft_putnbr_fd.c \
			./srcs_Part_2/ft_putendl.c \
			./srcs_Part_2/ft_strjoin.c \
			./srcs_Part_2/ft_itoa.c \
			./Bonus/ft_lstnew.c \
			./Bonus/ft_lstadd_front.c \
			./Bonus/ft_lstadd_back.c \
			./Bonus/ft_lstlast.c \
			./Bonus/ft_lstsize.c \
			./Bonus/ft_lstdelone.c \
			./Bonus/ft_lstclear.c \
			./Bonus/ft_lstiter.c \
			./Bonus/ft_lstmap.c \

MAIN 	= 	main.c

OBJS	=	${SRCS:.c=.o}


CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

HEADER	=	-I ./includes/libft.h

.c.o:
			@gcc ${CFLAGS} -c $< -o $(<:.c=.o) ${HEADER}

${NAME}:	${OBJS}
			@ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:	
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

beta:		all
			@sh hello.sh
			@gcc ${CFLAGS} ${MAIN} ${NAME} && ./a.out

re:			fclean all

.PHONY:		all clean fclean re beta
