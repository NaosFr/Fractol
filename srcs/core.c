/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:50:13 by ncella            #+#    #+#             */
/*   Updated: 2017/12/14 09:47:08 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_algo_fractal(int *img, t_mlx *smlx)
{
	double x;
	double y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (smlx->type_fractol == 1)
				ft_algo_mandelbrot(img, smlx, x, y);
			else if (smlx->type_fractol == 2)
				ft_algo_julia(img, smlx, x, y);
			else if (smlx->type_fractol == 3)
				ft_algo_shadow(img, smlx, x, y);
			else if (smlx->type_fractol == 4)
				ft_algo_illuma(img, smlx, x, y);
			y++;
		}
		x++;
	}
}

char			ft_fractal(t_mlx *smlx)
{
	int		*my_image_int;

	my_image_int = (int*)smlx->my_image_string;
	ft_algo_fractal(my_image_int, smlx);
	smlx->my_image_string = (char*)my_image_int;
	return (*smlx->my_image_string);
}
