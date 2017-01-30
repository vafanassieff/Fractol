/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:08:37 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 16:22:01 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(t_env env)
{
	int here;

	here = (env.x * 4) + (env.y * env.isize);
	ft_memset(&env.img[0 + here], env.color.b, 1);
	ft_memset(&env.img[1 + here], env.color.g, 1);
	ft_memset(&env.img[2 + here], env.color.r, 1);
}

t_colorspace	hsv_init(float hue, float saturation, float value)
{
	t_colorspace c;

	c.h = hue / 360;
	c.s = saturation / 100;
	c.v = value / 100;
	c.i = floor(c.h * 6);
	c.f = c.h * 6 - c.i;
	c.p = c.v * (1 - c.s);
	c.q = c.v * (1 - c.f * c.s);
	c.t = c.v * (1 - (1 - c.f) * c.s);
	c.ret = c.i % 6;
	return (c);
}

t_colorspace	hsv2rgbis(t_colorspace c)
{
	if (c.ret == 2)
	{
		c.r = c.p;
		c.g = c.v;
		c.b = c.t;
	}
	if (c.ret == 3)
	{
		c.r = c.p;
		c.g = c.q;
		c.b = c.v;
	}
	if (c.ret == 4)
	{
		c.r = c.t;
		c.g = c.p;
		c.b = c.v;
	}
	if (c.ret == 5)
	{
		c.r = c.v;
		c.g = c.p;
		c.b = c.q;
	}
	return (c);
}

t_color			hsv2rgb(float hue, float saturation, float value)
{
	t_colorspace c;

	c = hsv_init(hue, saturation, value);
	if (c.ret == 0)
	{
		c.r = c.v;
		c.g = c.t;
		c.b = c.p;
	}
	if (c.ret == 1)
	{
		c.r = c.q;
		c.g = c.v;
		c.b = c.p;
	}
	c = hsv2rgbis(c);
	c.color.r = c.r * 255;
	c.color.g = c.g * 255;
	c.color.b = c.b * 255;
	return (c.color);
}
