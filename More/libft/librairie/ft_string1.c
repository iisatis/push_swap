
#include "../includes/ft_printf.h"

int		ft_int(int n, t_flag *arg)
{
	char	*s;
	int		len;

	if (arg->lg == 2)
		s = ft_itoa((short int)n);
	else if (arg->lg == 1)
		s = ft_itoa((signed char)n);
	else
		s = ft_itoa(n);
	ft_precisionnb(n, &s, arg);
	ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_lint(long int n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoalgint(n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_llint(long long n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoalglgint(n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_intm(intmax_t n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoaintmax(n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_sizet(size_t n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoalglgint((long long int)n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}
