
#include "../includes/checker.h"

int				main(int argc, char **argv)
{
	t_pile		*ba;
	char		*str;
	t_begin		*begin;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		ba = ft_build_pile_str(argv[1]);
	else
		ba = ft_build_pile(argc, argv);
	str = NULL;
	begin = ft_init_begin();
	begin->bb = NULL;
	begin->ba = ba;
	while (get_next_line(0, &str) == 1)
	{
		ft_move(str, begin);
		free(str);
	}
	free(str);
	ft_check_pile(&begin->ba, &begin->bb);
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	free(begin);
	return (0);
}
