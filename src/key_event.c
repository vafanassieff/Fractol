/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:19:31 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/26 16:08:18 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *env)
{
		if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		{
			env->isize = 1;
			exit(0);
		}
		return (0);
}
