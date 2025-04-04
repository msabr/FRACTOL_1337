/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:29:55 by msabr             #+#    #+#             */
/*   Updated: 2025/04/04 22:02:13 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc == 2 && (!mandelbrot_check(argv[1]) || !tricorn_check(argv[1])))
	{
		if (mandelbrot_check(argv[1]) == 0)
			window.name = "mandelbrot";
		else if (tricorn_check(argv[1]) == 0)
			window.name = "tricorn";
		window_mlx(&window);
	}
	else if (argc == 4 && julia_check(argv) == 1)
	{
		window.julia.real = ft_atoi(argv[2]);
		window.julia.imaginary = ft_atoi(argv[3]);
		if (window.julia.real > 2 || window.julia.real < -2)
			return (print_error(), 0);
		if (window.julia.imaginary > 2 || window.julia.imaginary < -2)
			return (print_error(), 0);
		window.name = "julia";
		window_mlx(&window);
	}
	else
		return (print_error(), 0);
}
