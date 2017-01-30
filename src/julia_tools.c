/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:13:31 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 17:05:29 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_env *j)
{
	j->h = SCREEN_Y;
	j->w = SCREEN_X;
	j->zoom = 1;
	j->movex = 0;
	j->movey = 0;
	j->maxiter = DEFAULT_I;
	j->cre = -0.7;
	j->cim = 0.27015;
	j->y = -1;
	j->hue = 256;
	j->value = 255;
}

void	display_julia(t_env j)
{
	while (j.y++ < j.h)
	{
		j.x = -1;
		while (j.x++ < j.w)
		{
			j.newre = 1.5 * (j.x - j.w / 2) / (0.5 * j.zoom * j.w) + j.movex;
			j.newim = (j.y - j.h / 2) / (0.5 * j.zoom * j.h) + j.movey;
			j.i = -1;
			while (j.i++ < j.maxiter)
			{
				j.oldre = j.newre;
				j.oldim = j.newim;
				j.newre = j.oldre * j.oldre - j.oldim * j.oldim + j.cre;
				j.newim = 2 * j.oldre * j.oldim + j.cim;
				if ((j.newre * j.newre + j.newim * j.newim) > 4)
					break ;
			}
			j.color = hsv2rgb(j.i % j.hue, 255, j.value * (j.i < j.maxiter));
			put_pixel(j);
		}
	}
	j.put = mlx_put_image_to_window(j.mlx, j.win, j.iptr, 0, 0);
}
