/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:27:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/26 01:24:38 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		print_error("Error image init");
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image->image)
		print_error("Error image init");
	image->address = mlx_get_data_addr(image->image,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	if (!image->address)
		print_error("Error address init");
	return (image);
}

void	put_str_data(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx, fractol->window,
		620, 30, ACID_GREEN, fractol->fractol_name);
	mlx_string_put(fractol->mlx, fractol->window,
		620, 50, ACID_GREEN, "max_iter:");
	mlx_string_put(fractol->mlx, fractol->window,
		720, 50, ACID_GREEN, ft_itoa(fractol->max_iter));
	mlx_string_put(fractol->mlx, fractol->window,
		620, 70, ACID_GREEN, "c.re (x1000):");
	mlx_string_put(fractol->mlx, fractol->window,
		720, 70, ACID_GREEN, ft_itoa(fractol->c.re * 1000));
	mlx_string_put(fractol->mlx, fractol->window,
		620, 90, ACID_GREEN, "c.im (x1000):");
	mlx_string_put(fractol->mlx, fractol->window,
		720, 90, ACID_GREEN, ft_itoa(fractol->c.im * 1000));
	if (fractol->fractol_name[0] == 'J')
	{
		mlx_string_put(fractol->mlx, fractol->window,
			620, 110, ACID_GREEN, "k.re (x1000):");
		mlx_string_put(fractol->mlx, fractol->window,
			720, 110, ACID_GREEN, ft_itoa(fractol->k.re * 1000));
		mlx_string_put(fractol->mlx, fractol->window,
			620, 130, ACID_GREEN, "k.im (x1000):");
		mlx_string_put(fractol->mlx, fractol->window,
			720, 130, ACID_GREEN, ft_itoa(fractol->k.im * 1000));
	}
}

void	my_mlx_pixel_put(t_image *image_old, int x, int y, int color)
{
	char	*dst;

	dst = image_old->address + \
		(y * image_old->line_length + \
		x * (image_old->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
