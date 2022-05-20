/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/20 03:19:37 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <mlx.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/*	Window properties	*/
# define HEIGHT			800
# define WIDTH			800
/*	Iteration limit		*/
# define MAX_ITER		256
/*		X11 events		*/
# define ON_DESTROY		17
# define ON_KEYDOWN		2
# define ON_MOUSEDOWN	4
# define ON_MOUSEMOVE	6
/*		Mouse hooks		*/
# define RIGHT_CLICK	1
# define SCROLL_UP		4
# define SCROLL_DOWN	5
/*		Keys hooks		*/
# define KEY_ESC		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_SPACE		49
# define KEY_C			8

typedef struct s_image		t_image;
typedef struct s_complex	t_complex;
typedef struct s_palette	t_palette;
typedef struct s_color		t_color;
typedef struct s_fractol	t_fractol;

struct s_image
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_complex
{
	double	re;
	double	im;
};

struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		*image_old;
	t_image		*image_new;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	complex_num;
	t_complex	const_complex_num;
	int			iter;
	int			max_iter;
	int8_t		julia_move;
	char		*fractol_name;
	t_color		*color_sets;
	t_palette	*current_color_set;
};

struct s_palette
{
	int	red;
	int	green;
	int	blue;
};

struct s_color
{
	t_palette	*first_set;
	t_palette	*second_set;
	t_palette	*third_set;
};

int			get_color(t_fractol *fractol);

t_complex	init_complex(double re, double im);

t_fractol	*init_fractol(char *fractol_name, int jul_c_re, int jul_c_im);

t_image		*init_image(void *mlx);

void		my_mlx_pixel_put(t_image *image_old, int x, int y, int color);

int			mandelbrot(t_fractol *fractol);
int			julia(t_fractol *fractol);
int			burning_ship(t_fractol *fractol);

void		draw_fractal(t_fractol *fractol);

void		print_error(char *str);
void		usage(void);

int			julia_motion(int x, int y, t_fractol *fractol);

int			zoom_func(int x, int y, double zoom, t_fractol *fractol);
int			zoom(int mousecode, int x, int y, t_fractol *fractol);

int			close_window(t_fractol *fractol);
void		move_down(t_fractol *fractol);
void		move_up(t_fractol *fractol);
void		move_left(t_fractol *fractol);
void		move_right(t_fractol *fractol);
int			move_keys(int keycode, t_fractol *fractol);

#endif
