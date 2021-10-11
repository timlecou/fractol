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
	res->xy.x = 0;
	res->xy.y = 0;
	res->d_xy.x = 0;
	res->d_xy.y = 0;
	if (!mlx_get_screen_size(mlx->mlx, &res->xy.x, &res->xy.y))
		return (print_error("failed to get screen size\n"));
	if (res->xy.y > 600)
		res->xy.y = 600;
	if (res->xy.x > 900)
		res->xy.x = 900;
	res->d_xy.x = (double)res->xy.x;
	res->d_xy.y = (double)res->xy.y;
	return (0);
}

int	new_window(t_mlx *mlx, t_reso *res)
{
	init_mlx(mlx);
	mlx->mlx = mlx_init();
	if (get_resolution(mlx, res))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, res->xy.x, res->xy.y, "fract-ol");
	if (!mlx->win)
		return (print_error("failed to create window\n"));
	mlx->img = mlx_new_image(mlx->mlx, res->xy.x, res->xy.y);
	if (!mlx->img)
		return (print_error("failed to create mlx image\n"));
	return (0);
}
