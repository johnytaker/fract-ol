/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:08:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/06 17:21:29 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	get_color(t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)fractol->iter / fractol->max_iter;
	color.channel[0] = 0;
	color.channel[1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[2] =
		(int8_t)(50 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[3] =
		(int8_t)(15 * pow((1 - t), 3) * t * 255);
	return (color);
}
