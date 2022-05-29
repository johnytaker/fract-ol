/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:32:57 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/29 18:20:31 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	zoom_func(int x, int y, double zoom, t_fractol *fractol)
{
	t_complex	mouse;
	double		interpolation;

	mouse = init_complex(
			(double)x / (WIDTH / fabs(fractol->max.re - fractol->min.re)) + \
			fractol->min.re,
			(double)y / (HEIGHT / fabs(fractol->max.im - fractol->min.im)) * \
			-1 + fractol->max.im);
	interpolation = 1.0 / zoom;
	fractol->min.re = interpolate(mouse.re, fractol->min.re, interpolation);
	fractol->min.im = interpolate(mouse.im, fractol->min.im, interpolation);
	fractol->max.re = interpolate(mouse.re, fractol->max.re, interpolation);
	fractol->max.im = interpolate(mouse.im, fractol->max.im, interpolation);
	return (0);
}
