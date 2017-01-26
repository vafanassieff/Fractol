/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:47:44 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/26 14:20:57 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *message)
{
	ft_putendl(message);
	exit(0);
}

void	print_help(void)
{
	ft_putendl("Usage for this program :");
	ft_putendl("./fractol [fractal]\nFractal are :\nMandelbrot\nJulia\n3eme");
}
