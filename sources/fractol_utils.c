/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:18:45 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/19 16:35:12 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

static void	set_limits(t_fractol *fractol)
{
	fractol->max_iter = 100;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im +
		(fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->const_complex_num = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
}

t_fractol	*init_fractol(char *fractol_name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		print_error("error fractol init");
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, fractol_name);
	fractol->image = init_image(mlx);
	set_limits(fractol);
	return (fractol);
}