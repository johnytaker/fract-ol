/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:58:41 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/15 16:42:15 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractol)
{
	int		iter;
	t_complex	z;

	iter = 0;
	z = init_complex(fractol->complex_num.re, fractol->complex_num.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < fractol->max_iter)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->const_complex_num.re,
			2.0 * z.re * z.im + fractol->const_complex_num.im);
		iter++;
	}
	return (iter);
}