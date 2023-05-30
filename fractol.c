/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:08:18 by msaidi            #+#    #+#             */
/*   Updated: 2023/04/07 22:17:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	rescale(double x, double start, double end)
{
	return ((x / SIZE) * (end - start) + start);
}

void	zoom_in(int x, int y, t_vars *vars)
{
	double	tx;
	double	ty;

	tx = rescale(x, vars->start_x, vars->end_x);
	ty = rescale(y, vars->start_y, vars->end_y);
	vars->start_x += tx;
	vars->end_x += tx;
	vars->start_y += ty;
	vars->end_y += ty;
	vars->start_x *= vars->scale;
	vars->end_x *= vars->scale;
	vars->start_y *= vars->scale;
	vars->end_y *= vars->scale;
	vars->iter += 10;
	vars->key_scale *= vars->scale;
}

void	zoom_out(int x, int y, t_vars *vars)
{
	double	tx;
	double	ty;

	tx = rescale(x, vars->start_x, vars->end_x);
	ty = rescale(y, vars->start_y, vars->end_y);
	vars->start_x /= vars->scale;
	vars->end_x /= vars->scale;
	vars->start_y /= vars->scale;
	vars->end_y /= vars->scale;
	vars->start_x -= tx;
	vars->end_x -= tx;
	vars->start_y -= ty;
	vars->end_y -= ty;
	vars->iter -= 10;
	vars->key_scale /= vars->scale;
}

void	parsing(char **av, t_vars *vars)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
		vars->type_frac = 1;
	else if (!ft_strcmp(av[1], "julia"))
		vars->type_frac = 2;
	else if (!ft_strcmp(av[1], "tricorn"))
		vars->type_frac = 3;
	else
	{
		write(1, "Please enter mandelbrot, julia or tricorn\n", 43);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		parsing(av, &vars);
		variable_init(&vars);
		draw_img(&vars);
		mlx_mouse_hook(vars.mlx_window, mouse, &vars);
		mlx_hook(vars.mlx_window, 17, 0, ft_quit, &vars);
		mlx_hook(vars.mlx_window, 6, 0, mouse_moving, &vars);
		mlx_hook(vars.mlx_window, 2, 0, keyboard, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	else
		write(2, "Invalid Args, choose a set.\n", 29);
	return (0);
}
