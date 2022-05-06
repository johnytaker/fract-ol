/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:17:28 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/06 17:29:11 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_down(t_fractol *fractol)
{
	double	delta;

	delta = fabs(fractol->max.im - fractol->min.im);
	fractol->min.im -= delta * 0.1;
	fractol->max.im -= delta * 0.1;
	draw_fractal(fractol);
}

void	move_up(t_fractol *fractol)
{
	double	delta;

	delta = fabs(fractol->max.im - fractol->min.im);
	fractol->min.im += delta * 0.1;
	fractol->max.im += delta * 0.1;
	draw_fractal(fractol);
}

void	move_left(t_fractol *fractol)
{
	double	delta;

	delta = fabs(fractol->max.re - fractol->min.re);
	fractol->min.re -= delta * 0.1;
	fractol->max.re -= delta * 0.1;
	draw_fractal(fractol);
}

void	move_right(t_fractol *fractol)
{
	double	delta;

	delta = fabs(fractol->max.re - fractol->min.re);
	fractol->min.re += delta * 0.1;
	fractol->max.re += delta * 0.1;
	draw_fractal(fractol);
}
