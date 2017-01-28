/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:43:33 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/28 17:14:04 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_env *m)
{
	m->h = SCREEN_Y;
	m->w = SCREEN_X;
	m->zoom = 0.75;
	m->moveX = 0;
	m->moveY = 0;
	m->maxIterations = DEFAULT_I;
	m->y = -1;
	m->hue = 256;
	m->value = 255;
}

t_env	man_init_bis(t_env m)
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

void	display_man(t_env m)
{
	while (m.y++ < m.h)
	{
		m.x = -1;
		while (m.x++ < m.w)
		{
			m = man_init_bis(m);
			while (m.i++ < m.maxIterations)
			{
				m.oldRe = m.newRe;
				m.oldIm = m.newIm;
				m.newRe = m.oldRe * m.oldRe - m.oldIm * m.oldIm + m.pr;
				m.newIm = 2 * m.oldRe * m.oldIm + m.pi;
				if ((m.newRe * m.newRe + m.newIm * m.newIm) > 4)
					break ;
			}
			m.color = hsv2rgb(m.i % m.hue, 255, m.value * (m.i < m.maxIterations));
			m.xlen = (m.x * 4) + (m.y * m.isize);
			put_pixel(m.xlen, m.color, m);
		}
	}
	m.put = mlx_put_image_to_window(m.mlx, m.win, m.iptr, 0, 0);
}

void	mandel_before(t_env m)
{
	display_man(m);
	mlx_key_hook(m.win, key_hook, &m);
	mlx_loop(m.mlx);
}
