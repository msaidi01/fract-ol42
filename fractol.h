/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:07:07 by msaidi            #+#    #+#             */
/*   Updated: 2023/04/10 00:06:09 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h> 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define SIZE 500

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*mlx_img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
	int		iter;
	int		color;
	double	start_x;
	double	end_x;
	double	start_y;
	double	end_y;
	double	julia_x;
	double	julia_y;
	double	scale;
	double	key_scale;
	int		type_frac;
	int		px;
	int		py;
	int		lock;
	double	clr_var;
}	t_vars;
void	variable_init(t_vars *vars);
void	draw_img(t_vars *vars);
double	mandelbrot(t_point c, t_vars *vars);
int		keyboard(int keycode, t_vars *vars);
int		ft_quit(t_vars *vars);
int		mouse(int keycode, int x, int y, t_vars *vars);
void	zoom_out(int x, int y, t_vars *vars);
void	zoom_in(int x, int y, t_vars *vars);
double	rescale(double x, double start, double end);
int		color_c(int i, t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	up_down(int keycode, t_vars *vars);
void	left_right(int keycode, t_vars *vars);
int		ft_strcmp(const char *s1, const char *s2);
double	julia(t_point c, t_vars *vars);
int		mouse_moving(int x, int y, t_vars *vars);
double	tricorn(t_point z, t_vars *vars);
void	parsing(char **av, t_vars *vars);
#endif
