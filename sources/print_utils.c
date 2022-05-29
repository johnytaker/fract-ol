/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:12:44 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/29 16:11:09 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	usage(void)
{
	ft_putendl_fd("USAGE:\n\n\
./fractol [flag] \n\n\
Available flags:\n\n\
  -b	Burning ship\n\
  -m	Mandelbrot\n\
  -j	Julia * \n\n\
* you can draw Julia set with your own constant (k.re, k.im):\n\
  ./fractol -j [first](x1000) [second](x1000)", 2);
	exit(EXIT_FAILURE);
}
