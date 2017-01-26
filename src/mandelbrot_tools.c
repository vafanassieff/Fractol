/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:43:33 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/26 20:40:36 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandelbrot	mandelbrot_init(void)
{
	t_mandelbrot	m;

	m.h = SCREEN_Y;
	m.w = SCREEN_X;
	m.zoom = 1;
	m.moveX = -0.5;
	m.moveY = 0;
	m.maxIterations = 1000;
	m.y = -1;
	return (m);
}

t_mandelbrot	man_init_bis(t_mandelbrot m)
{
	m.pr = 1.5 * (m.x - m.w / 2) / (0.5 * m.zoom * m.w) + m.moveX;
	m.pi = (m.y - m.h / 2) / (0.5 * m.zoom * m.h) + m.moveY;
	m.newRe = 0;
	m.newIm = 0;
	m.oldRe = 0;
	m.oldIm = 0;
	m.i = -1;
	return (m);
}

