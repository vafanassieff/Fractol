/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:34:26 by vafanass          #+#    #+#             */
/*   Updated: 2017/02/02 19:35:10 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_arg(char *arg, t_env e)
{
	if (ft_strcmp(arg, "Tricorn") == 0)
	{
		e.type = 4;
		mandelbrot_init(&e);
		fractal(e);
	}
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		error_usage(ERR_USAGE);
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		e.type = 1;
		mandelbrot_init(&e);
		fractal(e);
	}
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		e.type = 2;
		julia_init(&e);
		fractal(e);
	}
	if (ft_strcmp(argv[1], "BurningShip") == 0)
	{
		e.type = 3;
		burningship_init(&e);
		fractal(e);
	}
	parse_arg(argv[1], e);
	error_usage(ERR_USAGE);
	return (0);
}
