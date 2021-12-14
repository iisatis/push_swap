
#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current;

	current = lst;
	if (lst != 0)
	{
		while (current != NULL)
		{
			(*f)(current);
			current = current->next;
		}
	}
}
