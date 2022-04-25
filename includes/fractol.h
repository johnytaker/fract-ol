/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/25 21:46:19 by iugolin          ###   ########.fr       */
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

# define HEIGHT			700
# define WIDTH			700

# define COLOR_TUNDORA	0x999999

# define LEFT_CLICK		1
# define RIGHT_CLICK	2
# define MIDDLE_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef struct s_image		t_image;
typedef struct s_complex	t_complex;
typedef struct s_fractol	t_fractol;
typedef struct s_formula	t_formula;
typedef struct s_color		t_color;

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
	int			color_shift;
	int			formula;
	char		*fractol_name;
};

struct s_color
{
	int8_t	channel[4];
};

t_color		get_color(int iter, t_fractol *fractol);

t_complex	init_complex(double re, double im);

t_fractol	*init_fractol(char *fractol_name);

t_image		*init_image(void *mlx);

void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, t_color color);

int			mandelbrot(t_fractol *fractol);

int			julia(t_fractol *fractol);

void		draw_fractal(t_fractol *fractol);

void		print_error(char *str);

int			close_window(t_fractol *fractol);

int		zoom(int mousecode, int x, int y, t_fractol *fractol);

int		julia_motion(int x, int y, t_fractol *fractol);

#endif
