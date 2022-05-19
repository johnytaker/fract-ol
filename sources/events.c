/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:24:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/19 21:46:25 by iugolin          ###   ########.fr       */
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
	else if (keycode == KEY_SPACE)
	{
		if (fractol->julia_move == 1)
			fractol->julia_move = 0;
		else
			fractol->julia_move = 1;
	}
	else if (keycode == KEY_C)
	{
		if (fractol->current_color_set == fractol->color_sets->first_set)
			fractol->current_color_set = fractol->color_sets->second_set;
		else if (fractol->current_color_set == fractol->color_sets->second_set)
			fractol->current_color_set = fractol->color_sets->third_set;
		else if (fractol->current_color_set == fractol->color_sets->third_set)
			fractol->current_color_set = fractol->color_sets->first_set;
	}
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	if (fractol->julia_move == 1)
	{
		fractol->const_complex_num = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(fractol);
	}
	return (0);
}
