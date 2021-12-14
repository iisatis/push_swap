
#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_begin		*begin;

	begin = ft_init_begin();
	begin->bb = NULL;
	begin->inst = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		begin->ba = ft_build_pile_str(argv[1]);
	else
		begin->ba = ft_build_pile(argc, argv);
	if (ft_is_sort(&begin->ba, 1) != 0)
		ft_algo(begin);
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	ft_lstdel2(&begin->inst);
	free(begin);
	return (0);
}
