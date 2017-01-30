/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:53:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 18:00:13 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
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
	printf("button = %d x = %d y = %d\n", button, x, y);
	return (0);
}

int			ft_mouse(int x, int y, t_env *env)
{
	printf("x = %d y = %d\n", x, y);
	env->mousex = x;
	return (0);
}
