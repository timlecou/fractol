#include "fractol.h"

int	close_mlx_win(int keycode, t_mlx *mlx);

int	launch_program(t_fractol *fractol)
{
	if (ft_init(fractol))
		return (print_error("an error has occured when creating a window\n"));
	draw_fractal(fractol);
	mlx_hook(fractol->mlx->win, 2, 1L<<0, close_mlx_win, fractol->mlx);
	mlx_loop(fractol->mlx->mlx);
	return (0);
}
