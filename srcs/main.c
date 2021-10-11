#include "fractol.h"

int		ft_parsing(t_fractol *fractol, int ac, char **av)
{
	if (ac < 2 || (ft_strcmp_type(av[1], "julia") != 0
			&& ft_strcmp_type(av[1], "mandelbrot") != 0))
	{
		print_error("Argument required\n");
		print_error("Available commands are: ./fractol [julia/mandelbrot]\n");
		return (1);
	}
	if (ft_strcmp_type(av[1], "julia") == 0)
		fractol->type = JULIA;
	if (ft_strcmp_type(av[1], "mandelbrot") == 0)
		fractol->type = MANDELBROT;
	if (av[2])
		fractol->coef = ft_atoi(av[2]);
	else
		fractol->coef = 
	return (0);
}

int		main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		return (print_error("malloc failed\n"));
	if (ft_parsing(fractol, ac, av) == 1)
	{
		free(fractol);
		return (1);
	}
	printf("fractol->type = %d", fractol->type);
	//free(fractol);
	//return(0);
	
	fractol->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (!fractol->mlx)
		return (print_error("malloc failed\n"));
	fractol->res = (t_reso*)malloc(sizeof(t_reso));
	if (!fractol->res)
		return (print_error("malloc failed\n"));
	if (launch_program(fractol))
		return (print_error("an error has occured when runnig the program\n"));
	free(fractol->res);
	free(fractol->mlx);
	free(fractol);
	return (0);
}
