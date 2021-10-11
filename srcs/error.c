#include "fractol.h"

int	print_error(char *str, int code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (code);
}
