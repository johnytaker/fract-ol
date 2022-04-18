/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:53 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/18 16:15:30 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <mlx.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define HEIGHT	1000
# define WIDTH	1000
# define COLOR_TUNDORA	0x55555

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
	int			src_line;
	int			dst_line;
	int			color_shift;
	int			formula;
};

// struct s_formula
// {
// 	char	*fractol_name;
// 	int		(*formula)(t_fractol *fractol);
// };

struct s_color
{
	int8_t	channel[4];
};


void	print_error(char *str);

#endif
