/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/01 16:41:28 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	choose_fractal(t_fractol *fractol)
{
	int	iter;
	
	iter = 0;
	if (fractol->fractol_name[0] == 'm')
		iter = mandelbrot(fractol);
	else if (fractol->fractol_name[0] == 'j')
		iter = julia(fractol);
	return (iter);
}

static void	draw_fractal_part(t_fractol *fractol)
{
	int			y;
	int			x;

	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	y = 0;
	while (y < HEIGHT)
	{
		fractol->complex_num.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->complex_num.re = fractol->min.re + x * fractol->factor.re;
			fractol->iter = choose_fractal(fractol);
			my_mlx_pixel_put(fractol, x, y, get_color(fractol));
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_fractol *fractol)
{
	draw_fractal_part(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
}