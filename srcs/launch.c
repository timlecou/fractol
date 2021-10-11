#include "fractol.h"

int	launch_program(t_fractol *fractol)
{
	if (new_window(fractol->mlx, fractol->res))
		return (print_error("an error has occured when creating a window\n", 1));
	mlx_loop(fractol->mlx->mlx);
	return (0);
}
