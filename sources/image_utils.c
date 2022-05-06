/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:27:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/01 16:44:47 by iugolin          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8) +
		(y * fractol->image->line_length);
	fractol->image->address[i] = color.channel[3];
	fractol->image->address[i + 1] = color.channel[2];
	fractol->image->address[i + 2] = color.channel[1];
	fractol->image->address[i + 3] = color.channel[0];
}

// void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = fractol->image->address +
// 		(x * fractol->image->bits_per_pixel / 8) +
// 		(y * fractol->image->line_length);
// 	*(unsigned int *)dst = color;
// }
