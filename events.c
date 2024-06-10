/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:49:56 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/22 14:27:02 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	handle_key_press(int keycode, t_fractol *fract)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fract->mlx_conex, fract->mlx_window);
		exit(0);
	}
	else if (keycode == 126)
		fract->y_offset -= 50;
	else if (keycode == 125)
		fract->y_offset += 50;
	else if (keycode == 123)
		fract->x_offset -= 50;
	else if (keycode == 124)
		fract->x_offset += 50;
	drawing_fractol(fract);
	return (0);
}

static	int	handle_close(t_fractol *fractal)
{
	mlx_destroy_window(fractal->mlx_conex, fractal->mlx_window);
	exit (0);
	return (0);
}

static	int	handle_mouse_click(int button, int x, int y, t_fractol *fractal)
{
	(void) x;
	(void) y;
	if (button == 4)
	{
		fractal->zoom *= 1.1;
	}
	else if (button == 5)
	{
		fractal->zoom /= 1.1;
	}
	drawing_fractol(fractal);
	return (0);
}

void	handle_events(t_fractol *fractal)
{
	mlx_hook (fractal->mlx_window, 17, 0, &handle_close, fractal);
	mlx_hook (fractal->mlx_window, 2, 0, &handle_key_press, fractal);
	mlx_hook (fractal->mlx_window, 4, 0, &handle_mouse_click, fractal);
}
