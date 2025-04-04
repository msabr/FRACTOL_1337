/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:44:06 by msabr             #+#    #+#             */
/*   Updated: 2025/03/12 01:42:57 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to check if the argument is julia
int	julia_numbers_pars_helper(int i, int j, char **argv, int flag)
{
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
			j++;
		while (argv[i][j] != 32 && argv[i][j] != 9)
		{
			if (argv[i][j] && ((argv[i][j] == '-' || argv[i][j]
				== '+') || (argv[i][j] >= '0' && argv[i][j] <= '9')))
				j++;
			else if (argv[i][j] && argv[i][j] == '.' && flag == 1)
			{
				j++;
				flag = 0;
			}
			else
				break ;
		}
		while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
			j++;
		if (argv[i][j] != '\0')
			break ;
		flag = 1;
	}
	return (i);
}

// Function to check if the argument is mandelbrot
void	window_mlx(t_window *window)
{
	window_init(window);
	fractal_render(window);
	mlx_loop((window)->mlx);
}

// Function to set the complex number c
void	c_set(t_complex *c, t_window *window, int x, int y)
{
	if (ft_strncmp(window->name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		(*c).real = (scaling_func(x, -2, 2
					)) * window->zoom + window->x;
		(*c).imaginary = (scaling_func(y, 2, -2
					)) * window->zoom + window->y;
	}
	else if (ft_strncmp(window->name, "tricorn", ft_strlen("tricorn")) == 0)
	{
		(*c).real = (scaling_func(x, -2, 2
					)) * window->zoom + window->x;
		(*c).imaginary = (scaling_func(y, 2, -2
					)) * window->zoom + window->y;
	}
	else if (ft_strncmp(window->name, "julia", ft_strlen("julia")) == 0)
	{
		(*c).real = window->julia.real;
		(*c).imaginary = window->julia.imaginary;
	}
}

// Function to set the complex number z
void	z_set(t_complex *z, t_window *window, int x, int y)
{
	(*z).real = (scaling_func(x, -2, 2
				)) * window->zoom + window->x;
	(*z).imaginary = (scaling_func(y, 2, -2
				)) * window->zoom + window->y;
}

// Function to put a pixel in the image
void	tricorn_calculations(t_complex *z, t_complex *c)
{
	double	tmpreal;
	double	r2;
	double	i2;

	r2 = (*z).real * (*z).real;
	i2 = (*z).imaginary * (*z).imaginary;
	tmpreal = r2 - i2 + (*c).real;
	(*z).imaginary = -2 * (*z).real * (*z).imaginary + (*c).imaginary;
	(*z).real = tmpreal;
}
