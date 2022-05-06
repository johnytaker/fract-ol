/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/06 18:42:00 by iugolin          ###   ########.fr       */
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

# define HEIGHT			1000
# define WIDTH			1000

# define MAX_ITER		500

# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define KEY_ESC		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13

typedef struct s_image		t_image;
typedef struct s_complex	t_complex;
typedef struct s_fractol	t_fractol;
typedef struct s_formula	t_formula;
typedef struct s_color		t_color;
typedef struct s_flag		t_flag;

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
	int			max_iter;
	t_image		*image;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	complex_num;
	t_complex	const_complex_num;
	int			iter;
	char		*fractol_name;
};

struct s_color
{
	int8_t	channel[4];
};

struct s_flag
{
	
};

t_color		get_color(t_fractol *fractol);

t_complex	init_complex(double re, double im);

t_fractol	*init_fractol(char *fractol_name);

t_image		*init_image(void *mlx);

void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, t_color color);

int			mandelbrot(t_fractol *fractol);

int			julia(t_fractol *fractol);

void		draw_fractal(t_fractol *fractol);

void		print_error(char *str);

int			julia_motion(int x, int y, t_fractol *fractol);

void		zoom_in(t_fractol *fractol);
void		zoom_out(t_fractol *fractol);
int			zoom(int mousecode, int x, int y, t_fractol *fractol);

int			close_window(t_fractol *fractol);
void		move_down(t_fractol *fractol);
void		move_up(t_fractol *fractol);
void		move_left(t_fractol *fractol);
void		move_right(t_fractol *fractol);
int			move_keys(int keycode, t_fractol *fractol);

#endif
