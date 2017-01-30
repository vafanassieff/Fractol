/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:05:46 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 17:05:40 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_env *m)
{
	m->h = SCREEN_Y;
	m->w = SCREEN_X;
	m->zoom = 0.75;
	m->movex = -0.5;
	m->movey = 0;
	m->maxiter = DEFAULT_I;
	m->y = -1;
	m->hue = 256;
	m->value = 255;
}

t_env	burning_init_bis(t_env m)
{
	m.pr = 1.5 * (m.x - m.w / 2) / (0.5 * m.zoom * m.w) + m.movex;
	m.pi = 1.5 * (m.y - m.h / 2) / (0.5 * m.zoom * m.h) + m.movey;
	m.newre = 0;
	m.newim = 0;
	m.oldre = 0;
	m.oldim = 0;
	m.i = -1;
	return (m);
}

void	display_ship(t_env m)
{
	while (m.y++ < m.h)
	{
		m.x = -1;
		while (m.x++ < m.w)
		{
			m = burning_init_bis(m);
			while (m.i++ < m.maxiter)
			{
				m.oldre = m.newre;
				m.oldim = m.newim;
				m.newre = fabs(m.oldre * m.oldre - m.oldim * m.oldim + m.pr);
				m.newim = fabs(m.oldre * m.oldim + m.oldre * m.oldim + m.pi);
				if ((m.newre * m.newre + m.newim * m.newim) > 10)
					break ;
			}
			m.color = hsv2rgb(m.i % m.hue, 255, m.value * (m.i < m.maxiter));
			put_pixel(m);
		}
	}
	m.put = mlx_put_image_to_window(m.mlx, m.win, m.iptr, 0, 0);
}
