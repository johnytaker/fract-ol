/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:44:30 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/20 03:05:52 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_fractol *fractol)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(fractol->complex_num.re, fractol->complex_num.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < fractol->max_iter)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->complex_num.re,
				-2.0 * fabs(z.re * z.im) + fractol->complex_num.im);
		iter++;
	}
	return (iter);
}