/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:35:27 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/26 20:40:38 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "mlx_key_osx.h"
# include <math.h>

# define SCREEN_X 500
# define SCREEN_Y 375

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
}				t_env;

typedef struct	s_mandelbrot
{
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
	int			maxIterations;
	int			h;
	int			w;
	int			x;
	int			y;
	int			i;
	int			xlen;
}				t_mandelbrot;

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

void			print_help(void);
void			error(char *message);
void			mandelbrot(void);
int				key_hook(int keycode, t_env *env);
void			put_pixel(int here, t_color color, t_env env);
int				xy_to_x(int x, int y, t_env env);
t_mandelbrot	mandelbrot_init(void);
t_mandelbrot    man_init_bis(t_mandelbrot m);
t_color			hsv2rgb(float hue, float saturation, float value);

#endif
