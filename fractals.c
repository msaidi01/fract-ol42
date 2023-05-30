/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:39:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/04/07 07:09:00 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_point c, t_vars *vars)
{
	t_point	p;
	double	xtmp;
	int		i;

	p.x = c.x;
	p.y = c.y;
	i = 0;
	while (c.x * c.x + c.y * c.y <= 4 && i < vars->iter)
	{
		xtmp = c.x * c.x - c.y * c.y + p.x;
		c.y = 2 * c.x * c.y + p.y;
		c.x = xtmp;
		i++;
	}
	return (i);
}

double	julia(t_point c, t_vars *vars)
{
	t_point	z;
	double	tmp;
	int		i;

	z.x = c.x;
	z.y = c.y;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < vars->iter)
	{
		tmp = z.x * z.x - z.y * z.y;
		z.y = 2 * z.x * z.y + vars->julia_y;
		z.x = tmp + vars->julia_x;
		i++;
	}
	return (i);
}

double	tricorn(t_point z, t_vars *vars)
{
	t_point	c;
	double	tmp;
	int		i;

	c.x = z.x;
	c.y = z.y;
	i = 0;
	while (c.x * c.x + c.y * c.y < 4 && i < vars->iter)
	{
		tmp = c.x * c.x - c.y * c.y + z.x;
		c.y = -2 * c.x * c.y + z.y;
		c.x = tmp;
		i++;
	}
	return (i);
}
