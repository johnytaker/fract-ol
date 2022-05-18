/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/16 17:47:28 by iugolin          ###   ########.fr       */
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
	if (fractol->fractol_name[0] == 'M')
		iter = mandelbrot(fractol);
	else if (fractol->fractol_name[0] == 'J')
		iter = julia(fractol);
	return (iter);
}

static void	draw_fractal_part(t_fractol *fractol)
{
	int			y;
	int			x;
	// t_vec3		a;
	// t_vec3		b;
	// t_vec3		c;
	// t_vec3		d;

	// a = new_vec3(0.5, 0.5, 0.5);
	// b = new_vec3(0.5, 0.5, 0.5);
	// c = new_vec3(2.0, 1.0, 0.0);
	// d = new_vec3(0.50, 0.20, 0.25);
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
			my_mlx_pixel_put(fractol->image_old, x, y, get_color(fractol));
			// my_mlx_pixel_put(fractol, x, y,
			// 	palette((float)(fractol->iter / fractol->max_iter), a, b, c, d));
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_fractol *fractol)
{
	draw_fractal_part(fractol);
	swap_img(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image_new->image, 0, 0);

}
