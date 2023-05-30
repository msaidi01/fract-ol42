/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:57:52 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/23 14:36:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	variable_init(t_vars *vars)
{
	vars->end_x = 2;
	vars->start_x = -2;
	vars->end_y = 2;
	vars->start_y = -2;
	vars->julia_x = -0.835;
	vars->julia_y = -0.2321;
	vars->scale = 0.5;
	vars->key_scale = 0.5;
	vars->iter = 80;
	vars->color = 50;
	vars->lock = 1;
	vars->mlx_ptr = mlx_init();
	vars->mlx_window = mlx_new_window(vars->mlx_ptr, SIZE, SIZE, "fract-ol");
	vars->mlx_img = mlx_new_image(vars->mlx_ptr, SIZE, SIZE);
	vars->addr = mlx_get_data_addr(vars->mlx_img,
			&vars->bits_per_px, &vars->line_len, &vars->endian);
}

int	keyboard(int keycode, t_vars *vars)
{
	if (keycode == 49)
		vars->lock *= -1;
	if (keycode == 125 || keycode == 126)
		up_down(keycode, vars);
	else if (keycode == 123 || keycode == 124)
		left_right(keycode, vars);
	else if (keycode == 8)
	{
		vars->color += 10;
		draw_img(vars);
	}
	else if (keycode == 53)
		ft_quit(vars);
	return (0);
}

void	up_down(int keycode, t_vars *vars)
{
	if (keycode == 125)
	{
		vars->start_y += vars->key_scale;
		vars->end_y += vars->key_scale;
		draw_img(vars);
	}
	else if (keycode == 126)
	{
		vars->start_y -= vars->key_scale;
		vars->end_y -= vars->key_scale;
		draw_img(vars);
	}
}

void	left_right(int keycode, t_vars *vars)
{
	if (keycode == 124)
	{
		vars->start_x += vars->key_scale;
		vars->end_x += vars->key_scale;
		draw_img(vars);
	}
	else if (keycode == 123)
	{
		vars->px = 0;
		vars->start_x -= vars->key_scale;
		vars->end_x -= vars->key_scale;
		draw_img(vars);
	}
}
