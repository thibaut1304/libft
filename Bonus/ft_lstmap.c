#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*ptr;

	newlst = NULL;
	while (lst)
	{
		if (!(ptr = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&newlst, (*del));
			return (0);
		}
		ft_lstadd_back(&newlst, ptr);
		lst = lst->next;
	}
	return (newlst);
}