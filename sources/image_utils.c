/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:27:21 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/20 03:17:21 by iugolin          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_image *image_old, int x, int y, int color)
{
	char	*dst;

	dst = image_old->address + \
		(y * image_old->line_length + \
		x * (image_old->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
