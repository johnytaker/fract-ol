/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:18:45 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/26 01:41:25 by iugolin          ###   ########.fr       */
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

static t_palette	*set_palette(int red, int green, int blue)
{
	t_palette	*palette;

	palette = (t_palette *)malloc(sizeof(t_palette));
	if (!palette)
		print_error("Allocate memory error\n");
	palette->red = red;
	palette->green = green;
	palette->blue = blue;
	return (palette);
}

static t_color	*set_colors(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		print_error("Allocate memory error\n");
	color->first_set = set_palette(110, 1, 4);
	color->second_set = set_palette(30, 150, 2);
	color->third_set = set_palette(9, 30, 7);
	return (color);
}

static void	set_limits(t_fractol *fractol)
{
	fractol->max_iter = MAX_ITER;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + \
		(fractol->max.re - fractol->min.re);
	fractol->julia_move = 1;
	fractol->color_sets = set_colors();
	fractol->current_color_set = fractol->color_sets->first_set;
}

t_fractol	*init_fractol(char *fractol_name, int jul_c_re, int jul_c_im)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		print_error("Allocate memory error\n");
	fractol->mlx = mlx_init();
	fractol->fractol_name = fractol_name;
	fractol->window = mlx_new_window(
			fractol->mlx, WIDTH, HEIGHT, fractol->fractol_name);
	fractol->image_old = init_image(fractol->mlx);
	fractol->image_new = init_image(fractol->mlx);
	set_limits(fractol);
	if (jul_c_re != 0 && jul_c_im != 0)
		fractol->k = init_complex(
				(double)jul_c_re * 0.001, (double)jul_c_im * 0.001);
	else
		fractol->k = init_complex(-0.7, 0.27015);
	return (fractol);
}
