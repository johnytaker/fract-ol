/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:24:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/15 19:32:36 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fractol)
{
	(void)fractol;
	exit(0);
}

int	zoom(int mousecode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;

	if (mousecode == SCROLL_UP)
		zoom_in(fractol);
	else
		zoom_out(fractol);
	draw_fractal(fractol);
	return (0);
}

int	move_keys(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		close_window(fractol);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(fractol);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_up(fractol);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(fractol);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(fractol);
	return (0);
}

int	julia_motion(int mousecode, int x, int y, t_fractol *fractol)
{
	if (mousecode == MIDDLE_BUTTON)
		
}
