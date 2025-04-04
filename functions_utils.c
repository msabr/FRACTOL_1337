/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:45:20 by msabr             #+#    #+#             */
/*   Updated: 2025/04/04 21:43:35 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to check if the argument is julia
double	scaling_func(double num, double new_min, double new_max)
{
	double	old_min;
	double	old_max;

	old_min = 0;
	old_max = 799;
	return ((
			new_max - new_min) * (num - old_min) / (old_max - old_min
		) + new_min);
}

// Function to convert a string to a double
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

// Function to convert a string to a double
double	atoi(char *str)
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

// Function to exit the program
int	exit_func(t_window *window)
{
	mlx_destroy_image(window->mlx, window->image.image);
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

// Function to put a pixel in the image
void	pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x *(img->bpp / 8));
	*(unsigned int *)(img->pixel + offset) = color;
}
