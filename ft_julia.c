/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:35:45 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/20 08:47:53 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_julia(t_fractol *fractal, char *param1, char *param2)
{
	fractal->name = 2;
	fractal->zoom = 1.0;
	fractal->julia_r = atof(param1);
	fractal->julia_i = atof(param2);
	make_fractal(fractal);
	drawing_fractol(fractal);
	handle_events(fractal);
	mlx_loop(fractal->mlx_conex);
}

int	calculate_julia(t_fractol *fract, int x, int y)
{
	t_julia_vars	vars;
	int				iterations;
	double			temp;

	vars.zx = 4.0 * ((double)(x + fract->x_offset)
			- WIDTH / 2) / WIDTH / fract->zoom;
	vars.zy = 4.0 * ((double)(y + fract->y_offset)
			- HEIGHT / 2) / HEIGHT / fract->zoom;
	vars.c_r = fract->julia_r;
	vars.c_i = fract->julia_i;
	iterations = 0;
	while (iterations < fract->iterations)
	{
		temp = vars.zx * vars.zx - vars.zy * vars.zy + vars.c_r;
		vars.zy = 2 * vars.zx * vars.zy + vars.c_i;
		vars.zx = temp;
		if ((vars.zx * vars.zx + vars.zy * vars.zy) > 4)
			break ;
		iterations++;
	}
	return (iterations);
}
