#include "fractol.h"

int	launch_program(t_fractol *fractol)
{
	if (ft_init(fractol))
		return (print_error("an error has occured when creating a window\n"));
	draw_fractal(fractol);
	mlx_hook(fractol->mlx->win, 3, 1L<<1, key_release, fractol->mlx);
	mlx_hook(fractol->mlx->win, 2, 1L<<0, key_press, fractol->mlx);
	mlx_loop(fractol->mlx->mlx);
	return (0);
}
