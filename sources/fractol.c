/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:14:52 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/30 14:38:37 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractol	*check_parameters_and_init(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = NULL;
	if (!ft_strcmp(argv[1], "-b") && argc == 2)
		fractol = init_fractol("Burning ship", 0, 0);
	else if (!ft_strcmp(argv[1], "-m") && argc == 2)
		fractol = init_fractol("Mandelbrot", 0, 0);
	else if (!ft_strcmp(argv[1], "-j") && argc == 4)
		fractol = init_fractol("Julia", ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (!ft_strcmp(argv[1], "-j") && argc == 2)
		fractol = init_fractol("Julia", 0, 0);
	else
		usage();
	return (fractol);
}

static void	hooks(t_fractol *fractol)
{
	mlx_hook(fractol->window, ON_DESTROY, 0, close_window, fractol);
	mlx_hook(fractol->window, ON_MOUSEDOWN, 0, zoom, fractol);
	mlx_hook(fractol->window, ON_KEYDOWN, 0, move_keys, fractol);
	if (fractol->fractol_name[0] == 'J')
		mlx_hook(fractol->window, ON_MOUSEMOVE, 0, julia_motion, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = check_parameters_and_init(argc, argv);
	if (fractol)
	{
		draw_fractal(fractol);
		hooks(fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}
