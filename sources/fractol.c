/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:31:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/19 18:00:10 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_parameters(int argc, char **argv)
{
	if (argc < )
}
int	main(int argc, char **argv)
{
	t_fractol	*fractol;
	void		*mlx;

	mlx = mlx_init();
	fractol = init_fractol("mandelbrot", mlx);
	draw_fractal(fractol);
	mlx_loop(mlx);
	return (0);
}
