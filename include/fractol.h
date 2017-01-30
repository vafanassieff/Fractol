/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:35:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/30 15:09:48 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "mlx_key_osx.h"
# include <math.h>
# include <stdio.h>

# define SCREEN_X 800
# define SCREEN_Y 600
# define DEFAULT_I 100
# define STEP 5

typedef	struct	s_color
{
	char			r;
	char			g;
	char			b;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*iptr;
	char		*img;
	int			bpp;
	int			endian;
	int			isize;
	int			put;
	int			type;
	t_color		color;
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	double		zoom;
	double		moveX;
	double		moveY;
	double		cRe;
	double		cIm;
	int			hue;
	int			value;
	int			maxIter;
	int			h;
	int			w;
	int			x;
	int			y;
	int			i;
	int			xlen;
}				t_env;

typedef struct s_colorspace
{
	double		r;
	double		g;
	double		b;
	double		h;
	double		s;
	double		v;
	double		q;
	int			i;
	double		f;
	double		p;
	double		a;
	double		t;
	int			ret;
	t_color		color;
}				t_colorspace;

# define ERR_USAGE "Wrong usage\nUse ./fractol [Mandelbrot] [Julia] [3eme]"
# define ERR_MLX "Mlx issue\nExiting"

void			choose_type(t_env env);
void			mandel_before(t_env m);
void			error(char *message);
void			fractal(t_env e);
void			display_man(t_env m);
void            put_pixel(int here, t_color color, t_env env);
int				key_hook(int keycode, t_env *e);
void			mandelbrot_init(t_env *m);
void			julia_init(t_env *j);
t_env		    man_init_bis(t_env m);
t_color			hsv2rgb(float hue, float saturation, float value);
void			julia_before(t_env j);
void			burningship_before(t_env s);
void			burningship_init(t_env *s);

#endif
