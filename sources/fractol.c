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
	if (!ft_strcmp("-m", argv[1]) && argc == 2)
		fractol = init_fractol("Mandelbrot", 0, 0);
	else if (!ft_strcmp("-j", argv[1]) && argc == 4)
		fractol = init_fractol("Julia", ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (!ft_strcmp("-j", argv[1]) && argc == 2)
		fractol = init_fractol("Julia", 0, 0);
	else
		usage();
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
		if (fractol->fractol_name[0] == 'J')
			mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
