/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:58:16 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/18 21:48:51 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\n'))
		++s;
	if (*s == '+' || *s == '-')
		sign = 1 - 2 * (*s++ == '-');
	while (*s != '.' && *s)
		integral = (integral * 10) + (*s++ - '0');
	if (integral > INT_MAX)
		exit(1);
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}
