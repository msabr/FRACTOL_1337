/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:32:37 by msabr             #+#    #+#             */
/*   Updated: 2025/03/12 01:54:15 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to exit the program
static int	key_func(int key, t_window *window)
{
	if (key == 53)		// 53 = ESC
		exit_func(window);
	if (key == 123)		// 123 = left arrow key
		window->x -= (0.5 * window->zoom);
	if (key == 124)		// 124 = right arrow key
		window->x += (0.5 * window->zoom);
	if (key == 125)		// 125 = down arrow key
		window->y -= (0.5 * window->zoom);
	if (key == 126)		// 126 = up arrow key
		window->y += (0.5 * window->zoom);
	if (key == 83)		// 83 = 1 key
		window->color = 0x020a13;
	if (key == 84)		// 84 = 2 key
		window->color = 0x000500;
	if (key == 85)		// 85 = 3 key
		window->color = 0x080808;
	if (key == 86)		// 86 = 4 key
		window->color = 0x080000;
	fractal_render(window);
	return (0);
}

// Funtion to exit the program
static int	mouse_func(int button, int x, int y, t_window *window)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (!window)
		return (0);
	mouse_x = (scaling_func(x, -2, 2)) * window->zoom + window->x;
	mouse_y = (scaling_func(y, 2, -2)) * window->zoom + window->y;
	if (button == 4)
		zoom_factor = 2.0;
	else if (button == 5)
		zoom_factor = 0.5;
	else
		return (0);
	window->zoom *= zoom_factor;
	window->x = mouse_x - (scaling_func(x, -2, 2)) * window->zoom;
	window->y = mouse_y - (scaling_func(y, 2, -2)) * window->zoom;
	fractal_render(window);
	return (0);
}

// Function to exit the program
void	init_events(t_window *window)
{
	mlx_key_hook(window->win, key_func, window);
	mlx_mouse_hook(window->win, mouse_func, window);
	mlx_hook(window->win, 17, 0, exit_func, window);
}
