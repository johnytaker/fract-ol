/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:24:16 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/31 10:45:38 by iugolin          ###   ########.fr       */
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
	if (mousecode == SCROLL_UP)
		zoom_func(x, y, 1.20, fractol);
	else if (mousecode == SCROLL_DOWN)
		zoom_func(x, y, 0.80, fractol);
	// mlx_clear_window(fractol->mlx, fractol->window);
	draw_fractal(fractol);
	return (0);
}

static void	color_selector(t_fractol *fractol)
{
	if (fractol->current_color_set == fractol->color_sets->first_set)
		fractol->current_color_set = fractol->color_sets->second_set;
	else if (fractol->current_color_set == fractol->color_sets->second_set)
		fractol->current_color_set = fractol->color_sets->third_set;
	else if (fractol->current_color_set == fractol->color_sets->third_set)
		fractol->current_color_set = fractol->color_sets->first_set;
}

static void	julia_move_selector(t_fractol *fractol)
{
	if (fractol->julia_move == 1)
		fractol->julia_move = 0;
	else
		fractol->julia_move = 1;
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
	else if (keycode == KEY_C)
		color_selector(fractol);
	else if (keycode == KEY_SPACE)
		julia_move_selector(fractol);
	else if (keycode == KEY_K)
		julia_set_selector(fractol);
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_NP)
		fractol->max_iter += 8;
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_NP)
		fractol->max_iter -= 8;
	// mlx_clear_window(fractol->mlx, fractol->window);
	draw_fractal(fractol);
	return (0);
}
