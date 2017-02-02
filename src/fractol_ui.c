/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:00:43 by vafanass          #+#    #+#             */
/*   Updated: 2017/02/02 18:03:49 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_ui(t_env *e)
{
	char dest[20];

	ft_strcpy(dest, "Itterations = ");
	ft_strcat(dest, ft_itoa(e->maxiter));
	mlx_string_put(e->mlx, e->win, 10, 600, WHITE, "Lock Mouse = L");
	mlx_string_put(e->mlx, e->win, 10, 620, WHITE, "+/- Itteration = I/O");
	mlx_string_put(e->mlx, e->win, 10, 640, WHITE, "Change Color = LSHIFT");
	mlx_string_put(e->mlx, e->win, 10, 660, WHITE, "+/- Zoom = +/-");
	mlx_string_put(e->mlx, e->win, 10, 680, WHITE, "Reset Fractal = R");
	mlx_string_put(e->mlx, e->win, 250, 600, WHITE, "Choose Fracral = 1/2/3..");
	mlx_string_put(e->mlx, e->win, 250, 620, WHITE, "Moove = Arrow Key");
	mlx_string_put(e->mlx, e->win, 250, 640, WHITE, dest);
}
