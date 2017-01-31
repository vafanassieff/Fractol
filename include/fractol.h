/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:35:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/31 17:44:53 by vafanass         ###   ########.fr       */
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
# define PADDLE 0.01

typedef	struct	s_color
{
	char		r;
	char		g;
	char		b;
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
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		movex;
	double		movey;
	double		cre;
	double		cim;
	int			hue;
	int			value;
	int			maxiter;
	int			h;
	int			w;
	int			x;
	int			y;
	int			i;
	int			mousex;
	int			mousey;
	int			oldmousex;
	int			oldmousey;
	char		mouselock;
}				t_env;

typedef struct	s_colorspace
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

# define ERR_USAGE "Wrong usage\nUse ./fractol [Mandelbrot][Julia][BurningShip]"
# define ERR_MLX "Mlx issue\nExiting"

void			choose_type(t_env env);
void			error(char *message);
void			fractal(t_env e);
void			display_man(t_env m);
void			display_julia(t_env j);
void			display_ship(t_env m);
void			put_pixel(t_env env);
void			mandelbrot_init(t_env *m);
void			julia_init(t_env *j);
void            burningship_init(t_env *s);
t_env			man_init_bis(t_env m);
t_color			hsv2rgb(float hue, float saturation, float value);
int             key_hook(int keycode, t_env *e);
int				keycode_next(int keycode, t_env *e);
int				keycode_next_bis(int keycode, t_env *e);
int				keycode_next_ter(int keycode, t_env *e);
int				keycode_next_quater(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				ft_mouse(int x, int y, t_env *env);
#endif
