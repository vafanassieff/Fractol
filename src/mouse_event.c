/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:53:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/31 18:47:30 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (e->mouselock == 0)
	{
		if (button == 1 || button == 5)
		{
			e->zoom *= 2;
			choose_type(*e);
		}
		if (button == 2 || button == 4)
		{
			e->zoom /= 2;
			choose_type(*e);
		}
		e->mousex = x;
		e->mousey = y;
	}
	return (0);
}

void		change_julia(t_env *e, int x, int y)
{
	if (e->oldmousex < x)
		e->cre -= PADDLE;
	if (e->oldmousex > x)
		e->cre += PADDLE;
	if (e->oldmousey < y)
		e->cim -= PADDLE;
	if (e->oldmousey > y)
		e->cim += PADDLE;
}

int			ft_mouse(int x, int y, t_env *e)
{
	if (e->type == 2 && e->mouselock == 0)
	{
		if (e->oldmousex || e->oldmousey)
		{
			change_julia(e, x, y);
			choose_type(*e);
		}
		e->oldmousex = x;
		e->oldmousey = y;
	}
	return (0);
}
