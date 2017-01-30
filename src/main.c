/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:34:26 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 14:37:17 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		error(ERR_USAGE);
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
	error(ERR_USAGE);
	return (0);
}
