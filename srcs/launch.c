#include "fractol.h"

int	close_mlx_win(int keycode, t_mlx *mlx);

int	launch_program(t_fractol *fractol)
{
	if (new_window(fractol->mlx, fractol->res))
		return (print_error("an error has occured when creating a window\n"));
	mlx_hook(fractol->mlx->win, 2, 1L<<0, close_mlx_win, fractol->mlx);
	mlx_loop(fractol->mlx->mlx);
	return (0);
}
