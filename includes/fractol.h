#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../mlx_linux/mlx.h"

# define COEF_A -0.038088
# define COEF_B 0.9754633
# define JULIA 1
# define MANDELBROT 2
# define MAX_ITERATION 256

typedef struct		s_xy
{
	int		x;
	int		y;
}			t_xy;

typedef struct		s_d_xy
{
	double		x;
	double		y;
}			t_d_xy;

typedef struct		s_reso
{
	t_xy		xy;
	t_d_xy		d_xy;
}			t_reso;

typedef	struct		s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int		*data;
	int		bpp;
	int		endian;
	int		size_l;
}			t_mlx;

typedef struct		s_fractol
{
	t_mlx		*mlx;
	t_reso		*res;
	int		type;
	t_d_xy		coef;
	int		color;
	double		zoom;
}			t_fractol;

//MLX
void		init_mlx(t_mlx *mlx);
int		get_resolution(t_mlx *mlx, t_reso *res);
int		ft_init(t_fractol *fractol);
int		key_press(int keycode, t_mlx *mlx);
int		key_release(int keycode, t_mlx *mlx);
int		button_press(int keycode, int x, int y, t_fractol *fractol);

//LAUNCH
int		launch_program(t_fractol *fractol);

//ERROR
int		print_error(char *str);

//UTILS
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp_type(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

//EXIT

//DRAW
void		draw_fractal(t_fractol *fractol);

#endif
