/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:26:14 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 18:00:20 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_type(t_env env)
{
	if (env.type == 1)
		display_man(env);
	if (env.type == 2)
		display_julia(env);
	if (env.type == 3)
		display_ship(env);
}

void	fractal(t_env e)
{
	if (!(e.mlx = mlx_init()))
		error(ERR_MLX);
	if (!(e.win = mlx_new_window(e.mlx, SCREEN_X, SCREEN_Y, "Fract'ol")))
		error(ERR_MLX);
	if (!(e.iptr = mlx_new_image(e.mlx, SCREEN_X, SCREEN_Y)))
		error(ERR_MLX);
	e.img = mlx_get_data_addr(e.iptr, &e.bpp, &e.isize, &e.endian);
	choose_type(e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, (1L << 6), ft_mouse, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
