/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:26:32 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/20 15:25:17 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_gide(void)
{
	write(1, "you must enter the following:", 29);
	write(1, "\n", 1);
	write(1, "./fractol mandelbrot", 20);
	write(1, "\n", 1);
	write(1, "./fractol julia arg1 arg2", 25);
	write(1, "\n", 1);
}

void	drawing_fractol(t_fractol *fract)
{
	int	x;
	int	y;
	int	iterations;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fract->name == 2)
				iterations = calculate_julia(fract, x, y);
			else if (fract->name == 1)
				iterations = calculate_mandelbrot(fract, x, y);
			if (iterations < fract->iterations)
				color = get_trgb(iterations);
			else
				color = BLACK;
			my_mlx_pixel_put(fract, x++, y, color);
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_conex, fract->mlx_window,
		fract->img.img_ptr, 0, 0);
}

void	make_fractal(t_fractol *fract)
{
	fract->mlx_conex = mlx_init();
	if (!fract->mlx_conex)
		exit(1);
	make_window(fract);
	make_img(fract);
	make_data(fract);
	fract->current_colour = PURPLE;
}

int	main(int ac, char **av)
{
	t_fractol	fractal;

	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		handle_mandelbrot(&fractal);
	else if (ac == 4 && !ft_strcmp(av[1], "julia")
		&& is_valid_arg(av[2]) && is_valid_arg(av[3]))
		handle_julia(&fractal, av[2], av[3]);
	else
	{
		ft_gide();
		exit(1);
	}
	return (0);
}
