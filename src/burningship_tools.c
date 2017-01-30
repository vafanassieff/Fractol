/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:05:46 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 15:05:30 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_env *m)
{
	m->h = SCREEN_Y;
	m->w = SCREEN_X;
	m->zoom = 0.75;
	m->moveX = -0.5;
	m->moveY = 0;
	m->maxIter = DEFAULT_I;
	m->y = -1;
	m->hue = 256;
	m->value = 255;
}

t_env	burning_init_bis(t_env m)
{
	m.pr = 1.5 * (m.x - m.w / 2) / (0.5 * m.zoom * m.w) + m.moveX;
	m.pi = 1.5 * (m.y - m.h / 2) / (0.5 * m.zoom * m.h) + m.moveY;
	m.newRe = 0;
	m.newIm = 0;
	m.oldRe = 0;
	m.oldIm = 0;
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
			while (m.i++ < m.maxIter)
			{
				m.oldRe = m.newRe;
				m.oldIm = m.newIm;
				m.newRe = fabs(m.oldRe * m.oldRe - m.oldIm * m.oldIm + m.pr);
				m.newIm = fabs(m.oldRe * m.oldIm + m.oldRe * m.oldIm + m.pi);
				if ((m.newRe * m.newRe + m.newIm * m.newIm) > 10)
					break ;
			}
			m.color = hsv2rgb(m.i % m.hue, 255, m.value * (m.i < m.maxIter));
			m.xlen = (m.x * 4) + (m.y * m.isize);
			put_pixel(m.xlen, m.color, m);
		}
	}
	m.put = mlx_put_image_to_window(m.mlx, m.win, m.iptr, 0, 0);
}

void	burningship_before(t_env b)
{
	display_ship(b);
	mlx_key_hook(b.win, key_hook, &b);
	mlx_loop(b.mlx);
}
