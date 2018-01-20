/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:10:55 by ncella            #+#    #+#             */
/*   Updated: 2017/12/13 12:09:37 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_key_move(int keycode, t_mlx *smlx)
{
	if (keycode == 13)
		smlx->y1 -= 1 / (smlx->zoom / 10);
	else if (keycode == 1)
		smlx->y1 += 1 / (smlx->zoom / 10);
	else if (keycode == 0)
		smlx->x1 -= 1 / (smlx->zoom / 10);
	else if (keycode == 2)
		smlx->x1 += 1 / (smlx->zoom / 10);
}

static void		ft_key_color(int keycode, t_mlx *smlx)
{
	if (keycode == 18)
		smlx->type_color = 1;
	else if (keycode == 19)
		smlx->type_color = 2;
	else if (keycode == 20)
		smlx->type_color = 3;
	else if (keycode == 21)
		smlx->type_color = 4;
	else if (keycode == 23)
		smlx->type_color = 5;
	else if (keycode == 49)
	{
		smlx->type_fractol++;
		if (smlx->type_fractol == 5)
			smlx->type_fractol = 1;
		ft_init(smlx);
	}
}

int				ft_key(int keycode, t_mlx *smlx)
{
	if (keycode == 53)
	{
		smlx->type_fractol = 0;
		mlx_clear_window(smlx->mlx, smlx->win);
		free(smlx);
		exit(0);
	}
	ft_key_move(keycode, smlx);
	ft_key_color(keycode, smlx);
	mlx_destroy_image(smlx->mlx, smlx->pointeur_image);
	smlx->pointeur_image = mlx_new_image(smlx->mlx, WIDTH, HEIGHT);
	ft_fractal(smlx);
	mlx_put_image_to_window(smlx->my_image_string, smlx->win,
			smlx->pointeur_image, 0, 0);
	ft_info(smlx);
	return (0);
}
