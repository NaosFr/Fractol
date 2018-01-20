/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:51:23 by ncella            #+#    #+#             */
/*   Updated: 2017/12/14 09:35:11 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_mouse_move(int x, int y, t_mlx *smlx)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <=
		HEIGHT && smlx->type_fractol == 2)
	{
		smlx->c_r = ((double)x / (double)WIDTH) / 1 - 1.0;
		smlx->c_i = ((double)y / (double)HEIGHT) / 1 - 1.0;
		mlx_destroy_image(smlx->mlx, smlx->pointeur_image);
		smlx->pointeur_image = mlx_new_image(smlx->mlx, WIDTH, HEIGHT);
		ft_fractal(smlx);
		mlx_put_image_to_window(smlx->my_image_string, smlx->win,
			smlx->pointeur_image, 0, 0);
		ft_info(smlx);
	}
	return (0);
}

void			ft_mouse_click_left(int x, int y, t_mlx *smlx)
{
	double scale;
	double reduc;

	scale = 1.3;
	reduc = 2;
	smlx->vx = x;
	smlx->vy = y;
	smlx->x1 = (x / smlx->zoom + smlx->x1) - ((smlx->zoom * scale) / reduc);
	smlx->x1 += ((smlx->zoom * scale) / reduc) - (x / (smlx->zoom * scale));
	smlx->y1 = (y / smlx->zoom + smlx->y1) - ((smlx->zoom * scale) / reduc);
	smlx->y1 += ((smlx->zoom * scale) / reduc) - (y / (smlx->zoom * scale));
	smlx->zoom *= scale;
	smlx->iteration_max++;
}

void			ft_mouse_click_rigth(t_mlx *smlx)
{
	double scale;
	double reduc;

	scale = 1.3;
	reduc = 2;
	smlx->x1 = (smlx->vx / smlx->zoom + smlx->x1) -
		((smlx->zoom / scale) / reduc);
	smlx->x1 += ((smlx->zoom / scale) / reduc) -
		(smlx->vx / (smlx->zoom / scale));
	smlx->y1 = (smlx->vy / smlx->zoom + smlx->y1) -
		((smlx->zoom / scale) / reduc);
	smlx->y1 += ((smlx->zoom / scale) / reduc) -
		(smlx->vy / (smlx->zoom / scale));
	smlx->zoom /= scale;
	smlx->iteration_max--;
}

int				ft_mouse_click(int keycode, int x, int y, t_mlx *smlx)
{
	if (keycode == 5 || keycode == 1)
		ft_mouse_click_left(x, y, smlx);
	else if (keycode == 4 || keycode == 2)
		ft_mouse_click_rigth(smlx);
	mlx_destroy_image(smlx->mlx, smlx->pointeur_image);
	smlx->pointeur_image = mlx_new_image(smlx->mlx, WIDTH, HEIGHT);
	ft_fractal(smlx);
	mlx_put_image_to_window(smlx->my_image_string, smlx->win,
			smlx->pointeur_image, 0, 0);
	ft_info(smlx);
	return (0);
}
