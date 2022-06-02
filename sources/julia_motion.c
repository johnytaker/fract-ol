/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:34:52 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/31 10:07:49 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_motion(int x, int y, t_fractol *fractol)
{
	if (fractol->julia_move == 1)
	{
		fractol->k->re = 4 * ((double)x / WIDTH - 0.5);
		fractol->k->im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		// mlx_clear_window(fractol->mlx, fractol->window);
		draw_fractal(fractol);
	}
	return (0);
}
