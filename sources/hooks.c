/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:32:57 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/06 17:27:58 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *fractol)
{
	t_complex	mouse;
	
	mouse = init_complex(
		fabs(fractol->max.re - fractol->min.re),
		fabs(fractol->max.im - fractol->min.im));
	fractol->min.re += mouse.re * 0.1;
	fractol->min.im += mouse.im * 0.1;
	fractol->max.re -= mouse.re * 0.1;
	fractol->max.im -= mouse.re * 0.1;
}

void	zoom_out(t_fractol *fractol)
{
	t_complex	mouse;

	mouse = init_complex(
		fabs(fractol->max.re - fractol->min.re),
		fabs(fractol->max.im - fractol->min.im));
	fractol->min.re -= mouse.re * 0.1;
	fractol->min.im -= mouse.im * 0.1;
	fractol->max.re += mouse.re * 0.1;
	fractol->max.im += mouse.re * 0.1;
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->const_complex_num = init_complex(
		4 * ((double)x / WIDTH - 0.5),
		4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	draw_fractal(fractol);
	return (0);
}
