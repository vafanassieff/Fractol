/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:19:31 by vafanass          #+#    #+#             */
/*   Updated: 2017/02/02 19:18:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_PAD_ADD)
		e->zoom = e->zoom * 2;
	if (keycode == KEY_PAD_SUB)
		e->zoom = e->zoom / 2;
	if (keycode == KEY_R)
	{
		if (e->type == 1)
			mandelbrot_init(e);
		if (e->type == 2)
			julia_init(e);
		if (e->type == 3)
			burningship_init(e);
		if (e->type == 4)
		{
			mandelbrot_init(e);
			e->vx = -2;
		}
	}
	keycode_next(keycode, e);
	return (0);
}

int		keycode_next(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
		e->movex = e->movex - 0.2 / e->zoom;
	if (keycode == KEY_RIGHT)
		e->movex = e->movex + 0.2 / e->zoom;
	if (keycode == KEY_DOWN)
		e->movey = e->movey + 0.2 / e->zoom;
	if (keycode == KEY_UP)
		e->movey = e->movey - 0.2 / e->zoom;
	keycode_next_bis(keycode, e);
	return (0);
}

int		keycode_next_bis(int keycode, t_env *e)
{
	if (keycode == KEY_I)
		e->maxiter = e->maxiter + STEP;
	if (keycode == KEY_O)
		e->maxiter = e->maxiter - STEP;
	if (keycode == KEY_SHIFT_LEFT)
	{
		e->hue = e->hue - 10;
		e->value = e->value - 10;
	}
	keycode_next_ter(keycode, e);
	return (0);
}

int		keycode_next_ter(int keycode, t_env *e)
{
	if (keycode == KEY_1)
	{
		e->type = 1;
		mandelbrot_init(e);
	}
	if (keycode == KEY_2)
	{
		e->type = 2;
		julia_init(e);
	}
	if (keycode == KEY_3)
	{
		e->type = 3;
		burningship_init(e);
	}
	if (keycode == KEY_4)
	{
		e->type = 4;
		mandelbrot_init(e);
	}
	keycode_next_quater(keycode, e);
	return (0);
}

int		keycode_next_quater(int keycode, t_env *e)
{
	if (keycode == KEY_L)
	{
		if (e->mouselock == 1)
		{
			e->mouselock = 0;
			return (0);
		}
		if (e->mouselock == 0)
		{
			e->mouselock = 1;
			choose_type(*e);
		}
	}
	choose_type(*e);
	return (0);
}
