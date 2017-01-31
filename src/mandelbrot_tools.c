/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:43:33 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/31 20:17:10 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_env *m)
{
	m->h = SCREEN_Y;
	m->w = SCREEN_X;
	m->zoom = 1;
	m->movex = 0;
	m->movey = 0;
	m->maxiter = DEFAULT_I;
	m->y = -1;
	m->hue = 256;
	m->value = 255;
}

t_env	man_init_bis(t_env m)
{
	m.pr = 1.5 * (m.x - m.w / 2) / (0.5 * m.zoom * m.w) + m.movex;
	m.pi = (m.y - m.h / 2) / (0.5 * m.zoom * m.h) + m.movey;
	m.newre = 0;
	m.newim = 0;
	m.oldre = 0;
	m.oldim = 0;
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
			while (m.i++ < m.maxiter)
			{
				m.oldre = m.newre;
				m.oldim = m.newim;
				m.newre = m.oldre * m.oldre - m.oldim * m.oldim + m.pr;
				m.newim = 2 * m.oldre * m.oldim + m.pi;
				if ((m.newre * m.newre + m.newim * m.newim) > 4)
					break ;
			}
			m.color = hsv2rgb(m.i % m.hue, 255, m.value * (m.i < m.maxiter));
			put_pixel(m);
		}
	}
	m.put = mlx_put_image_to_window(m.mlx, m.win, m.iptr, 0, 0);
}
