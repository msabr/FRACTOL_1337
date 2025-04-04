/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:33:26 by msabr             #+#    #+#             */
/*   Updated: 2025/03/12 01:43:12 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to set the complex number c
void	regular_calculations(t_complex *z, t_complex *c)
{
	double	tmpreal;

	tmpreal = ((*z).real * (*z).real) - ((
				*z).imaginary * (*z).imaginary) + (*c).real;
	(*z).imaginary = 2 * (*z).real * (*z).imaginary + (*c).imaginary;
	(*z).real = tmpreal;
}

// Function to set the complex number c
void	calculations(t_complex *z, t_complex *c, t_window *window)
{
	if (ft_strncmp(window->name, "tricorn", ft_strlen("tricorn")) == 0)
		tricorn_calculations(z, c);
	else
		regular_calculations(z, c);
}

// Function to set the complex number c
void	colors(int i, int x, int y, t_window *window)
{
	double	color;

	color = get_color(i, window);
	pixel_put(x, y, &window->image, color);
}

// Function to set the complex number c
void	handl_pixel_inits(int *i, t_complex *z)
{
	(*i) = -1;
	(*z).real = 0;
	(*z).imaginary = 0;
}
