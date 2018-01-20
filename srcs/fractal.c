/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:52:09 by ncella            #+#    #+#             */
/*   Updated: 2017/12/14 09:47:06 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_pixel(int *img, int x, int y, int color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		img[y * WIDTH + x] = color;
}

void			ft_algo_mandelbrot(int *img, t_mlx *smlx, int x, int y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;

	c_r = x / smlx->zoom + smlx->x1;
	c_i = y / smlx->zoom + smlx->y1;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < smlx->iteration_max)
	{
		smlx->tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * smlx->tmp + c_i;
		i = i + 1;
	}
	if (i == smlx->iteration_max)
		put_pixel(img, x, y, BLACK);
	else
		put_pixel(img, x, y, ft_color(i, smlx));
}

void			ft_algo_julia(int *img, t_mlx *smlx, int x, int y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;

	c_r = smlx->c_r;
	c_i = smlx->c_i;
	z_r = x / smlx->zoom + smlx->x1;
	z_i = y / smlx->zoom + smlx->y1;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < smlx->iteration_max)
	{
		smlx->tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * smlx->tmp + c_i;
		i = i + 1;
	}
	if (i == smlx->iteration_max)
		put_pixel(img, x, y, BLACK);
	else
		put_pixel(img, x, y, ft_color(i, smlx));
}

void			ft_algo_shadow(int *img, t_mlx *smlx, int x, int y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;

	c_r = x / smlx->zoom + smlx->x1;
	c_i = y / smlx->zoom + smlx->y1;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < smlx->iteration_max)
	{
		smlx->tmp = z_r;
		z_r = ABS(z_r) * ABS(z_r) - ABS(z_i) * ABS(z_i) + ABS(c_r);
		z_i = 1 * ABS(z_i) * smlx->tmp + ABS(c_i);
		i = i + 1;
	}
	if (i == smlx->iteration_max)
		put_pixel(img, x, y, BLACK);
	else
		put_pixel(img, x, y, ft_color(i, smlx));
}

void			ft_algo_illuma(int *img, t_mlx *smlx, int x, int y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;

	c_r = x / smlx->zoom + smlx->x1;
	c_i = y / smlx->zoom + smlx->y1;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r - z_i * z_i < 4 && i < smlx->iteration_max)
	{
		smlx->tmp = z_r;
		z_r = z_r * z_r - z_i * z_i - c_r;
		z_i = -2 * z_i * smlx->tmp - c_i;
		i = i + 1;
	}
	if (i == smlx->iteration_max)
		put_pixel(img, x, y, BLACK);
	else
		put_pixel(img, x, y, ft_color(i, smlx));
}
