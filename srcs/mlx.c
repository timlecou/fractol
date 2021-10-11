#include "fractol.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
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

int	ft_init(t_fractol *fractol)
{
	//malloc structure mlx
	fractol->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (!fractol->mlx)
		return (print_error("malloc failed\n"));
	//malloc structure resolution
	fractol->res = (t_reso*)malloc(sizeof(t_reso));
	if (!fractol->res)
		return (print_error("malloc failed\n"));
	//init mlx
	init_mlx(fractol->mlx);
	fractol->mlx->mlx = mlx_init();
	if (get_resolution(fractol->mlx, fractol->res))
		return (1);
	fractol->mlx->win = mlx_new_window(fractol->mlx->mlx, fractol->res->xy.x, fractol->res->xy.y, "fract-ol");
	if (!fractol->mlx->win)
		return (print_error("failed to create window\n"));
	fractol->mlx->img = mlx_new_image(fractol->mlx->mlx, fractol->res->xy.x, fractol->res->xy.y);
	if (!fractol->mlx->img)
		return (print_error("failed to create mlx image\n"));
	fractol->mlx->data = (int *)mlx_get_data_addr(fractol->mlx->img, &fractol->mlx->bpp, &fractol->mlx->size_l, &fractol->mlx->endian);
	if (!fractol->mlx->data)
		return (print_error("mlx_get_data_addr() failed\n"));
	return (0);
}
