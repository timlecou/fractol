#include "fractol.h"

void	draw_pixel(t_fractol fractol, t_xy pos)
{
	t_d_xy		d_pos;

	d_pos.x = 1.5 * ((double)pos.x - fractol->res->d_xy.x / 2)
		/ (0.5 * fractol->zoom * fractol->res->d_xy.x);
	d_pos.y = ((double)pos.y - fractol->res->d_xy.y / 2)
		/ (0.5 * fractol->zoom * fractol->res->d_xy.y);
	fractol->mlx->img[pos.y * fractol->res->xy.x + pos.x] = 
		set_color(fractol->color);
}

void	draw_fractal(t_fractol *fractol)
{
	t_xy	pos;

	pos.x = 0;
	while (pos.x < fractol->res->x)
	{
		y = 0;
		while (pos.y < fractol->res->xy.y)
		{
			draw_pixel(fractol, pos);
			pos.y++;
		}
		pos.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
