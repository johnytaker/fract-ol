/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:18:45 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/25 20:43:30 by iugolin          ###   ########.fr       */
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
		(fractol->max.re - fractol->min.re);
	fractol->const_complex_num = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
	// fractol->scale = WIDTH / (fractol->max.re - fractol->min.re);
	// fractol->scale = 2;
}

t_fractol	*init_fractol(char *fractol_name)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		print_error("Error fractol init");
	fractol->mlx = mlx_init();
	fractol->fractol_name = fractol_name;
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->fractol_name);
	fractol->image = init_image(fractol->mlx);
	set_limits(fractol);
	return (fractol);
}