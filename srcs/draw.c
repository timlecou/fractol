#include "fractol.h"

int	iterate_julia(t_d_xy *c, t_d_xy d_pos)
{
	int	i;
	t_d_xy	d_tmp;

	i = 0;
	while (sqrt(c->x * c->x + c->y * c->y) <= 2 && i < MAX_ITERATION)
	{
		d_tmp.x = c->x;
		d_tmp.y = c->y;
		c->x = d_tmp.x * d_tmp.x - d_tmp.y * d_tmp.y + d_pos.x;
		c->y = 2 * d_tmp.x * d_tmp.y + d_pos.y;
		i++;
	}
	return (i);
}

int	iteration(t_fractol *fractol, t_d_xy d_pos)
{
	if (fractol->type == JULIA)
		return (iterate_julia(&d_pos, fractol->coef));
	return (0);
}

int	set_color(int it, int color)
{
	int	ret;

	ret = 0;
	if (it == 0)
		return (0);
	if (it == MAX_ITERATION)
		return (0);
	ret = (it * (1 + color * 2) | it * (3 + color / 3) << 8 | it * (7 + color) << 16);
	//printf("[%d]\n", ret);
	return (ret);
}

void	draw_pixel(t_fractol *fractol, t_xy pos)
{
	t_d_xy		d_pos;

	d_pos.x = 1.5 * ((double)pos.x - fractol->res->d_xy.x / 2)
		/ (0.5 * fractol->zoom * fractol->res->d_xy.x);
	d_pos.y = ((double)pos.y - fractol->res->xy.y / 2)
		/ (0.5 * fractol->zoom * fractol->res->xy.y);
	//printf("(%f)(%f)\n", d_pos.x, d_pos.y);
	fractol->mlx->data[pos.y * fractol->res->xy.x + pos.x] = 
		set_color(iteration(fractol, d_pos), fractol->color);
}

void	draw_fractal(t_fractol *fractol)
{
	t_xy	pos;

	pos.x = 0;
	while (pos.x < fractol->res->xy.x)
	{
		pos.y = 0;
		while (pos.y < fractol->res->xy.y)
		{
			draw_pixel(fractol, pos);
			pos.y++;
		}
		pos.x++;
	}
	mlx_put_image_to_window(fractol->mlx->mlx, fractol->mlx->win, fractol->mlx->img, 0, 0);
}
