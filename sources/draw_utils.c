/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/26 01:22:11 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	swap_img(t_fractol *fractol)
{
	t_image	*temp;

	temp = fractol->image_new;
	fractol->image_new = fractol->image_old;
	fractol->image_old = temp;
}

static int	choose_fractal(t_fractol *fractol)
{
	int	iter;

	iter = 0;
	if (fractol->fractol_name[0] == 'B')
		iter = burning_ship(fractol);
	else if (fractol->fractol_name[0] == 'M')
		iter = mandelbrot(fractol);
	else if (fractol->fractol_name[0] == 'J')
		iter = julia(fractol);
	return (iter);
}

static void	draw_function(t_fractol *fractol)
{
	int			y;
	int			x;

	fractol->factor = init_complex(
			(fractol->max.re - fractol->min.re) / (WIDTH - 1),
			(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			fractol->iter = choose_fractal(fractol);
			my_mlx_pixel_put(fractol->image_old, x, y, get_color(fractol));
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_fractol *fractol)
{
	draw_function(fractol);
	swap_img(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image_new->image, 0, 0);
	put_str_data(fractol);
}
