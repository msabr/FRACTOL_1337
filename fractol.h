/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:33:38 by msabr             #+#    #+#             */
/*   Updated: 2025/04/04 21:45:25 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// bibliotheques
# include "../Libft/libft.h"
# include <mlx.h>

// macros
# define WIDTH 900 
# define HEIGHT 900

// structures
typedef struct s_image
{
	void	*image;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_window
{
	double		x;
	double		y;
	void		*mlx;
	void		*win;
	double		zoom;
	int			max_iter;
	int			color;
	char		*name;
	t_complex	julia;
	t_image		image;
}	t_window;

// prototypes
int		julia_check(char **argv);
int		mandelbrot_check(char *argv);
double	scaling_func(double num, double new_min, double new_max);
double	atoi(char *str);
int		exit_func(t_window *window);
void	pixel_put(int x, int y, t_image *img, int color);
void	window_init(t_window *window);
void	fractal_render(t_window *window);
void	init_events(t_window *window);
int		tricorn_check(char *argv);
int		julia_numbers_pars_helper(int i, int j, char **argv, int flag);
void	window_mlx(t_window *window);
void	c_set(t_complex *c, t_window *window, int x, int y);
void	z_set(t_complex *z, t_window *window, int x, int y);
void	tricorn_calculations(t_complex *z, t_complex *c);
void	regular_calculations(t_complex *z, t_complex *c);
void	calculations(t_complex *z, t_complex *c, t_window *window);
void	colors(int i, int x, int y, t_window *window);
void	handl_pixel_inits(int *i, t_complex *z);
void	print_error(void);
int		get_color(int i, t_window *window);
void	more_inits(t_window *window);

#endif // FRACTOL_H