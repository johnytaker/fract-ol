/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:08:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/17 16:50:18 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_fractol *fractol)
{
	// t_color	1color;
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

	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(50 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(15 * pow((1 - t), 3) * t * 255);
	return (0 << 24 | red << 16 | green << 8 | blue);
}

// t_vec3 new_vec3(float x, float y, float z)
// {
// 	t_vec3	values;

// 	// values = malloc(sizeof(t_vec3));
// 	values.x = x;
// 	values.y = y;
// 	values.z = z;
// 	return (values);
// }

// t_vec3	palette(float t, t_vec3 a, t_vec3 b, t_vec3 c, t_vec3 d)
// {
// 	t_vec3	bcd;
// 	t_vec3	cd;
// 	t_vec3	abcd;

// 	c.x *= t;
// 	c.y *= t;
// 	c.z *= t;

// 	cd = new_vec3(cos(6.28318 * (c.x + d.x)), cos(6.28318 * (c.y + d.y)), cos(6.28318 * (c.z + d.z)));
// 	bcd = new_vec3(b.x * cd.x, b.y * cd.y, b.z * cd.z);
// 	abcd = new_vec3(a.x + bcd.x, a.y + bcd.y, a.z + bcd.z);
// 	return (abcd);
// }
