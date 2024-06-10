/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:37:08 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/21 16:39:23 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define WIDTH	1000
# define HEIGHT	1000
# define BLUE			0x0000FF 
# define ORANGE			0xFF6600
# define BLACK			0x000000
# define PURPLE			0x9932CC

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bit_par_px;
	int		bit_order;
	int		pix_len;
}				t_img;
typedef struct s_fractol
{
	int		name;
	void	*mlx_conex;
	void	*mlx_window;
	t_img	img;
	int		iterations;
	int		current_colour;
	double	julia_r;
	double	julia_i;
	int		x_offset;
	int		y_offset;
	double	zoom;
}				t_fractol;
typedef struct s_julia_vars
{
	double	zx;
	double	zy;
	double	c_r;
	double	c_i;
}				t_julia_vars;
typedef struct s_mandelbrot
{
	double	pr;
	double	pi;
	double	a;
	double	b;
}				t_mandelbrot;
int		calculate_julia(t_fractol *fract, int x, int y);
void	handle_julia(t_fractol *fractal, char *param1, char *param2);
void	handle_mandelbrot(t_fractol *fractal);
void	handle_events(t_fractol *fractal);
void	drawing_fractol(t_fractol *fract);
int		calculate_mandelbrot(t_fractol *fract, int x, int y);
int		choose_color(int iteration, t_fractol *f);
void	my_mlx_pixel_put(t_fractol *fract, int x, int y, int color);
int		ft_strcmp(char *s1, char *s2);
void	make_data(t_fractol *fract);
void	make_fractal(t_fractol *fract);
void	make_img(t_fractol *fract);
void	make_window(t_fractol *fract);
double	ft_atof(char *s);
int		is_valid_arg(char *str);
int		ft_isdigit(char c);


int    get_trgb(int iters);
#endif
