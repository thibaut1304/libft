#include "../includes/libft.h"
#include <string.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstrr(char *c)
{
	int i = 0;

	while (c[i])
		ft_putchar(c[i++]);
}

// t_list	*add_element(t_list *list, char *content)
// {
// 	t_list *element;

// 	if (!(element = malloc(sizeof(list))))
// 		return (NULL);
	
// 	element->content = content;
// 	element->next = list;
// 	return (element);
// }

// t_list	*end_element(t_list *list, char *content)
// {
// 	t_list *element;

// 	if (!(element = malloc(sizeof(list))))
// 		return (NULL);

// 	t_list *temp;
// 	temp = list;

// 	element->content = content;
// 	element->next = NULL;

// 	while (temp->next != NULL)
// 	{
// 		temp = temp->next;
// 	}
// 	temp->next = element;
// 	return (list);
// }

void	print_list(t_list *list)
{
	if (list)
	{
			while (list)
		{
			ft_putstrr("Content : ");
			ft_putstrr(list->content);
			if (list->text != NULL)
			{
				ft_putstrr("Text: ");
				ft_putstrr(list->text);
			}
			list = list->next;
		}
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_list		*ft_lstlast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (alst == NULL || *alst == NULL)
	{
		*alst = new;
	}
	else
	{
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// void	del(void *list)
// {
// 	t_list		*tmp;

// 	tmp = list;
// 	while (list)
// 	{
// 		tmp = (t_list)list->next;
// 		free(list);
// 		list = tmp;
// 	}
// }

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

int main(void)
{
	t_list *list;
	t_list *new;
	t_list *new2;
	t_list *new3;
	t_list *new4;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = "test\n";
	new->next = NULL;

	new2 = (t_list *)malloc(sizeof(t_list));
	new2->content = "caca\n";
	new2->text = "caca\n";
	new2->next = NULL;

	new3 = (t_list *)malloc(sizeof(t_list));
	new3->content = "pipi\n";
	new3->next = NULL;

	new4 = (t_list *)malloc(sizeof(t_list));
	new4->content = "prout\n";
	new4->text = "Text5\n";
	new4->next = NULL;
	// list = NULL;
	list = ft_lstnew("tata\n");
	ft_lstadd_front(&list, new);
	ft_lstadd_back(&list, new2);
	ft_lstadd_front(&list, new3);
	ft_lstadd_back(&list, new4);

	print_list(list);
	// ft_lstdelone(list, &del);
	printf("Taille list : %d\n", ft_lstsize(list));
	return (0);
}
// int main()
// {
// 	t_list	*list;

// 	list = NULL;

// add_element(list, "tata\n");
// add_element(list, "toto\n");
// add_element(list, "tutu\n");
// add_element(list, "test\n");
// end_element(list, "test\n");
// 	// list = add_element(list, "toto\n");
// 	// list = add_element(list, "tutu\n");
// 	// list = add_element(list, "test\n");
// 	// list = end_element(list, "test\n");

// 	print_list(list);
// 	return 0;
// }