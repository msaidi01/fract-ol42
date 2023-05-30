/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:14:28 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/24 19:42:36 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_len + x * (vars->bits_per_px / 8));
	*(unsigned int *) dst = color;
}

int	color_c(int i, t_vars *vars)
{
	int	r;
	int	g;
	int	b;

	if (i >= vars->iter)
		return (0);
	r = i * (1 - cos(vars->color));
	b = 4 * i * (1 + cos(vars->color)) + 100;
	g = 3 * i * (1 + sin(vars->color) + 1);
	return (r << 16 | g << 8 | b);
}

int	mouse_moving(int x, int y, t_vars *vars)
{
	if (x > 0 && x <= SIZE && y > 0 && y <= SIZE && vars->lock == 1)
	{
		vars->julia_x = rescale(x, vars->start_x, vars->end_y);
		vars->julia_y = rescale(y, vars->start_x, vars->end_y);
	}
	draw_img(vars);
	return (0);
}

int	mouse(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 5)
	{
		zoom_in(x, y, vars);
		draw_img(vars);
	}
	if (keycode == 4)
	{
		zoom_out(x, y, vars);
		draw_img(vars);
	}
	return (0);
}