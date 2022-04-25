/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:39:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/25 20:43:53 by iugolin          ###   ########.fr       */
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
	t_color		color;

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
			fractol->formula = choose_fractal(fractol);
			color = get_color(fractol->formula, fractol);
			my_mlx_pixel_put(fractol, x, y, color);
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
	// mlx_string_put(fractol->mlx, fractol->window, 900, 965, COLOR_TUNDORA,
	// 	"H - Help");
}