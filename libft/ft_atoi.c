/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:31:35 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/27 16:19:00 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_digit(char c)
{
	if (!ft_isdigit(c) && c != '\0')
	{
		ft_putendl_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
}

static void	check_max_min_int(unsigned long number, int sign)
{
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
	{
		ft_putendl_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	check_digit(*str);
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
		check_digit(*str);
	}
	check_max_min_int(number, sign);
	return (number * sign);
}
