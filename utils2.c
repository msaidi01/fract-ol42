/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:26:54 by msaidi            #+#    #+#             */
/*   Updated: 2023/04/07 22:25:40 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	frac_pick(int a, int b, double clr_var, t_vars *vars)
{
	if (vars->type_frac == 1)
		clr_var = mandelbrot((t_point){rescale(a, vars->start_x, vars->end_x),
				rescale(b, vars->start_y, vars->end_y)}, vars);
	else if (vars->type_frac == 2)
		clr_var = julia((t_point){rescale(a, vars->start_x, vars->end_x),
				rescale(b, vars->start_y, vars->end_y)}, vars);
	else if (vars->type_frac == 3)
		clr_var = tricorn((t_point){rescale(a, vars->start_x, vars->end_x),
				rescale(b, vars->start_y, vars->end_y)}, vars);
	return (clr_var);
}

void	draw_img(t_vars *vars)
{
	int		a;
	int		b;
	double	clr_var;

	a = 0;
	clr_var = 0;
	while (a < SIZE)
	{
		b = 0;
		while (b < SIZE)
		{
			clr_var = frac_pick(a, b, clr_var, vars);
			my_mlx_pixel_put(vars, a, b, color_c(clr_var, vars));
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window,
		vars->mlx_img, 0, 0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	int				i;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (ps1[i] == ps2[i] && ps1[i] && ps2[i])
		i++;
	return (ps1[i] - ps2[i]);
}

int	ft_quit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->mlx_img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
	exit(0);
	return (0);
}
