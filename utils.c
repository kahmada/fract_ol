/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:26:59 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/20 15:03:38 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_window(t_fractol *fract)
{
	fract->mlx_window = mlx_new_window(fract->mlx_conex,
			WIDTH, HEIGHT, "fractol");
	if (!fract->mlx_window)
		exit(1);
}

void	make_img(t_fractol *fract)
{
	fract->img.img_ptr = mlx_new_image(fract->mlx_conex, WIDTH, HEIGHT);
	if (!fract->img.img_ptr)
		exit(1);
	fract->img.pixel_ptr = mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bit_par_px, &fract->img.pix_len, &fract->img.bit_order);
	if (!fract->img.pixel_ptr)
		exit(1);
}

void	make_data(t_fractol *fract)
{
	fract->iterations = 250;
}

int	is_valid_arg(char *str)
{
	int	nbr;

	nbr = 0;
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (ft_isdigit(*str))
	{
		str++;
	}
	if (*str == '.')
	{
		str++;
		nbr++;
	}
	while (ft_isdigit(*str))
	{
		str++;
	}
	if (*str == '\0' && nbr <= 1)
		return (1);
	return (0);
}
