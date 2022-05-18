/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:27:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/16 17:48:34 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		print_error("error image init");
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (image->image == NULL)
		print_error("error image init");
	image->address = mlx_get_data_addr(image->image,
		&image->bits_per_pixel, &image->line_length, &image->endian);
	return (image);
}

void	my_mlx_pixel_put(t_image *image_old, int x, int y, int color)
{
	// int	i;

	// i = (x * fractol->image->bits_per_pixel / 8) +
	// 	(y * fractol->image->line_length);
	// fractol->image->address[i] = color.channel[3];
	// fractol->image->address[i + 1] = color.channel[2];
	// fractol->image->address[i + 2] = color.channel[1];
	// fractol->image->address[i + 3] = color.channel[0];

	char	*dst;
	
	dst = image_old->address + (y * image_old->line_length + x * (image_old->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, t_vec3 palette)
// {
// 	int	i;

// 	i = (x * fractol->image_old->bits_per_pixel / 8) +
// 		(y * fractol->image_old->line_length);
// 	fractol->image_old->address[i] = fmin(255, fmax(0, pow(palette.z, 1 / 2.2)));
// 	fractol->image_old->address[i + 1] = fmin(255, fmax(0, pow(palette.y, 1 / 2.2)));
// 	fractol->image_old->address[i + 2] = fmin(255, fmax(0, pow(palette.x, 1 / 2.2)));
// 	fractol->image_old->address[i + 3] = 0;
	// char	*dst;

	// dst = image_old->address + (y * image_old->line_length + x * (image_old->bits_per_pixel / 8));
	// *(unsigned int *)dst = color;
// }
