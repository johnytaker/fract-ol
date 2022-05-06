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
	if (argc < 2 || argc > 3)
		print_error("USAGE: ./fractol [name]");
	if (!ft_strcmp("mandelbrot", argv[1]) ||
		!ft_strcmp("julia", argv[1]))
		fractol = init_fractol(argv[1]);
	else
		print_error("Available fractals:\nmandelbrot\njulia");
	return (fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = check_parameters_and_init(argc, argv);
	if (fractol)
	{
		draw_fractal(fractol);
		mlx_hook(fractol->window, 17, 0, close_window, fractol);
		mlx_hook(fractol->window, 4, 0, zoom, fractol);
		mlx_hook(fractol->window, 2, 0, move_keys, fractol);
		if (fractol->fractol_name[0] == 'j')
			mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
