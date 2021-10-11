#include "fractol.h"

int	close_mlx_win(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = NULL;
}

int	get_resolution(t_mlx *mlx, t_reso *res)
{
	res->x = 0;
	res->y = 0;
	if (!mlx_get_screen_size(mlx->mlx, &res->x, &res->y))
		return (print_error("failed to get screen size\n", 1));
	if (res->y > 600)
		res->y = 600;
	if (res->x > 900)
		res->x = 900;
	return (0);
}

int	new_window(t_mlx *mlx, t_reso *res)
{
	init_mlx(mlx);
	mlx->mlx = mlx_init();
	if (get_resolution(mlx, res))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, res->x, res->y, "fract-ol");
	return (0);
}
