/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:26:48 by kahmada           #+#    #+#             */
/*   Updated: 2024/06/06 17:50:19 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_mandelbrot(t_fractol *fractal)
{
	fractal->name = 1;
	fractal->zoom = 1.0;
	make_fractal(fractal);
	drawing_fractol(fractal);
	handle_events(fractal);
	mlx_loop(fractal->mlx_conex);
}

int	calculate_mandelbrot(t_fractol *fract, int x, int y)
{
	t_mandelbrot	params;
	int				iterations;
	double			temp;

	params.pr = 4.0 * ((double)(x + fract->x_offset)
			- WIDTH / 2) / WIDTH / fract->zoom;
	params.pi = 4.0 * ((double)(y + fract->y_offset)
			- HEIGHT / 2) / HEIGHT / fract->zoom;
	params.a = 0.0;
	params.b = 0.0;
	iterations = 0;
	while (iterations < fract->iterations)
	{
		temp = params.a * params.a
			- params.b * params.b + params.pr;
		params.b = 2 * params.a * params.b + params.pi;
		params.a = temp;
		if ((params.a * params.a + params.b * params.b) > 4)
			break ;
		iterations++;
	}
	return (iterations);
}
int    get_trgb(int iters)
{
    int    r = 1;
    int    g = 6;
    int    b = 0;
    return (0 << 24 | r * iters << 19 | g * iters << 8 | b * iters);
}
int	choose_color(int iteration, t_fractol *f)
{
	int	color;

	color = iteration * f->current_colour;
	return (color);
}

void	my_mlx_pixel_put(t_fractol *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->img.pixel_ptr + (y * fract->img.pix_len
			+ x * (fract->img.bit_par_px / 8));
	*(unsigned int *)dst = color;
}

