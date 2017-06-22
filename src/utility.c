/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:47:44 by vafanass          #+#    #+#             */
/*   Updated: 2017/02/02 19:35:08 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}
void	error_usage(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("[Tricorn]\n", 2);
	exit(0);
}
