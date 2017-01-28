/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:26:14 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/28 15:13:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_type(t_env env)
{
	if (env.type == 1)
		mandel_before(env);
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
}
