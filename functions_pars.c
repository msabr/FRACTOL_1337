/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:45:15 by msabr             #+#    #+#             */
/*   Updated: 2025/03/12 01:48:42 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to check if the argument is julia
static int	check_empty(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '\0')
		return (1);
	while (argv[i] == 32 || argv[i] == 9)
		i++;
	if (argv[i] == '\0')
		return (1);
	return (0);
}

// Function to check if the argument is julia
static int	julia_numbers_pars(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 2;
	j = 0;
	flag = 1;
	if (check_empty(argv[i]) == 1)
		return (1);
	i = 1;
	i = julia_numbers_pars_helper(i, j, argv, flag);
	if (i == 4 && !argv[i])
		return (1);
	return (0);
}

// Function to check if the argument is mandelbrot
int	mandelbrot_check(char *argv)
{
	int		i;
	int		j;
	char	*str1;

	str1 = "mandelbrot";
	i = 0;
	j = 0;
	if (check_empty(argv) == 1)
		return (1);
	while (argv[i] == 32 || argv[i] == 9)
		i++;
	while (argv[i] && argv[i] == str1[j])
	{
		i++;
		j++;
	}
	while (argv[i] == 32 || argv[i] == 9)
		i++;
	if (argv[i] == '\0' && str1[j] == '\0')
		return (0);
	return (1);
}

// Function to check if the argument is tricorn
int	tricorn_check(char *argv)
{
	int		i;
	int		j;
	char	*str1;

	str1 = "tricorn";
	i = 0;
	j = 0;
	if (check_empty(argv) == 1)
		return (1);
	while (argv[i] == 32 || argv[i] == 9)
		i++;
	while (argv[i] && argv[i] == str1[j])
	{
		i++;
		j++;
	}
	while (argv[i] == 32 || argv[i] == 9)
		i++;
	if (argv[i] == '\0' && str1[j] == '\0')
		return (0);
	return (1);
}

// Function to check if the argument is julia
int	julia_check(char **argv)
{
	int		i;
	int		j;
	char	*str1;

	str1 = "julia";
	i = 0;
	j = 0;
	if (check_empty(argv[1]) == 1)
		return (1);
	while (argv[1][i] == 32 || argv[1][i] == 9)
		i++;
	while (argv[1][i] && argv[1][i] == str1[j])
	{
		i++;
		j++;
	}
	while (argv[1][i] == ' ' || argv[1][i] == 9)
		i++;
	if (argv[1][i] == '\0' && str1[j] == '\0')
	{
		return (julia_numbers_pars(argv));
	}
	return (0);
}
