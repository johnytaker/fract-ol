 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:31:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/20 20:35:21 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractol	*check_parameters_and_init(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = NULL;
	if(!ft_strcmp("-b", argv[1]) && argc == 2)
		fractol = init_fractol("Burning ship", 0 , 0);
	else if (!ft_strcmp("-m", argv[1]) && argc == 2)
		fractol = init_fractol("Mandelbrot", 0, 0);
	else if (!ft_strcmp("-j", argv[1]) && argc == 4)
		fractol = init_fractol("Julia", ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (!ft_strcmp("-j", argv[1]) && argc == 2)
		fractol = init_fractol("Julia", 0, 0);
	else
		usage();
	return (fractol);
}

int	get_coordinates(int x, int y, t_fractol *fractol)
{
	char	*x_coordinate = ft_strjoin(ft_strdup("x: "), ft_itoa(x));
	char	*y_coordinate = ft_strjoin(ft_strdup("y: "), ft_itoa(y));
	mlx_string_put(fractol->mlx, fractol->window,
		620, 110, ACID_GREEN, x_coordinate);
	// mlx_string_put(fractol->mlx, fractol->window,
	// 	720, 110, ACID_GREEN, ft_itoa(x));
	mlx_string_put(fractol->mlx, fractol->window,
		620, 130, ACID_GREEN, y_coordinate);
	// mlx_string_put(fractol->mlx, fractol->window,
	// 	720, 130, ACID_GREEN, ft_itoa(y));
	free(x_coordinate);
	free(y_coordinate);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = check_parameters_and_init(argc, argv);
	if (fractol)
	{
		draw_fractal(fractol);
		mlx_hook(fractol->window, ON_DESTROY, 0, close_window, fractol);
		mlx_hook(fractol->window, ON_MOUSEDOWN, 0, zoom, fractol);
		mlx_hook(fractol->window, ON_KEYDOWN, 0, move_keys, fractol);
		mlx_hook(fractol->window, ON_MOUSEMOVE, 0, get_coordinates, fractol);
		if (fractol->fractol_name[0] == 'J')
			mlx_hook(fractol->window, ON_MOUSEMOVE, 0, julia_motion, fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
