
#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *elem)
{
	if (alst != NULL && elem != NULL)
	{
		elem->next = *alst;
		*alst = elem;
	}
}
