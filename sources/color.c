/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:08:07 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/29 15:31:37 by iugolin          ###   ########.fr       */
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
	red = (int)(fractol->current_color_set->red * \
			(1 - t) * pow(t, 3) * 255);
	green = (int)(fractol->current_color_set->green * \
			pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(fractol->current_color_set->blue * \
			pow((1 - t), 3) * t * 255);
	return (0 << 24 | red << 16 | green << 8 | blue);
}
