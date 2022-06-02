/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:58:41 by iugolin           #+#    #+#             */
/*   Updated: 2022/05/31 10:29:35 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractol)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < fractol->max_iter)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k->re,
				2.0 * z.re * z.im + fractol->k->im);
		iter++;
	}
	return (iter);
}

t_complex	*set_julia_k(double k_re, double k_im)
{
	t_complex	*set;

	set = (t_complex *)malloc(sizeof(t_complex));
	if (!set)
		print_error("Allocate memory error\n");
	set->re = k_re;
	set->im = k_im;
	return (set);
}

t_julset	*set_juliasets(void)
{
	t_julset	*julia_sets;

	julia_sets = (t_julset *)malloc((sizeof(t_julset)));
	if (!julia_sets)
		print_error("Allocate memory error\n");
	julia_sets->first = set_julia_k(-0.7, 0.27);
	julia_sets->second = set_julia_k(0.294, -0.014);
	julia_sets->third = set_julia_k(-0.4, 0.6);
	julia_sets->fourth = set_julia_k(-0.8, 0.156);
	return (julia_sets);
}

void	julia_set_selector(t_fractol *fractol)
{
	if (fractol->k == fractol->julia_sets->first)
		fractol->k = fractol->julia_sets->second;
	else if (fractol->k == fractol->julia_sets->second)
		fractol->k = fractol->julia_sets->third;
	else if (fractol->k == fractol->julia_sets->third)
		fractol->k = fractol->julia_sets->fourth;
	else if (fractol->k == fractol->julia_sets->fourth)
		fractol->k = fractol->julia_sets->first;
	else
		fractol->k = fractol->julia_sets->first;
}
