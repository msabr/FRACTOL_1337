/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:54:04 by msabr             #+#    #+#             */
/*   Updated: 2025/08/29 17:04:56 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	atoi_helper(char *str, int i)
{
	double	fraction;
	double	power;

	fraction = 0.0;
	power = 1.0;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		power /= 10;
		fraction = fraction + (str[i] - '0') * power;
		i++;
	}
	return (fraction);
}

double	ft_atoi(char *str)
{
	double	number;
	int		sign;
	int		i;

	sign = 1;
	number = 0.0;
	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return ((atoi_helper(str, i) + number) * sign);
}
