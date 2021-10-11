#include "fractol.h"

int		ft_parsing(int ac, char **av)
{
	if (ac < 2 || (ft_strcmp_type(av[1], "julia") != 0
			&& ft_strcmp_type(av[1], "mandelbrot") != 0))
	{
		print_error("Argument required\n");
		print_error("Available commands are: ./fractol [julia/mandelbrot]\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_fractol	*fractol;

	if (ft_parsing(ac, av) == 1)
		return (1);
	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		return (print_error("malloc failed\n"));
	if (ft_strcmp_type(av[1], "julia") == 0)
		fractol->type = JULIA;
	if (ft_strcmp_type(av[1], "mandelbrot") == 0)
		fractol->type = MANDELBROT;
	printf("fractol->type = %d", fractol->type);
	if (launch_program(fractol))
		return (print_error("an error has occured when runnig the program\n"));


	//FREE
	free(fractol->res);
	free(fractol->mlx);
	free(fractol);
	return (0);
}
