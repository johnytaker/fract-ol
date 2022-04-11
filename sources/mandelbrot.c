/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:09:38 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/09 18:07:07 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

static t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		print_error("error image init");
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	// if (image->image == NULL)
	// 	print_error("error image init");
	image->address = mlx_get_data_addr(image->image, &image->bits_per_pixel, \
		&image->line_length, &image->endian);
	return (image);
}

static void	set_limits(t_fractol *fractol)
{
	fractol->max_iter = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->const_complex_num = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
}

static int	mandelbrot(t_fractol *fractol)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(fractol->complex_num.re, fractol->complex_num.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < fractol->max_iter)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->complex_num.re,
			2.0 * z.re * z.im +fractol->complex_num.im);
		iter++;
	}
	return (iter);
}

static t_fractol	*init_fractol(char *fractol_name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		print_error("error fractol init");
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, fractol_name);
	fractol->image = init_image(mlx);
	set_limits(fractol);
	// fractol->is_julia_fixed = true;
	fractol-> = mandelbrot(fractol);
	return (fractol);
}

static t_color	get_color(int iter, t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)iter / fractol->max_iter;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

static void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->line_length);
	fractol->image->address[i] = color.channel[3];
	fractol->image->address[++i] = color.channel[2];
	fractol->image->address[++i] = color.channel[1];
	fractol->image->address[++i] = color.channel[0];
}

static void	draw_fractal_part(t_fractol *fractol)
{
	int			y;
	int			x;
	t_color		color;

	y = fractol->src_line;
	while (y < fractol->dst_line)
	{
		fractol->complex_num.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->complex_num.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			my_mlx_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_fractal(t_fractol *fractol)
{
	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	draw_fractal_part(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, 900, 965, COLOR_TUNDORA,
		"H - Help");
}

void	start(void)
{
	t_fractol	*fractol;
	void		*mlx;

	mlx = mlx_init();
	fractol = init_fractol("mandelbrot", mlx);
	draw_fractal(fractol);
	mlx_loop(mlx);
}

int	main(void)
{
	start();
	return (0);
}
