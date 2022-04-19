/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:24:41 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/19 16:18:11 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length
		+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_image	img;
	int		x_len;
	int		y_len;
	int		color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 768, "fractol");
	img.image = mlx_new_image(mlx, 1024, 768);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	y_len = 250;
	color = 0x00FF0000;
	while (y_len)
	{
		x_len = 250;
		while (x_len)
		{
			my_mlx_pixel_put(&img, x_len, y_len, color++);
			x_len--;
		}
		y_len--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.image, 0, 0);
	mlx_loop(mlx);
}
