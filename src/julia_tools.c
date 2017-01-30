/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:13:31 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 15:05:34 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_env *j)
{
	j->h = SCREEN_Y;
	j->w = SCREEN_X;
	j->zoom = 1;
	j->moveX = 0;
	j->moveY = 0;
	j->maxIter = DEFAULT_I;
	j->cRe = -0.7;
	j->cIm = 0.27015;
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
			j.newRe = 1.5 * (j.x - j.w / 2) / (0.5 * j.zoom * j.w) + j.moveX;
			j.newIm = (j.y - j.h / 2) / (0.5 * j.zoom * j.h) + j.moveY;
			j.i = -1;
			while (j.i++ < j.maxIter)
			{
				j.oldRe = j.newRe;
				j.oldIm = j.newIm;
				j.newRe = j.oldRe * j.oldRe - j.oldIm * j.oldIm + j.cRe;
				j.newIm = 2 * j.oldRe * j.oldIm + j.cIm;
				if ((j.newRe * j.newRe + j.newIm * j.newIm) > 4)
					break ;
			}
			j.color = hsv2rgb(j.i % j.hue, 255, j.value * (j.i < j.maxIter));
			j.xlen = (j.x * 4) + (j.y * j.isize);
			put_pixel(j.xlen, j.color, j);
		}
	}
	j.put = mlx_put_image_to_window(j.mlx, j.win, j.iptr, 0, 0);
}

void	julia_before(t_env j)
{
	display_julia(j);
	mlx_key_hook(j.win, key_hook, &j);
	mlx_loop(j.mlx);
}
