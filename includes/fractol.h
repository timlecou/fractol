#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct		s_reso
{
	int		x;
	int		y;
}			t_reso;

typedef	struct		s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int		*data;
	int		bpp;
	int		endian;
}			t_mlx;

typedef struct		s_fractol
{
	t_mlx		*mlx;
	t_reso		*res;
}			t_fractol;

//MLX
void		init_mlx(t_mlx *mlx);
int		get_resolution(t_mlx *mlx, t_reso *res);
int		new_window(t_mlx *mlx, t_reso *res);

//LAUNCH
int		launch_program(t_fractol *fractol);

//ERROR
int		print_error(char *str, int code);

#endif
