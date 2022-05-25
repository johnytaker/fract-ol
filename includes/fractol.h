/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/26 01:13:02 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <string.h>
# include <stdint.h>
# include <mlx.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/*	Window properties	*/
# define HEIGHT			800
# define WIDTH			800
/*	Iteration limit		*/
# define MAX_ITER		128
/*		X11 events		*/
# define ON_DESTROY		17
# define ON_KEYDOWN		2
# define ON_MOUSEDOWN	4
# define ON_MOUSEMOVE	6
/*		Mouse hooks		*/
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
# define KEY_PLUS		24
# define KEY_MINUS		27
# define KEY_PLUS_NP	69
# define KEY_MINUS_NP	78
/*		String color	*/
# define ACID_GREEN		0x00FF00
/*		Structures		*/
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
	t_complex	c;
	t_complex	k;
	int			iter;
	int			max_iter;
	int			julia_move;
	char		*fractol_name;
	t_color		*color_sets;
	t_palette	*current_color_set;
	int			x;
	int			y;
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
/*								Burning ship							*/
int			burning_ship(t_fractol *fractol);
/*								Color									*/
int			get_color(t_fractol *fractol);
/*								Draw utils								*/
void		draw_fractal(t_fractol *fractol);
/*								Events									*/
int			close_window(t_fractol *fractol);
int			zoom(int mousecode, int x, int y, t_fractol *fractol);
int			move_keys(int keycode, t_fractol *fractol);
int			julia_motion(int x, int y, t_fractol *fractol);
/*								Fractol utils							*/
t_complex	init_complex(double re, double im);
t_fractol	*init_fractol(char *fractol_name, int jul_c_re, int jul_c_im);
/*								Image utils								*/
t_image		*init_image(void *mlx);
void		put_str_data(t_fractol *fractol);
void		my_mlx_pixel_put(t_image *image_old, int x, int y, int color);
/*								Julia									*/
int			julia(t_fractol *fractol);
/*								Mandelbrot								*/
int			mandelbrot(t_fractol *fractol);
/*								Move keyboard							*/
void		move_down(t_fractol *fractol);
void		move_up(t_fractol *fractol);
void		move_left(t_fractol *fractol);
void		move_right(t_fractol *fractol);
/*								Print utils								*/
void		print_error(char *str);
void		usage(void);
/*								Zoom									*/
int			zoom_func(int x, int y, double zoom, t_fractol *fractol);
#endif
