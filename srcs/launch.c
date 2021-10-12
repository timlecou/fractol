#include "fractol.h"

void	mlx_hook_looper(t_fractol *fractol)
{
	mlx_hook(fractol->mlx->win, 2, 1L<<0, key_press, fractol->mlx);
	mlx_hook(fractol->mlx->win, 3, 1L<<1, key_release, fractol->mlx);
	mlx_hook(fractol->mlx->win, 4, 1L<<2, button_press, fractol->mlx);
}

int	launch_program(t_fractol *fractol)
{
	if (ft_init(fractol))
		return (print_error("an error has occured when creating a window\n"));
	draw_fractal(fractol);
	mlx_hook_looper(fractol);
	mlx_loop(fractol->mlx->mlx);
	return (0);
}
