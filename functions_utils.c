/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:45:20 by msabr             #+#    #+#             */
/*   Updated: 2025/04/04 21:59:30 by msabr            ###   ########.fr       */
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
