/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:33:47 by msabr             #+#    #+#             */
/*   Updated: 2025/04/04 21:41:36 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to exit the program
void	print_error(void)
{
	ft_putstr_fd("\nthe correct prototypes for this ", 2);
	ft_putstr_fd("program are the following\n\n\n", 2);
	ft_putstr_fd("\t\t./fractol mandelbrot\n\t./fractol multibrot\n", 2);
	ft_putstr_fd("\t\t./fractol julia <value> <value2>\n\n", 2);
	ft_putstr_fd("the values in the julia fractal ", 2);
	ft_putstr_fd("should be in the interval [-2, 2]\n", 2);
	exit(1);
}

// Function to check if the argument is mandelbrot
void	more_inits(t_window *window)
{
	window->x = 0;
	window->y = 0;
	window->zoom = 1.0;
	window->max_iter = 100;
	window->color = 0x123456;
	window->image.pixel = mlx_get_data_addr(window->image.image,
			&window->image.bpp, &window->image.line_len, &window->image.endian);
}
