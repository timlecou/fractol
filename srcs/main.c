#include "fractol.h"

int		main(int ac, char **av)
{
	t_fractol	*fractol;

	if (ac < 2)
	{
		printf("Argument required\n");
		printf("Available commands are: ./fractol [julia/mandelbrot]\n");	
		return (1);
	}
	if (ft_strncmp(av[1], "julia", 5) != 0 && ft_strncmp(av[1], "mandelbrot", 10) != 0)
	{
		printf("Invalid argument: %s\n", av[1]);
		printf("Available commands are: ./fractol [julia/mandelbrot]\n");	
		return (1);
	}
	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		return (print_error("malloc failed\n", 1));
	fractol->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (!fractol->mlx)
		return (print_error("malloc failed\n", 1));
	fractol->res = (t_reso*)malloc(sizeof(t_reso));
	if (!fractol->res)
		return (print_error("malloc failed\n", 1));
	if (launch_program(fractol))
		return (print_error("an error has occured when runnig the program\n", 1));
	free(fractol->res);
	free(fractol->mlx);
	free(fractol);
	return (0);
}