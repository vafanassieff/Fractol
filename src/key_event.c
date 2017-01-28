/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:19:31 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/28 16:29:44 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_PAD_ADD)
	{
		e->zoom = e->zoom * 2;
		choose_type(*e);
	}
	if (keycode == KEY_PAD_SUB)
	{
		e->zoom = e->zoom / 2;
		choose_type(*e);
	}
	if (keycode == KEY_R)
	{
		if (e->type == 1)
			mandelbrot_init(e);
		if (e->type == 2)
			julia_init(e);
		choose_type(*e);
	}
	if (keycode == KEY_LEFT)
	{
		e->moveX = e->moveX - 0.1 / e->zoom;
		choose_type(*e);
	}
	if (keycode == KEY_RIGHT)
	{
		e->moveX = e->moveX + 0.1 / e->zoom;
		choose_type(*e);
	}
	if (keycode == KEY_DOWN)
	{
		e->moveY = e->moveY + 0.1 / e->zoom;
		choose_type(*e);
	}
	if (keycode == KEY_UP)
	{
		e->moveY = e->moveY - 0.1 / e->zoom;
		choose_type(*e);
	}
	if (keycode == KEY_I)
	{
		e->maxIterations = e->maxIterations + 5;
		choose_type(*e);
	}
	if (keycode == KEY_O)
	{
		e->maxIterations = e->maxIterations - 5;
		choose_type(*e);
	}
	return (0);
}
