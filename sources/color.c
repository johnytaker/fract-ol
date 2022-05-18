/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:08:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/18 22:29:19 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_fractol *fractol)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)fractol->iter / fractol->max_iter;
	// color.channel[0] = 0;
	// color.channel[1] =
	// 	(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	// color.channel[2] =
	// 	(int8_t)(50 * pow((1 - t), 2) * pow(t, 2) * 255);
	// color.channel[3] =
	// 	(int8_t)(15 * pow((1 - t), 3) * t * 255);
	// return (color);

	red = (int)(110 * (1 - t) * pow(t, 3) * 255);
	green = (int)(1 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(4 * pow((1 - t), 3) * t * 255);
	return (0 << 24 | red << 16 | green << 8 | blue);
}

