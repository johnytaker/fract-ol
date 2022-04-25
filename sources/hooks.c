/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:32:57 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/25 20:41:33 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fractol)
{
	(void)fractol;
	exit(0);
}

// int	zoom(int mousecode, int x, int y, t_fractol *fractol)
// {
// 	t_complex	c;

// 	c.re = fractol->min.re + (double)x / HEIGHT * fractol->scale;
// 	c.im = fractol->min.im + (double)y / WIDTH * fractol->scale;
// 	if (mousecode == SCROLL_UP)
// 	{
// 		fractol->scale *= 1.1;
// 		fractol->min.re = (fractol->min.re - c.re) * 1.1 + c.re;
// 		fractol->min.im = (fractol->min.im - c.im) * 1.1 + c.im;
// 		draw_fractal(fractol);
// 	}
// 	else if (mousecode == SCROLL_DOWN)
// 	{
// 		fractol->scale /= 1.1;
// 		fractol->min.re = (fractol->min.re - c.re) / 1.1 + c.re;
// 		fractol->min.im = (fractol->min.im - c.im) / 1.1 + c.im;
// 		draw_fractal(fractol);
// 	}
// 	return (0);
// }


int	zoom(int mousecode, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	(void)x;
	(void)y;

	if (mousecode == SCROLL_UP)
	{
		mouse = init_complex(
			fabs(fractol->max.re - fractol->min.re),
			fabs(fractol->max.im - fractol->min.im));
		fractol->min.re += mouse.re * 0.1;
		fractol->min.im += mouse.im * 0.1;
		fractol->max.re -= mouse.re * 0.1;
		fractol->max.im -= mouse.re * 0.1;
	}
	else
	{
		mouse = init_complex(
			fabs(fractol->max.re - fractol->min.re),
			fabs(fractol->max.im - fractol->min.im));
		fractol->min.re -= mouse.re * 0.1;
		fractol->min.im -= mouse.im * 0.1;
		fractol->max.re += mouse.re * 0.1;
		fractol->max.im += mouse.re * 0.1;
	}
	draw_fractal(fractol);
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->const_complex_num = init_complex(
		4 * ((double)x / WIDTH - 0.5),
		4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	draw_fractal(fractol);
	return (0);
}

// static void	zoom_down(int x, int y, float i, t_fractol *fractol)
// {
// 	double	cx;
// 	double	cy;

// 	cx = fractol->min.re + x * fractol->const_complex_num.re;
// 	cy = fractol->min.im + y * fractol->const_complex_num.im;
// 	fractol->min.re = cx + ((fractol->min.re - cx) / i);
// 	fractol->min.im = cy + ((fractol->min.im - cy) / i);
// 	fractol->max.re = cx + ((fractol->max.re - cx) / i);
// 	fractol->max.im = cy + ((fractol->max.im - cy) / i);
// 	fractol->scale *= i;
// 	draw_fractal(fractol);
// }

// int	zoom(int code, int x, int y, t_fractol *fractol)
// {
// 	if (code == SCROLL_DOWN && fractol->scale > 11)
// 		zoom_down(x, y, 0.9, fractol);
// 	else if (code == SCROLL_UP)
// 		zoom_down(x, y, 1.1, fractol);
// 	return (0);
// }