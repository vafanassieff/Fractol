/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:26:14 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/26 20:40:34 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_img(t_env env, t_mandelbrot m)
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
			m.color = hsv2rgb(m.i % 256, 255, 255 * (m.i < m.maxIterations));
			m.xlen = (m.x * 4) + (m.y * env.isize);
			put_pixel(m.xlen, m.color, env);
		}
	}
	env.put = mlx_put_image_to_window(env.mlx, env.win, env.iptr, 0, 0);
}

void	mandelbrot(void)
{
	t_env			env;
	t_mandelbrot	m;

	if (!(env.mlx = mlx_init()))
		error(ERR_MLX);
	if (!(env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, "Mandelbrot")))
		error(ERR_MLX);
	if (!(env.iptr = mlx_new_image(env.mlx, SCREEN_X, SCREEN_Y)))
		error(ERR_MLX);
	env.img = mlx_get_data_addr(env.iptr, &env.bpp, &env.isize, &env.endian);
	m = mandelbrot_init();
	display_img(env, m);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
}
