/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:34:26 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/28 16:29:37 by vafanass         ###   ########.fr       */
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
	if (ft_strcmp(argv[1], "3eme") == 0)
		fractal(e);
	if (ft_strcmp(argv[1], "help") == 0)
		error(ERR_USAGE);
	else
		error(ERR_USAGE);
	return (0);
}
